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

    //Pre:
    //Post:retorna el tipo de accion quiere realizar el usuario sobre el destino.
    static string preguntar_accion_destino();

    //Pre:
    //Post:Devuelve un evento creado por el usuario.
    static Evento crear_evento();

    //Pre:
    //Post:Pasa por consola lo que sucedera en el juego dependiendo del estado del jugador.
    static void definir_destino(Destino &destino);
public:

    //Pre:
    //Post:Evalua la accion sobre el destino ingresada por el usuario.
    static void ejecutar_destino(Destino &destino);

};

#endif //LISTAS_TESTS_MENU_DES_HPP
