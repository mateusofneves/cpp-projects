#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

#include "le_arquivo.hpp"
#include "salva_arquivo.hpp"

void adicionapalavra() {
    cout << "Digite a nova palavra para o jogo: ";
    string nova_palavra;
    cin >> nova_palavra;

    vector<string> palavras = le_arquivo();
    palavras.push_back(nova_palavra);

    salva_arquivo(palavras);

}