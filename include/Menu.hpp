
#ifndef LISTAS_TESTS_MENU_HPP
#define LISTAS_TESTS_MENU_HPP
#include <string>
#include <iostream>
#include "Evento.hpp"
#include "Destino.hpp"
using namespace std;


class Menu {
private:
    static string  preguntar_accion();

    static void evaluar_acciones_destino(Destino &destino);

    static string preguntar_accion_destino();

    static Evento crear_evento();

    static void definir_destino(Destino &destino);
public:

    static void evaluar_accion();
};


#endif //LISTAS_TESTS_MENU_HPP
