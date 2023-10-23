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
    size_t cantidad_mapa;
    size_t cantidad_guardados;
    size_t cantidad_g ;
    size_t cantidad_m;

    //Pre:
    //Post:Evalua si la accion ejecutada en el evento pasado por parametro es correcta.
    bool evaluar_evento_valido(Evento evento);

    //Pre:
    //Post:iguala cantidad_mapa y cantidad_guardados a 0.
    void igualar_cantidades_a_0();

public:
    Destino();

    //Pre: se le debe pasar por parametro un evento valido.
    //Post:agrega el evento a la cola.
    void agregar_evento(Evento evento);

    //Pre:
    //Post:Cuenta la cantidad_mapa y cantidad_guardados desencolando la cola.
    void contar_eventos();

    //Pre:
    //Post:Analiza las distintas cantidades de eventos y dependiendo de las mismas retorna el estado del jugador.
    string analizar_estado_jugador();

    //Pre:antes de ejecutar este metodo hay que usar analizar_estado_jugador() para pasarle el estado por parametro.
    //Post:Resta las cantidades de eventos utilizadas para definir el estado del jugador.
    void acomodar_cantidades(string estado_del_jugador);

    //Pre:antes de ejecutar este metodo hay que usar acomodar_cantidades().
    //Post:vuelve a encolar con la nueva cantidad de elementos.
    void volver_a_encolar();

    void mostrar();

    ~Destino();
}
;


#endif //LISTAS_TESTS_DESTINO_HPP
