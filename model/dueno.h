#ifndef DUENO_H
#define DUENO_H

#include <string>
using namespace std;

class Dueno {
public:
    Dueno();
    Dueno(string nombre, string apellido, string direccion, string telefono);

    void leerDatos();
    void guardarDatos();
    void insertar();
    void modificar(const string& nombre);
    void eliminar(const string& nombre);
    void consultar(const string& nombre);

private:
    string nombre;
    string apellido;
    string direccion;
    string telefono;
};

#endif // DUENO_H
