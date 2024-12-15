#include "dueno.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector> // Asegúrate de incluir la biblioteca vector

using namespace std;

Dueno::Dueno() : nombre(""), apellido(""), direccion(""), telefono("") {}

Dueno::Dueno(string nombre, string apellido, string direccion, string telefono) 
    : nombre(nombre), apellido(apellido), direccion(direccion), telefono(telefono) {}

void Dueno::leerDatos() {
    ifstream archivo("data/duenos.csv");
    if (!archivo) {
        cerr << "No se pudo abrir el archivo de duenos." << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string campo;
        vector<string> campos; // Asegúrate de declarar el vector

        while (getline(ss, campo, ',')) {
            campos.push_back(campo);
        }

        if (campos.size() == 4) {
            nombre = campos[0];
            apellido = campos[1];
            direccion = campos[2];
            telefono = campos[3];
        }
    }
    archivo.close();
}

void Dueno::guardarDatos() {
    ofstream archivo("data/duenos.csv", ios::app);
    if (!archivo) {
        cerr << "No se pudo abrir el archivo de duenos." << endl;
        return;
    }
    archivo << nombre << "," << apellido << "," << direccion << "," << telefono << endl;
    archivo.close();
}

void Dueno::insertar() {
    cout << "Ingrese el nombre del dueno: ";
    cin >> nombre;
    cout << "Ingrese el apellido: ";
    cin >> apellido;
    cout << "Ingrese la direccion: ";
    cin >> direccion;
    cout << "Ingrese el telefono: ";
    cin >> telefono;
    guardarDatos();
}

void Dueno::modificar(const string& nombre) {
    ifstream archivo("data/duenos.csv");
    ofstream archivoTemp("data/temp.csv");
    if (!archivo || !archivoTemp) {
        cerr << "No se pudo abrir el archivo de duenos." << endl;
        return;
    }

    string linea;
    bool encontrado = false;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string campo;
        vector<string> campos;

        while (getline(ss, campo, ',')) {
            campos.push_back(campo);
        }

        if (campos[0] == nombre) {
            encontrado = true;
            cout << "Ingrese el nuevo apellido: ";
            cin >> campos[1];
            cout << "Ingrese la nueva direccion: ";
            cin >> campos[2];
            cout << "Ingrese el nuevo telefono: ";
            cin >> campos[3];
        }

        archivoTemp << campos[0] << "," << campos[1] << "," << campos[2] << "," << campos[3] << endl;
    }

    archivo.close();
    archivoTemp.close();
    remove("data/duenos.csv");
    rename("data/temp.csv", "data/duenos.csv");

    if (!encontrado) {
        cout << "Dueno no encontrado." << endl;
    }
}

void Dueno::eliminar(const string& nombre) {
    ifstream archivo("data/duenos.csv");
    ofstream archivoTemp("data/temp.csv");
    if (!archivo || !archivoTemp) {
        cerr << "No se pudo abrir el archivo de duenos." << endl;
        return;
    }

    string linea;
    bool encontrado = false;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string campo;
        vector<string> campos;

        while (getline(ss, campo, ',')) {
            campos.push_back(campo);
        }

        if (campos[0] != nombre) {
            archivoTemp << campos[0] << "," << campos[1] << "," << campos[2] << "," << campos[3] << endl;
        } else {
            encontrado = true;
        }
    }

    archivo.close();
    archivoTemp.close();
    remove("data/duenos.csv");
    rename("data/temp.csv", "data/duenos.csv");

    if (!encontrado) {
        cout << "Dueno no encontrado." << endl;
    }
}

void Dueno::consultar(const string& nombre) {
    ifstream archivo("data/duenos.csv");
    if (!archivo) {
        cerr << "No se pudo abrir el archivo de duenos." << endl;
        return;
    }

    string linea;
    bool encontrado = false;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string campo;
        vector<string> campos;

        while (getline(ss, campo, ',')) {
            campos.push_back(campo);
        }

        if (campos[0] == nombre) {
            encontrado = true;
            cout << "Nombre: " << campos[0] << endl;
            cout << "Apellido: " << campos[1] << endl;
            cout << "Direccion: " << campos[2] << endl;
            cout << "Telefono: " << campos[3] << endl;
            break;
        }
    }

    archivo.close();

    if (!encontrado) {
        cout << "Dueno no encontrado." << endl;
    }
}
