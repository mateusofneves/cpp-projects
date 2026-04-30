#include <iostream>
#include <fstream>
#include "salva_arquivo.hpp"
using namespace std;

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