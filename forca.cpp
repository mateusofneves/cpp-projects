#include <iostream>
#include <string>
using namespace std;

const string PALAVRA_SECRETA = "MATEMATICA";

bool letra_existe(char chute) {
    for (int i = 0; i < PALAVRA_SECRETA.size(); i++) {
        if (PALAVRA_SECRETA[i] == chute) {
            return true;
        }
    }
    
    return false;
}

int main() {
    cout << "***********************************" << endl;
    cout << "*** Bem-vindo ao jogo da forca! ***" << endl;
    cout << "***********************************" << endl;

    bool nao_acertou = true;
    bool nao_enforcou = true;

    while (nao_acertou && nao_enforcou) {
        char chute;
        cout << "Digite uma letra: ";
        cin >> chute;

        if (letra_existe(chute)) {
            cout << "Voce acertou uma letra!" << endl;
        } else {
            cout << "Voce errou!" << endl;
        }
    }
    

    return 0;
}