#include <iostream>
#include <fstream>

using namespace std;

int main(){

    ifstream lectura("archivo_a_copiar.txt");
    ofstream copia("archivo_copia.txt");

    if (!lectura.is_open() or !copia.is_open()){
        cout << "Ha ocurrido un error" << endl;
        return 0;
    }

    else {
        string linea;

        while (getline(lectura, linea)){
            copia << linea << endl;
        }

        cout << "Archivo copiado exitosamente" << endl;
    }

    lectura.close();
    copia.close();

    return 0;
}