#include <string>
#include <map>
using namespace std;

string palavra_secreta;
map<char, bool> chutou;

bool nao_acertou() {
    for (char letra : palavra_secreta) {
        if (!chutou[letra]) {
            return true;
        }
    }
    return false;
}