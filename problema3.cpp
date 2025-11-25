#include <iostream>
#include <fstream>

using namespace std;

void escribirFibonacciBinario();
void leerFibonacciBinario();

int main(){
    escribirFibonacciBinario();
    leerFibonacciBinario();
    return 0;
}

void escribirFibonacciBinario(){
    ofstream fibonacci("fibonacci.bin", ios::binary);
    if (!fibonacci.is_open()){
        cout << "Ha ocurrido un error ";
        return;
    }

    int inicio = 0;
    int siguiente = 1;

    for (int i = 0; i < 20; i++){
        fibonacci.write(reinterpret_cast<char*>(&inicio), sizeof(int));
        int actual = inicio + siguiente;
        inicio = siguiente;
        siguiente = actual;
    }

    fibonacci.close();
    
}

void leerFibonacciBinario(){
    cout << "Lectura de Fibonacci:" << endl;
    ifstream fibonacci("fibonacci.bin", ios::binary);

    if (!fibonacci.is_open()){
        cout << "Ha ocurrido un error";
        return;
    }

    int contador = 1;
    int termino;

    while (fibonacci.read(reinterpret_cast<char*>(&termino), sizeof(int))){
        cout << "Termino " << contador << ": " << termino << endl;
        contador ++;
    }

    fibonacci.close();

}