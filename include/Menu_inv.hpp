//
// Created by Valentin Valle on 9/26/2023.
//

#ifndef AYP2_PLANTILLA_TP1_2C2023_MENU_HPP
#define AYP2_PLANTILLA_TP1_2C2023_MENU_HPP

#include <string>
#include <iostream>
#include "Inventario.hpp"
#include "Item.hpp"
using namespace std;

class Menu_inv {
private:
    // Pre:
    // Post: Se encarga de preguntarle al usuario que accion desea hacer en el inventario.
    static string preguntar_accion();

    // Pre: El inventario debe estar instanciado.
    // Post: Verifica que el item tenga un tipo valido.
    static bool verificar_item_correcto(string tipo);

    // Pre: El inventario debe estar instanciado.
    // Post: Le pide al usuario que introduzca el nombre y el tipo del Item que quiere agregar al inventario.
    static void introducir_item_para_alta(Inventario &inventario);

    // Pre:
    // Post: Le pide al usuario que ingrese el nombre del item que desea eliminar del inventario.
    static string introducir_item_para_baja();
public:
    // Pre:
    // Post: Evalua las acciones introducidas por el usuario, dependiendo de las mismas va a usar distintos metodos del inventario.
    static void ejecutar_inventario();



};


#endif //AYP2_PLANTILLA_TP1_2C2023_MENU_HPP
