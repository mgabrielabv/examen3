#ifndef MASCOTAS_H
#define MASCOTAS_H

#include <string>

using namespace std;

class Mascota {
public:
    Mascota();
    Mascota(string nombre, string tipo_animal, string genero, string castrado, int edad);

    void leerDatos(); 
    void guardarDatos();
    void insertar();
    void modificar(const string& nombre);
    void eliminar(const string& nombre);
    void consultar(const string& nombre);

private:
    string nombre;
    string tipo_animal; 
    string genero; 
    string castrado; 
    int edad;
};

#endif // MASCOTAS_H
