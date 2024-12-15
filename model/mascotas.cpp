#include "mascotas.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector> // Asegúrate de incluir la biblioteca vector

using namespace std;

Mascota::Mascota() : nombre(""), tipo_animal(""), genero(""), castrado("no"), edad(0) {}

Mascota::Mascota(string nombre, string tipo_animal, string genero, string castrado, int edad) 
    : nombre(nombre), tipo_animal(tipo_animal), genero(genero), castrado(castrado), edad(edad) {}

// Método para leer datos desde el archivo CSV
void Mascota::leerDatos() {
    ifstream archivo("data/mascotas.csv");
    if (!archivo) {
        cerr << "No se pudo abrir el archivo de mascotas." << endl;
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

        if (campos.size() == 5) {
            nombre = campos[0];
            tipo_animal = campos[1];
            genero = campos[2];
            castrado = campos[3];
            try {
                edad = stoi(campos[4]);
            } catch (const invalid_argument& e) {
                cerr << "Error al convertir la edad: " << campos[4] << " en la linea: " << linea << endl;
                edad = 0; // Valor predeterminado
            } catch (const out_of_range& e) {
                cerr << "Numero fuera de rango: " << campos[4] << " en la linea: " << linea << endl;
                edad = 0;
            }
        }
    }
    archivo.close();
}

void Mascota::guardarDatos() {
    ofstream archivo("data/mascotas.csv", ios::app); 
    if (!archivo) {
        cerr << "No se pudo abrir el archivo de mascotas." << endl;
        return;
    }

    archivo << nombre << "," << tipo_animal << "," << genero << "," << castrado << "," << edad << endl;
    archivo.close();
}

void Mascota::insertar() {
    cout << "Ingrese el nombre de la mascota: ";
    cin >> nombre;
    cout << "Ingrese el tipo de animal: ";
    cin >> tipo_animal;
    cout << "Ingrese el genero: ";
    cin >> genero;
    cout << "Ingrese si está castrado (si/no): ";
    cin >> castrado;
    cout << "Ingrese la edad: ";
    cin >> edad;
    guardarDatos();
}

void Mascota::modificar(const string& nombre) {
    ifstream archivo("data/mascotas.csv");
    ofstream archivoTemp("data/temp.csv");
    if (!archivo || !archivoTemp) {
        cerr << "No se pudo abrir el archivo de mascotas." << endl;
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
            cout << "Ingrese el nuevo tipo de animal: ";
            cin >> campos[1];
            cout << "Ingrese el nuevo genero: ";
            cin >> campos[2];
            cout << "Ingrese si está castrado (si/no): ";
            cin >> campos[3];
            cout << "Ingrese la nueva edad: ";
            cin >> campos[4];
        }

        archivoTemp << campos[0] << "," << campos[1] << "," << campos[2] << "," << campos[3] << "," << campos[4] << endl;
    }

    archivo.close();
    archivoTemp.close();
    remove("data/mascotas.csv");
    rename("data/temp.csv", "data/mascotas.csv");

    if (!encontrado) {
        cout << "Mascota no encontrada." << endl;
    }
}

void Mascota::eliminar(const string& nombre) {
    ifstream archivo("data/mascotas.csv");
    ofstream archivoTemp("data/temp.csv");
    if (!archivo || !archivoTemp) {
        cerr << "No se pudo abrir el archivo de mascotas." << endl;
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
            archivoTemp << campos[0] << "," << campos[1] << "," << campos[2] << "," << campos[3] << "," << campos[4] << endl;
        } else {
            encontrado = true;
        }
    }

    archivo.close();
    archivoTemp.close();
    remove("data/mascotas.csv");
    rename("data/temp.csv", "data/mascotas.csv");

    if (!encontrado) {
        cout << "Mascota no encontrada." << endl;
    }
}

void Mascota::consultar(const string& nombre) {
    ifstream archivo("data/mascotas.csv");
    if (!archivo) {
        cerr << "No se pudo abrir el archivo de mascotas." << endl;
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
            cout << "Tipo de Animal: " << campos[1] << endl;
            cout << "Genero: " << campos[2] << endl;
            cout << "Castrado: " << campos[3] << endl;
            cout << "Edad: " << campos[4] << endl;
            break;
        }
    }

    archivo.close();

    if (!encontrado) {
        cout << "Mascota no encontrada." << endl;
    }
}
