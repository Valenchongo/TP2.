//
// Created by Valentin Valle on 10/22/2023.
//

#ifndef LISTAS_TESTS_MENU_DES_HPP
#define LISTAS_TESTS_MENU_DES_HPP
#include <string>
#include <iostream>
#include "Evento.hpp"
#include "Destino.hpp"

class Menu_des {
private:
    static string preguntar_accion_destino();

    static Evento crear_evento();

    static void definir_destino(Destino &destino);
public:
    static void evaluar_acciones_destino(Destino &destino);

};

#endif //LISTAS_TESTS_MENU_DES_HPP
