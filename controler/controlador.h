#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "../model/mascotas.h"
#include "../model/Dueno.h"

class Controlador {
public:
    Controlador();

    void leerDatosMascotas();
    void guardarDatosMascotas();

    void leerDatosDuenos();
    void guardarDatosDuenos();

    void insertarMascota();
    void modificarMascota(const std::string& nombre);
    void eliminarMascota(const std::string& nombre);
    void consultarMascota(const std::string& nombre);

    void insertarDueno();
    void modificarDueno(const std::string& nombre);
    void eliminarDueno(const std::string& nombre);
    void consultarDueno(const std::string& nombre);

private:
    Mascota mascotaActual;
    Dueno duenoActual;
};

#endif // CONTROLADOR_H