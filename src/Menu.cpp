
#include "../include/Menu.hpp"

void Menu::evaluar_accion() {
    Destino destino;
    cout<<"para salir ingrese la palabra 'Salir'"<<endl;
    string accion;
    do{
        accion = preguntar_accion();
        if (accion == "inventario"){

        }
        else if(accion == "destino"){
            evaluar_acciones_destino(destino);
        }
        else if(accion != "salir"){
            cout<<"no ingreso una accion valida"<<endl;
        }

    }while(accion != "salir");
}


void Menu::evaluar_acciones_destino(Destino &destino) {
    cout<<"para dejar de realizar acciones sobre Destino ponga la palabra 'volver'"<<endl;
    string accion_destino;
    do{
        accion_destino = preguntar_accion_destino();
        if (accion_destino == "agregar_evento"){
            Evento evento = crear_evento();
            destino.agregar_evento(evento);
        }
        else if(accion_destino == "definir_destino"){
            definir_destino(destino);
        }
        else if(accion_destino != "volver"){
            cout<<"no ingreso una accion valida"<<endl;
        }

    }while(accion_destino != "volver");
}


string Menu::preguntar_accion() {
    string accion;
    cout<<"operar sobre inventario/destino"<<endl;
    getline(cin,accion);
    return accion;
}

string Menu::preguntar_accion_destino() {
    string accion;
    cout<<"que accion desea realizar sobre el destino?"<<endl;
    getline(cin,accion);
    return accion;
}

Evento Menu::crear_evento() {
    string evento_experimentado;
    cout<<"Evento experimientado: "<<endl;
    getline(cin,evento_experimentado);
    return Evento(evento_experimentado);
}

void Menu::definir_destino(Destino &destino) {
    destino.contar_eventos();
    string estado_del_jugador = destino.analizar_eventos();
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