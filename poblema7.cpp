#include <iostream>
#include <fstream>

using namespace std;

int main(){

    ifstream archivo("buscarpalabra.txt");
    string palabra, palabra_buscar;

    if (!archivo.is_open()){

        cerr << "Ha ocurrido un error " << endl;
        return 1;

    }

    else {

        cout << "Mencione una palabra que desea buscar en el archivo de texto: " << endl;
        cin >> palabra_buscar;  

    }

    int contador = 0;

    while (archivo >> palabra){
        if (palabra == palabra_buscar){
            contador ++;
        }
    }

    cout << "La palabra " << palabra_buscar << " se ha encontrado un total de " << contador << " veces en el archivo." << endl;
    archivo.close();
    
    return 0;
}