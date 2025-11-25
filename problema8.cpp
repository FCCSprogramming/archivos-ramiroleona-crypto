#include <iostream>
#include <fstream>

using namespace std;

int main(){

    ifstream archivo("palabras_a_reemplazar.txt");
    ofstream archivo_temp("archivo_temp.txt");

    if (!archivo.is_open() or !archivo_temp.is_open()){
        cerr << "Ha ocurrido un error" << endl;
        return 1;
    }

    else {
        string palabra, palabra_a_reemplazar = "martes", palabra_nueva = "lunes";

        while (archivo >> palabra){
            if (palabra == palabra_a_reemplazar){
                archivo_temp << palabra_nueva;
            }

            else {
                archivo_temp << palabra;
            }

            archivo_temp << " ";
        }

        archivo.close();

        remove("palabras_a_reemplazar.txt");
        rename("archivo_temp.txt", "palabras_a_reemplazar.txt");

        cout << "El proceso de reemplazo ha finalizado correctamente." << endl;
        archivo_temp.close();

    }

    return 0;
}