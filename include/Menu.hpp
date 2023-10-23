
#ifndef LISTAS_TESTS_MENU_HPP
#define LISTAS_TESTS_MENU_HPP
#include <string>
#include <iostream>
#include "Evento.hpp"
#include "Destino.hpp"
using namespace std;


class Menu {
private:

    //Pre:
    //Post: pregunta al usuario si quiere operar en el inventario o en el destino.
    static string  preguntar_accion();
public:

    //Pre:
    //Post: Evalua la accion ingresada por el usuario.
    static void evaluar_accion();
};


#endif //LISTAS_TESTS_MENU_HPP
