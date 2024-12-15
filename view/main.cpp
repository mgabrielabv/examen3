#include <iostream>
#include <string>
#include "Controlador.h"

using namespace std;

void mostrarMenuPrincipal() {
    cout << "\n=============================================" << endl;
    cout << "           SISTEMA DE REGISTRO DE ADOPCION" << endl;
    cout << "=============================================" << endl;
    cout << "1. Gestionar Mascotas" << endl;
    cout << "2. Gestionar Duenos" << endl;
    cout << "3. Leer datos de mascotas" << endl;
    cout << "4. Guardar datos de mascotas" << endl;
    cout << "5. Leer datos de duenos" << endl;
    cout << "6. Guardar datos de duenos" << endl;
    cout << "7. Salir" << endl;
    cout << "=============================================" << endl;
    cout << "Seleccione una opcion: ";
}

void mostrarMenuMascotas() {
    cout << "\n=============================================" << endl;
    cout << "           GESTION DE MASCOTAS" << endl;
    cout << "=============================================" << endl;
    cout << "1. Insertar nueva mascota" << endl;
    cout << "2. Modificar mascota existente" << endl;
    cout << "3. Eliminar mascota" << endl;
    cout << "4. Consultar mascota" << endl;
    cout << "5. Volver al menu principal" << endl;
    cout << "=============================================" << endl;
    cout << "Seleccione una opcion: ";
}

void mostrarMenuDuenos() {
    cout << "\n=============================================" << endl;
    cout << "           GESTION DE DUENOS" << endl;
    cout << "=============================================" << endl;
    cout << "1. Insertar nuevo dueno" << endl;
    cout << "2. Modificar dueno existente" << endl;
    cout << "3. Eliminar dueno" << endl;
    cout << "4. Consultar dueno" << endl;
    cout << "5. Volver al menu principal" << endl;
    cout << "=============================================" << endl;
    cout << "Seleccione una opcion: ";
}

int main() {
    Controlador controlador;
    int opcionPrincipal;

    do {
        mostrarMenuPrincipal();
        cin >> opcionPrincipal;

        switch (opcionPrincipal) {
            case 1: {
                int opcionMascotas;
                do {
                    mostrarMenuMascotas();
                    cin >> opcionMascotas;
                    string nombreMascota;
                    switch (opcionMascotas) {
                        case 1:
                            controlador.insertarMascota();
                            break;
                        case 2:
                            cout << "Ingrese el nombre de la mascota a modificar: ";
                            cin >> nombreMascota;
                            controlador.modificarMascota(nombreMascota);
                            break;
                        case 3:
                            cout << "Ingrese el nombre de la mascota a eliminar: ";
                            cin >> nombreMascota;
                            controlador.eliminarMascota(nombreMascota);
                            break;
                        case 4:
                            cout << "Ingrese el nombre de la mascota a consultar: ";
                            cin >> nombreMascota;
                            controlador.consultarMascota(nombreMascota);
                            break;
                        case 5:
                            break;
                        default:
                            cout << "Opcion invalida. Intente de nuevo." << endl;
                            break;
                    }
                } while (opcionMascotas != 5);
                break;
            }
            case 2: {
                int opcionDuenos;
                do {
                    mostrarMenuDuenos();
                    cin >> opcionDuenos;
                    string nombreDueno;
                    switch (opcionDuenos) {
                        case 1:
                            controlador.insertarDueno();
                            break;
                        case 2:
                            cout << "Ingrese el nombre del dueno a modificar: ";
                            cin >> nombreDueno;
                            controlador.modificarDueno(nombreDueno);
                            break;
                        case 3:
                            cout << "Ingrese el nombre del dueno a eliminar: ";
                            cin >> nombreDueno;
                            controlador.eliminarDueno(nombreDueno);
                            break;
                        case 4:
                            cout << "Ingrese el nombre del dueno a consultar: ";
                            cin >> nombreDueno;
                            controlador.consultarDueno(nombreDueno);
                            break;
                        case 5:
                            break;
                        default:
                            cout << "Opcion invalida. Intente de nuevo." << endl;
                            break;
                    }
                } while (opcionDuenos != 5);
                break;
            }
            case 3:
                controlador.leerDatosMascotas();
                break;
            case 4:
                controlador.guardarDatosMascotas();
                break;
            case 5:
                controlador.leerDatosDuenos();
                break;
            case 6:
                controlador.guardarDatosDuenos();
                break;
            case 7:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
                break;
        }

    } while (opcionPrincipal != 7);

    return 0;
}
