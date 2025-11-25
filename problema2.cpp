#include <iostream>
#include <fstream>
using namespace std;

int main (){

    ofstream archivo("archivito2.txt");

    if(!archivo.is_open()){
        cout << "No se ha podido abrir el archivo" << endl;
    }

    else {
        archivo << "Este es el segundo archivo\n";
        archivo << "Estamos agregando texto\n";

        archivo.close();
    }

    ofstream archivo2("archivito2.txt", ios::app);

    archivo2 << "agregando texto al final\n";

    archivo2.close();

    return 0;
}