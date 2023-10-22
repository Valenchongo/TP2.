
#ifndef LISTAS_TESTS_INVENTARIO_HPP
#define LISTAS_TESTS_INVENTARIO_HPP

#include "Lista_de.hpp"
#include "Item.hpp"
#include <fstream>
#include <iostream>
using namespace std;

class Inventario {
private:
    const size_t CANTIDAD_MAXIMA_DE_ITEMS = 15;
    const size_t VALOR_FUERA_DEL_INVENTARIO = 16;

    Lista_de<Item*> lista;

    // Pre:El nombre pasado por parametro debe estar en el inventario.
    // Post: Busca el indice del item pasado por parametro.
    size_t buscar_indice_item(string nombre_item);

    // Pre: Se le debe pasar un string con formato "nombre,tipo".
    // Post: Retorna el nombre que esta dentro del string que se le paso por parametro.
    string extraer_nombre(string linea);

    // Pre: Se le debe pasar un string con formato "nombre,tipo".
    // Post: Retorna el tipo que esta dentro del string que se le paso por parametro.
    string extraer_tipo(string linea);

public:

    Inventario();

    // Pre: Se le debe pasar por parametro un item valido.
    // Post: Se encarga de agregar al vector el item pasado por parametro.
    void alta(Item* item);

    // Pre: Se le debe pasar el nombre de un item existente.
    // Post: Elimina el primer item con el nombre pasado por parametro.
    void baja(string nombre_item);

    // Pre:
    // Post: Lista la informacion de todos los items dentro del inventario.
    void consulta();

    // Pre:
    // Post: Guarda en un archivo csv todos los items que el jugador guardo en su inventario.
    void escribir_archivo();

    //Pre:
    //Post: Mediante un archivo csv, carga todos los items en la lista del inventario.
    void cargar_archivo();

    void tamaño();
};

#endif //LISTAS_TESTS_INVENTARIO_HPP
