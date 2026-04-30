#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "letra_existe.hpp"
using namespace std;

extern map<char, bool> chutou;
extern vector<char> chutes_errados;

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