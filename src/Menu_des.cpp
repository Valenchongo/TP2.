//
// Created by Valentin Valle on 10/22/2023.
//

#include "../include/Menu_des.hpp"


void Menu_des::evaluar_acciones_destino(Destino &destino) {
    cout<<"para dejar de realizar acciones sobre Destino ponga la palabra 'volver'"<<endl;
    string accion_destino;
    Evento g("guardar");
    Evento m("mapa");
    for(size_t i = 0; i<8;i++){
        destino.agregar_evento(m);
    }
    do{
        accion_destino = preguntar_accion_destino();
        if (accion_destino == "agregar_evento"){
            Evento evento = crear_evento();
            destino.agregar_evento(evento);
        }
        else if(accion_destino == "definir_destino"){
            destino.contar_eventos();
            definir_destino(destino);
            destino.volver_a_encolar();
            destino.mostrar();

        }
        else if(accion_destino != "volver"){
            cout<<"no ingreso una accion valida"<<endl;
        }

    }while(accion_destino != "volver");
}

string Menu_des::preguntar_accion_destino() {
    string accion;
    cout<<"que accion desea realizar sobre el destino?"<<endl;
    getline(cin,accion);
    return accion;
}

Evento Menu_des::crear_evento() {
    string evento_experimentado;
    cout<<"Evento experimientado: "<<endl;
    getline(cin,evento_experimentado);
    return Evento(evento_experimentado);
}

void Menu_des::definir_destino(Destino &destino) {
    string estado_del_jugador = destino.analizar_estado_jugador();
    destino.acomodar_cantidades(estado_del_jugador);
    if(estado_del_jugador == "Asustado"){
        cout<<"Evento Pyramid Head adelantado"<<endl;
    }
    else if(estado_del_jugador == "Desorientado"){
        cout<<"Aumento de factores ambientales"<<endl;
    }
    else if(estado_del_jugador == "Precavido"){
        cout<<"Aumento de la cantidad de enemigos"<<endl;
    }
    else if (estado_del_jugador == "No determinado"){
        cout<<"Comportamiento aun no definido"<<endl;
    }
}