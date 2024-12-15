#include "controlador.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Controlador::Controlador() {
    leerDatosDuenos();
    leerDatosMascotas();
}

void Controlador::leerDatosMascotas() {
    ifstream archivo("data/mascotas.csv");
    if (!archivo) {
        cerr << "No se pudo abrir el archivo de mascotas." << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string nombre, tipo_animal, genero, castrado, campo;
        int edad;

        getline(ss, nombre, ',');
        getline(ss, tipo_animal, ',');
        getline(ss, genero, ',');
        getline(ss, castrado, ',');
        getline(ss, campo, ',');
        try {
            edad = stoi(campo);
        } catch (const invalid_argument& e) {
            cerr << "Error al convertir la edad: " << campo << " en la linea: " << linea << endl;
            edad = 0; // Valor predeterminado
        } catch (const out_of_range& e) {
            cerr << "Numero fuera de rango: " << campo << " en la linea: " << linea << endl;
            edad = 0;
        }

        cout << "Nombre: " << nombre << endl;
        cout << "Tipo de Animal: " << tipo_animal << endl;
        cout << "Genero: " << genero << endl;
        cout << "Castrado: " << castrado << endl;
        cout << "Edad: " << edad << endl;
        cout << "--------------------------" << endl;
    }
    archivo.close();
}

void Controlador::guardarDatosMascotas() {
    mascotaActual.guardarDatos();
}

void Controlador::leerDatosDuenos() {
    ifstream archivo("data/duenos.csv");
    if (!archivo) {
        cerr << "No se pudo abrir el archivo de duenos." << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string nombre, apellido, direccion, telefono;

        getline(ss, nombre, ',');
        getline(ss, apellido, ',');
        getline(ss, direccion, ',');
        getline(ss, telefono, ',');

        cout << "Nombre: " << nombre << endl;
        cout << "Apellido: " << apellido << endl;
        cout << "Direccion: " << direccion << endl;
        cout << "Telefono: " << telefono << endl;
        cout << "--------------------------" << endl;
    }
    archivo.close();
}

void Controlador::guardarDatosDuenos() {
    duenoActual.guardarDatos();
}

void Controlador::insertarMascota() {
    mascotaActual.insertar();
    guardarDatosMascotas();
}

void Controlador::modificarMascota(const string& nombre) {
    mascotaActual.modificar(nombre);
    guardarDatosMascotas();
}

void Controlador::eliminarMascota(const string& nombre) {
    mascotaActual.eliminar(nombre);
    guardarDatosMascotas();
}

void Controlador::consultarMascota(const string& nombre) {
    mascotaActual.consultar(nombre);
}

void Controlador::insertarDueno() {
    duenoActual.insertar();
    guardarDatosDuenos();
}

void Controlador::modificarDueno(const string& nombre) {
    duenoActual.modificar(nombre);
    guardarDatosDuenos();
}

void Controlador::eliminarDueno(const string& nombre) {
    duenoActual.eliminar(nombre);
    guardarDatosDuenos();
}

void Controlador::consultarDueno(const string& nombre) {
    duenoActual.consultar(nombre);
}
