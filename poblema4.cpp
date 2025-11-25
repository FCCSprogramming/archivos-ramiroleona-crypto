#include<iostream>
#include<fstream>
using namespace std;

int main (){

    ifstream archivo("archivoproblema4.txt");
    int contador = 0;
    
    if (!archivo.is_open()){
        cerr << " Ha ocurrido un error" << endl;
        return 1;
    }

    else {

        

        string linea;

        while (getline(archivo, linea)){
            contador++;
        }
    }

    cout << "Se han contado un total de " << contador << " lineas." << endl;


    return 0;

}