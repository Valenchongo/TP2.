
#include "../include/Destino.hpp"
#include "../src/Cola.cpp"
#include "../src/Evento.cpp"

Destino::Destino() {
    cantidad_mapa = 0;
    cantidad_guardados = 0;
    cantidad_g = 0;
    cantidad_m = 0 ;
}

void Destino::agregar_evento(Evento evento) {
    if (evaluar_evento_valido(evento)){
        cola.alta(evento);
    }
    cout<<cantidad_g<<" cantidad de guardados"<<endl;
    cout<<cantidad_m<<" cantidad de mapa"<<endl;

}

void Destino::contar_eventos(){
    size_t cantidad_de_eventos = cola.tamanio();
    igualar_cantidades_a_0();
    for (size_t i = 0; i <cantidad_de_eventos;i++){
        Evento evento = cola.baja();
        if (evento == "guardar"){
            cantidad_guardados++;
            cantidad_g++;
        }
        else if (evento == "mapa"){
            cantidad_mapa++;
            cantidad_m++;
        }
    }
    //cantidad_mapa = contador_mapa;
    //cantidad_guardados = contador_guardados;
}

bool Destino::evaluar_evento_valido(Evento evento) {
    bool evento_valido = false;
    if (evento == "guardar"){
        cantidad_g++;
    }
    if (evento == "mapa"){
        cantidad_m++;
    }
    if (evento == "guardar" || evento == "mapa"){
        evento_valido = true;
    }
    else{
        cout<<"el evento no es correcto."<<endl;
    }
    return evento_valido;
}
string Destino::analizar_estado_jugador() {
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

void Destino::acomodar_cantidades(std::string estado_del_jugador) {
    if(estado_del_jugador == "Asustado"){
        cantidad_guardados -= 8;
    }
    else if(estado_del_jugador == "Desorientado"){
        if (cantidad_guardados != 0){
            cantidad_mapa = cantidad_mapa - cantidad_guardados;
            cantidad_mapa--;//de esta forma
        }
        else{
            cantidad_mapa -= 6;
        }
        cantidad_guardados = 0;
    }
    else if(estado_del_jugador == "Precavido"){
        if (cantidad_mapa != 0){
            cantidad_guardados = cantidad_guardados- cantidad_mapa;
            cantidad_guardados--;
        }
        else{
            cantidad_guardados -= 6;
        }
        cantidad_mapa = 0;
    }
    cantidad_g=cantidad_guardados;
    cantidad_m = cantidad_mapa;
}

void Destino::volver_a_encolar() {
    Evento guardar("guardar");
    Evento mapa("mapa");
    for (size_t i = 0; i < cantidad_guardados; i++){
        cola.alta(guardar);
    }
    for (size_t i = 0; i < cantidad_mapa; i++){
        cola.alta(mapa);
    }
}

void Destino::mostrar() {
    cout<<cantidad_guardados<<" guardaros"<<endl;
    cout<<cantidad_mapa<<" map"<<endl;
}

void Destino::igualar_cantidades_a_0() {
    cantidad_guardados = 0;
    cantidad_mapa = 0;
    cantidad_g = 0;
    cantidad_m = 0;
}
Destino::~Destino() {

}