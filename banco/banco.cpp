#include <iostream>
using namespace std;

struct Conta
{
    string numero;
    string cpfTitular;
    string nomeTitular;
    float saldo;
};


int main() 
{
    Conta umaConta;
    umaConta.numero;
    umaConta.cpfTitular;
    umaConta.nomeTitular;
    umaConta.saldo = 100;

    Conta outraConta;
    outraConta.saldo = 200;

    cout << "Uma Conta: " << umaConta.saldo << " Outra conta: " << outraConta.saldo << endl;

    return 0;
}