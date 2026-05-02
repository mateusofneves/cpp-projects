#include <iostream>
using namespace std;

struct Conta
{
    string numero;
    string cpfTitular;
    string nomeTitular;
    float saldo;

    void sacar(float valorASacar)
    {
        if (valorASacar < 0) {
            cout << "Nao pode sacar valor negativo." << endl;
            return;
        } else if (valorASacar > saldo) {
            cout << "Saldo insuficiente." << endl;
            return;
        }
        
        saldo -= valorASacar;
    }

    void depositar (float valorADepositar)
    {
        if (valorADepositar < 0) {
            cout << "Nao pode depositar valor negativo." << endl;
            return;
        }

        saldo += valorADepositar;
    }

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

    outraConta.depositar(500);
    outraConta.sacar(200);

    umaConta.saldo = 1000;

    cout << "Uma Conta: " << umaConta.saldo << " Outra conta: " << outraConta.saldo << endl;

    return 0;
}