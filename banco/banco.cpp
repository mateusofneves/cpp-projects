#include <iostream>
using namespace std;

struct Conta
{
    string numero;
    string cpfTitular;
    string nomeTitular;
    float saldo;
};

void sacar(Conta& conta, float valorASacar)
{
    if (valorASacar < 0) {
        cout << "Nao pode sacar valor negativo." << endl;
        return;
    } else if (valorASacar > conta.saldo) {
        cout << "Saldo insuficiente." << endl;
        return;
    }
    
    conta.saldo -= valorASacar;
}

void depositar (Conta& conta, float valorADepositar)
{
    if (valorADepositar < 0) {
        cout << "Nao pode depositar valor negativo." << endl;
        return;
    }

    conta.saldo += valorADepositar;
}

int main() 
{
    Conta umaConta;
    umaConta.numero;
    umaConta.cpfTitular;
    umaConta.nomeTitular;
    umaConta.saldo = 100;

    Conta outraConta;
    outraConta.saldo = 200;

    depositar(outraConta, 500);

    cout << "Uma Conta: " << umaConta.saldo << " Outra conta: " << outraConta.saldo << endl;

    return 0;
}