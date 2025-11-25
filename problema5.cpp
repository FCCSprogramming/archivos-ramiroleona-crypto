#include <iostream>
#include <fstream>

using namespace std;

int main(){

    ifstream archivo1("archivoproblema51.txt");
    ofstream archivo3("archivo_concatenado.txt");

    if (!archivo1.is_open() or !archivo3.is_open()){
        cerr << "Ha ocurrido un error" << endl;
        return 1;
    }

    else {
        string linea1;

        while (getline(archivo1, linea1)){
            archivo3 << linea1 << endl;
        }

        archivo1.close();
        archivo3.close();
    }

    ifstream archivo2("archivoproblema52.txt");
    ofstream archivo4("archivo_concatenado.txt", ios::app);

    if (!archivo2.is_open() or !archivo4.is_open()){
        cerr << "Ha ocurrido un error" << endl;
        return 1;
    }

    else {
        string linea2;

        while (getline(archivo2, linea2)){
            archivo4 << linea2 << endl;
        }

        archivo2.close();
        archivo4.close();
    }

    cout << "Archivo creado exitosamente " << endl;

    return 0;
}