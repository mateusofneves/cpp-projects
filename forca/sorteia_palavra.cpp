#include <vector>
#include <string>
#include <time.h>
#include <map>
#include "le_arquivo.hpp"
using namespace std;

#include "le_arquivo.hpp"

extern string palavra_secreta;
extern map<char, bool> chutou;
extern vector<char> chutes_errados;

void sorteia_palavra() {
    vector<string> palavras = le_arquivo();

    srand(time(0));
    int indice_sorteado = rand() % palavras.size();

    palavra_secreta = palavras[indice_sorteado];
}