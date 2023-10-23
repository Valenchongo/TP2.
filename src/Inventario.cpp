
#include "../include/Inventario.hpp"
#include "../src/Item.cpp"
#include "../src/Lista_de.cpp"

using namespace std;
Inventario::Inventario() {

}

void Inventario::tamaño(){
    cout<<lista.tamanio();
}
void Inventario::alta(Item* item) {
    if (lista.tamanio() < CANTIDAD_MAXIMA_DE_ITEMS){
        lista.alta(item);
    }
    else{
        delete item;
        cout<<"el inventario esta lleno..."<<endl;
    }
}

size_t Inventario::buscar_indice_item(string nombre_item) {
    size_t indice = VALOR_FUERA_DEL_INVENTARIO; //le doy el valor de 16 para que en caso que no se encuentre el item retorne este numero que esta fuera del alcance del inventario
    bool encontrado = false;
    size_t iterador = 0;
    while(!encontrado && iterador < lista.tamanio()){
        Item * item_actual = lista.elemento(iterador);
        if(*item_actual == nombre_item){
            indice = iterador;
            encontrado = true;
        }
        iterador++;
    }
    return indice;
}

void Inventario::baja(string nombre_item) {
    if (!lista.vacio()){
        size_t indice = buscar_indice_item(nombre_item);
        if (indice != VALOR_FUERA_DEL_INVENTARIO){
            Item *item = lista.baja(indice);
            delete item;
        }
        else{
            cout<<"error de inventario! no se dispone de ese item"<<endl;
        }
    }else{
        cout<<"el vector esta vacio, no se pueden eliminar items..."<<endl;
    }
}

void Inventario::escribir_archivo() {;
    ofstream archivoOutput(ruta_archivo);
    for (size_t i = 0; i < lista.tamanio() ; i++ ){
        Item * item_actual = lista.elemento(i);
        archivoOutput << *item_actual <<"\n"; //*vector[i]
        delete item_actual;
    }
    archivoOutput.close();
}

void Inventario::cargar_archivo() {
    ifstream archivoInput(ruta_archivo);
    if (archivoInput.is_open()){
        string linea;
        string nombre;
        string tipo;
        size_t iterador = 0;
        while(getline(archivoInput,linea) && iterador < CANTIDAD_MAXIMA_DE_ITEMS){
            nombre = extraer_nombre(linea);
            tipo = extraer_tipo(linea);
            Item* item = new Item(nombre,tipo);
            lista.alta(item);
            iterador++;
        }
        archivoInput.close();
    }
}

string Inventario::extraer_nombre(std::string linea) {
    size_t posicion_de_coma = linea.find(",");
    string nombre = "";
    for(size_t i = 0; i < posicion_de_coma; i++){
        nombre += linea[i];
    }
    return nombre;
}

string Inventario::extraer_tipo(std::string linea) {
    size_t posicion_de_coma = linea.find(",");
    string tipo = "";
    for(size_t i = posicion_de_coma + 1; i < linea.size() ; i++){
        tipo += linea[i];
    }
    return tipo;
}


void Inventario::consulta() {
    string nombre;
    string tipo;
    if (!lista.vacio()){
        for(size_t i = 0; i < lista.tamanio(); i++){
            cout<< i+1<<") ";
            lista.elemento(i)->listar_informacion();
            cout<<endl;
        }
    }
    else{
        cout<<"el inventario esta vacio."<<endl;
    }
}
