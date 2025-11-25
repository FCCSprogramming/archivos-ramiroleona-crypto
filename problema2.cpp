#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

struct vertice{
    int numero;
    double x;
    double y;
};

struct triangulo{
    vertice vertice1;
    vertice vertice2;
    vertice vertice3;
    double area;
};

double area_triangulo(vertice vertice1, vertice vertice2, vertice vertice3){
    double area = 0.5*fabs(vertice1.x*(vertice3.y-vertice2.y)+vertice2.x*(vertice1.y-vertice3.y)+vertice3.x*(vertice2.y-vertice1.y));
    return area;
}

int main(){

    ifstream laguna("laguna.txt");

    if (!laguna.is_open()){
        cerr << "Ha ocurrido un error " << endl;
        return 1;
    }

    int num_triangulos;
    int num_vertices;

    laguna >> num_triangulos;
    laguna >> num_vertices;
    
    vertice *vertices = new vertice[num_vertices];
    triangulo *triangulos = new triangulo[num_triangulos];
    double coordenada;
    int triangulo;
    
    for (int i = 0; i < num_vertices; i++){
        vertices[i].numero = i +1;
        laguna >> coordenada;
        vertices[i].x = coordenada;
        laguna >> coordenada;
        vertices[i].y = coordenada;
    }
    
    double area_total = 0;

    for (int i = 0; i < num_triangulos; i++){
        laguna >> triangulo;
        triangulos[i].vertice1 = vertices[triangulo-1];
        laguna >> triangulo;
        triangulos[i].vertice2 = vertices[triangulo-1];
        laguna >> triangulo;
        triangulos[i].vertice3 = vertices[triangulo-1];
        triangulos[i].area = area_triangulo(triangulos[i].vertice1, triangulos[i].vertice2, triangulos[i].vertice3);

        area_total+= triangulos[i].area;
    }
    
    ofstream archivo_area("area.txt");

    if (!archivo_area.is_open()){
        cerr << "Ha ocurrido un error " << endl;
        return 1;
    }

    archivo_area << area_total;

    cout << "El area total obtenida es de " << area_total << " unidades cuadradas." << endl;

    laguna.close();
    archivo_area.close();

    delete [] vertices;
    delete [] triangulos;

    vertices = nullptr;
    triangulos = nullptr;

    return 0;
}