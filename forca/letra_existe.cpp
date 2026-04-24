#include <string>
using namespace std;

string palavra_secreta;

bool letra_existe(char chute) {
    for (char letra : palavra_secreta) {
        if (letra == chute) {
            return true;
        }
    }
    
    return false;
}