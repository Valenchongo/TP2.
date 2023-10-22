
#include "../include/Destino.hpp"
#include "../src/Cola.cpp"
#include "../src/Evento.cpp"

Destino::Destino() {
    cantidad_mapa = 0;
    cantidad_guardados = 0;
}

void Destino::agregar_evento(Evento evento) {
    if (evaluar_evento_valido(evento)){
        cola.alta(evento);
    }
    else{
        cout<<"el evento no es correcto."<<endl;
    }
}

void Destino::contar_eventos(){
    size_t cantidad_de_eventos = cola.tamanio();
    for (size_t i = 0; i <cantidad_de_eventos;i++){
        Evento evento = cola.baja();
        if (evento == "guardar"){
            cantidad_guardados++;
        }
        else if (evento == "mapa"){
            cantidad_mapa++;
        }
    }
}

bool Destino::evaluar_evento_valido(Evento evento) {
    bool evento_valido = false;
    if (evento == "guardar" || evento == "mapa"){
        evento_valido = true;
    }
    return evento_valido;
}
string Destino::analizar_eventos() {
    string estado_del_jugador;
    if (cantidad_guardados >= 8){
        estado_del_jugador = "Asustado";
    }
    else if(cantidad_mapa > cantidad_guardados && cantidad_mapa > 5){
        estado_del_jugador = "Desorientado";
    }
    else if (cantidad_guardados > cantidad_mapa && cantidad_guardados > 5){
        estado_del_jugador = "Precavido";
    }
    else{
        estado_del_jugador = "No determinado";
    }
    return estado_del_jugador;
}


Destino::~Destino() {

}