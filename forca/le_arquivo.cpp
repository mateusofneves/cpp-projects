#include <iostream>
#include <fstream>
#include "le_arquivo.hpp"
using namespace std;

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