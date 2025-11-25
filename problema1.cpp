#include <iostream>
#include <fstream>
using namespace std;

int main (){

    ifstream archivo("primertexto.txt");

    if (!archivo.is_open()){
        cerr << "No se pudo abrir el archivo." << endl;
    }
    else {
        string Linea;
        while (getline(archivo, Linea)){
            cout << Linea << endl;
        }
    }
    
    archivo.close();

    return 0;

}