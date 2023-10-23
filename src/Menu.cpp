
#include "../include/Menu.hpp"

void Menu::evaluar_accion() {
    Destino destino;
    cout<<"para salir ingrese la palabra 'Salir'"<<endl;
    string accion;
    do{
        accion = preguntar_accion();
        if (accion == "inventario"){
            Menu_inv::ejecutar_inventario();
        }
        else if(accion == "destino"){
            Menu_des::ejecutar_destino(destino);
        }
        else if(accion != "salir"){
            cout<<"no ingreso una accion valida"<<endl;
        }

    }while(accion != "salir");
}

string Menu::preguntar_accion() {
    string accion;
    cout<<"operar sobre inventario/destino"<<endl;
    getline(cin,accion);
    return accion;
}

