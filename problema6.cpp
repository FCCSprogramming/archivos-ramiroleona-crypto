#include <iostream>
#include <fstream>

using namespace std;

void ContarPalabras(ifstream &archivo, int &contador);

int main(){

    ifstream archivo("contarpalabras.txt");
    int contador = 0;

    if (!archivo.is_open()){
        cerr << "Ha ocurrido un error" << endl;
        return 1;
    }

    else {
        ContarPalabras(archivo, contador);
    }

    archivo.close();

    cout << "Se han encontrado un total de " << contador << " palabras." << endl;

    return 0;
}

void ContarPalabras(ifstream &archivo, int &contador){
    
    string palabra;

    while (archivo >> palabra){
        contador++;
    }
}