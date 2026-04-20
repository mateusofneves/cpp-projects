#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
using namespace std;

int main() {
    srand(time(0)); // Inicializa a semente do gerador de números aleatórios

    const int NUMERO_SECRETO = rand() % 100 + 1; // Gera um numero aleatorio entre 1 e 100
    int numero_de_tentativas = 0;
    int tentativas = 0;

    double pontos = 1000.0;

    cout << "*****************************************" << endl;
    cout << "*** Bem-vindo ao jogo de adivinhacao! ***" << endl;
    cout << "*****************************************" << endl;

    cout << "Escolha o nivel de dificuldade:" << endl;
    cout << "Facil (F), Medio (M), Dificil (D)" << endl;
    cout << "Digite a letra correspondente ao nivel: ";
    
    char dificuldade;
    cin >> dificuldade;

    if (dificuldade == 'F' || dificuldade == 'f') {
        numero_de_tentativas = 20;
    } else if (dificuldade == 'M' || dificuldade == 'm') {
        numero_de_tentativas = 10;
    } else if (dificuldade == 'D' || dificuldade == 'd') {
        numero_de_tentativas = 5;
    } else {
        cout << "Dificuldade invalida. O jogo sera iniciado no nivel Medio." << endl;
        numero_de_tentativas = 10;
    }

    bool nao_acertou = true;

    for (int i = 1; i <= numero_de_tentativas; i++) {

        int chute;
        cout << "Tentativa " << i << endl;
        cout << "Digite o seu chute: ";
        cin >> chute;

        double pontos_perdidos = abs(chute - NUMERO_SECRETO) / 2.0;
        pontos -= pontos_perdidos;
        
        cout << "Voce chutou: " << chute << endl;

        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;

        if (acertou) {
            cout << "Parabens! Voce acertou!" << endl;
            nao_acertou = false;
            tentativas = i;
            break;
        }  else if (maior) {
            cout << "O numero secreto e menor do que " << chute << "." << endl;
        } else {
            cout << "O numero secreto e maior do que " << chute << "." << endl;
        }

    }

    cout << "Fim de jogo!" << endl;

    if (nao_acertou) {
        cout << "Voce perdeu! O numero secreto era " << NUMERO_SECRETO << "." << endl;
        cout << "Tente novamente para melhorar sua pontuacao!" << endl;
    } else {
        cout << "Voce acertou o numero secreto em " << tentativas << " tentativas." << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Sua pontuacao final e: " << pontos << " pontos." << endl;
    }

    return 0;

}