//
// Created by Valentin Valle on 10/14/2023.
//

#ifndef LISTAS_TESTS_DESTINO_HPP
#define LISTAS_TESTS_DESTINO_HPP
#include <string>
#include <iostream>
#include "Cola.hpp"
#include "Evento.hpp"
using namespace std;

class Destino {
private:
    Cola<Evento> cola;
    int cantidad_mapa;
    int cantidad_guardados;

    bool evaluar_evento_valido(Evento evento);

public:
    Destino();

    void agregar_evento(Evento evento);

    void contar_eventos();

    string analizar_eventos();

    ~Destino();
}
;


#endif //LISTAS_TESTS_DESTINO_HPP
