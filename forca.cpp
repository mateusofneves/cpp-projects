#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <vector>
#include <map>
using namespace std;

string palavra_secreta;
map<char, bool> chutou;
vector<char> chutes_errados;

bool letra_existe(char chute) {
    for (char letra : palavra_secreta) {
        if (letra == chute) {
            return true;
        }
    }
    
    return false;
}

bool nao_acertou() {
    for (char letra : palavra_secreta) {
        if (!chutou[letra]) {
            return true;
        }
    }
    return false;
}

bool nao_enforcou() {
    return chutes_errados.size() < 5;
}

void cabecalho() {
    cout << "***********************************" << endl;
    cout << "*** Bem-vindo ao jogo da forca! ***" << endl;
    cout << "***********************************" << endl;
    cout << endl;
}

void imprime_erros() {
    cout << "Chutes errados: ";
    for (char letra : chutes_errados) {
        cout << letra << " ";
    }
    cout << endl;
}

void imprime_palavra() {
    for (char letra : palavra_secreta) {
        if (chutou[letra]) {
            cout << letra << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

void chuta() {
    cout << "Digite uma letra: ";
    char chute;
    cin >> chute;
    chute = toupper(chute);

    chutou[chute] = true;

    if (letra_existe(chute)) {
        cout << "Voce acertou uma letra!" << endl;
    } else {
        cout << "Voce errou!" << endl;
        chutes_errados.push_back(chute);    
    }

        cout << endl;
}

vector<string> le_arquivo() {
    vector<string> palavras_do_arquivo;

    ifstream arquivo;
    arquivo.open("palavras.txt");

    if (arquivo.is_open()) {
        int quantidade_de_palavras;
        arquivo >> quantidade_de_palavras;

        for (int i = 0; i < quantidade_de_palavras; i++) {
            string palavras;
            arquivo >> palavras;
            palavras_do_arquivo.push_back(palavras);
        }

    arquivo.close();
    return palavras_do_arquivo;

    } else {
        cout << "Nao foi possivel abrir o arquivo!" << endl;
        exit(0);
    }
}

void sorteia_palavra() {
    vector<string> palavras = le_arquivo();

    srand(time(0));
    int indice_sorteado = rand() % palavras.size();

    palavra_secreta = palavras[indice_sorteado];
}

void salva_arquivo(vector<string> palavras) {
    ofstream arquivo;
    arquivo.open("palavras.txt");

    if (arquivo.is_open()) {
        arquivo << palavras.size() << endl;

        for (string palavra : palavras) {
            arquivo << palavra << endl;
        }

        arquivo.close();
    } else {
        cout << "Nao foi possivel abrir o arquivo!" << endl;
        exit(0);
    }
}

void adicionapalavra() {
    cout << "Digite a nova palavra para o jogo: ";
    string nova_palavra;
    cin >> nova_palavra;

    vector<string> palavras = le_arquivo();
    palavras.push_back(nova_palavra);

    salva_arquivo(palavras);

}

int main() {
    cabecalho();

    sorteia_palavra();

    while (nao_acertou() && nao_enforcou()) {

        imprime_erros();

        cout << endl;

        imprime_palavra();

        chuta();
    }
    
    cout << "Fim de jogo!" << endl;
    cout << "A palavra secreta era: " << palavra_secreta << endl;

    if (nao_acertou()){
        cout << "Voce perdeu! Tente novamente! " << endl;
    } else {
        cout << "Parabens! Voce ganhou!" << endl;
        cout <<"Voce deseja adicionar uma nova palavra ao jogo? (S/N) ";
        char resposta;
        cin >> resposta;

        if (resposta == 'S'){
            adicionapalavra();
        } else {
            cout << "Obrigado por jogar!" << endl;
        }   
    }
    
    return 0;
}