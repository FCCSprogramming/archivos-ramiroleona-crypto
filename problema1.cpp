#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int DIAS_ANO = 12*30;

struct FECHA{
    int dia, mes;
};

struct CARGA{
    int numpasajeros;
    FECHA* fecha;
};

void CrearEstructuraDinamica(CARGA*Listado, int cantidad){
    for (int i = 0; i < cantidad; i++){
        Listado[i].numpasajeros = 500 + rand ()%(700-500+1);
        Listado[i].fecha->dia = 1 + i%30;
        Listado[i].fecha->mes = 1+ i/30;
    }
}

void LiberarEspacio(CARGA *Listado, int cantidad){
    delete [] Listado;
    for (int i = 0; i < cantidad; i++){
        delete Listado[i].fecha;
        Listado[i].fecha = nullptr;
    }

    Listado = nullptr;
}

int main(){

    srand(time(NULL));    
    
    CARGA *Listado = new CARGA[DIAS_ANO];

    for (int i = 0; i < DIAS_ANO; i++){
        Listado[i].fecha = new FECHA;
    }

    CrearEstructuraDinamica(Listado, DIAS_ANO);

    int carga_minima = 0;

    for (int i = 0; i < DIAS_ANO; i++){
        if (Listado[i].numpasajeros>=0.95*700.0){
            carga_minima++;
        }
    }

    cout << "Se encontraron " << carga_minima << " dias con carga minima de 665 pasajeros" << endl;

    for (int i = 0; i < DIAS_ANO; i++){
        if (Listado[i].numpasajeros>=0.95*700.0){
            cout << Listado[i].fecha->dia << "/" << Listado[i].fecha->mes << ": " << Listado[i].numpasajeros << " pasajeros" << endl;
        }       
    }

    LiberarEspacio(Listado, DIAS_ANO);

    return 0;
}