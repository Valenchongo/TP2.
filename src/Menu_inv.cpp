
#include "../include/Menu_inv.hpp"
#include <fstream>
#include <iostream>


void Menu_inv::ejecutar_inventario() {
    Inventario inventario{};
    inventario.cargar_archivo();
    cout<<"si quiere salir del inventario ponga la palabra 'salir'"<<endl;
    string accion;
    do{
        accion = preguntar_accion();
        if(accion == "alta"){
            introducir_item_para_alta(inventario);
        }else if (accion == "baja"){
            string nombre_item = introducir_item_para_baja();
            inventario.baja(nombre_item);
        }else if(accion == "consulta"){
            inventario.consulta();
        }
        else if (accion != "salir"){
            cout<<"la accion '"<<accion<<"' no existe"<<endl;
        }
    }while(accion != "salir");
    inventario.escribir_archivo();
}

void Menu_inv::introducir_item_para_alta(Inventario &inventario) {
    bool item_correcto = false;
    string nombre;
    string tipo;
    do{
        cout<<"Nombre del item: ";
        getline(cin,nombre);
        cout<<"Tipo del item: ";
        getline(cin,tipo);
        item_correcto = verificar_item_correcto(tipo);
        if (!item_correcto){
            cout<<"el tipo ingresado es incorrecto, intente otra vez."<<endl;
        }
    }while(!item_correcto);
    Item* item = new Item(nombre,tipo);
    inventario.alta(item);
}

bool Menu_inv::verificar_item_correcto(string tipo) {
    return(tipo == TIPO_MUNICION || tipo == TIPO_CURATIVO || tipo == TIPO_PUZZLE);
}

string Menu_inv::introducir_item_para_baja() {
    string nombre;
    cout<<"indique el item a eliminar: ";
    getline(cin,nombre);
    return nombre;
}
string Menu_inv::preguntar_accion() {
    string accion;
    cout<<"Accion sobre el inventario: ";
    getline(cin,accion);
    return accion;
}
