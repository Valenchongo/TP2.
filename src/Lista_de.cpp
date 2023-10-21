#include "../include/Lista_de.hpp"
#include "../src/Nodo_de.cpp"
#include <iostream>
using namespace std;


template<typename T>
Lista_de<T>::Lista_de() {
    cantidad_datos = 0;
    primer_nodo == nullptr;
    ultimo_nodo == nullptr;
    cursor = nullptr;
    indice_cursor = -1;
}

template<typename T>
void Lista_de<T>::alta(T dato) {
    Nodo_de<T>* nuevo_nodo = new Nodo_de<T>(dato);
    if (cantidad_datos == 0) {
        primer_nodo = nuevo_nodo;
    } else {
        ultimo_nodo->cambiar_siguiente(nuevo_nodo) ;
        nuevo_nodo->cambiar_anterior(ultimo_nodo) ;
    }
    ultimo_nodo = nuevo_nodo;
    cantidad_datos++;

}

template<typename T>
Nodo_de<T> *Lista_de<T>::obtener_nodo(size_t indice) {
    Nodo_de<T>* aux = primer_nodo;
    if (indice >= cantidad_datos){
        throw Lista_exception();
    }
    else if(indice != 0){
        for (size_t i = 0; i < indice; i++){
            aux = aux->obtener_siguiente();
        }
    }
    return aux;
}

template<typename T>
void Lista_de<T>::alta(T dato, size_t indice) {
    if(indice > cantidad_datos){
        throw Lista_exception();
    }
    else if(indice == cantidad_datos){
        alta(dato);
    }
    else{
        Nodo_de<T> * nodo_siguiente = obtener_nodo(indice);
        Nodo_de<T> * nodo_anterior = nodo_siguiente->obtener_anterior();
        Nodo_de<T> * nuevo_nodo = new Nodo_de<T>(dato,nodo_anterior,nodo_siguiente);
        if (nodo_anterior != nullptr){
            nodo_anterior->cambiar_siguiente(nuevo_nodo);
        }
        else{
            primer_nodo = nuevo_nodo;
        }
        nodo_siguiente->cambiar_anterior(nuevo_nodo);
 //       cursor = ultimo_nodo;
        cantidad_datos++;
    }
}

template<typename T>
T Lista_de<T>::baja() {
    size_t indice_nodo_anterior = cantidad_datos - 2;
    T dato_a_devolver;
    if (vacio()){
        throw Lista_exception();
    }
    else if (cantidad_datos == 1){
        dato_a_devolver = primer_nodo->obtener_dato();
        primer_nodo = nullptr;
        ultimo_nodo = nullptr;
    }
    else{
        dato_a_devolver = ultimo_nodo->obtener_dato();
        Nodo_de<T>* nodo_anterior = obtener_nodo(indice_nodo_anterior);
        nodo_anterior->cambiar_siguiente(nullptr);
        delete ultimo_nodo;
        ultimo_nodo = nodo_anterior;
    }
    cantidad_datos--;
    return dato_a_devolver;
}

template<typename T>
T Lista_de<T>::baja(size_t indice) {
    T dato_a_devolver;
    if(indice >= cantidad_datos){
        throw Lista_exception();
    }
    else if (indice == -1 || indice == cantidad_datos - 1){
        dato_a_devolver = baja();
    }
    else{
        Nodo_de<T> * nodo_a_eliminar = obtener_nodo(indice);
        dato_a_devolver = nodo_a_eliminar->obtener_dato();
        Nodo_de<T> * nodo_anterior = nodo_a_eliminar->obtener_anterior();
        Nodo_de<T> * nodo_siguiente = nodo_a_eliminar->obtener_siguiente();
        nodo_siguiente->cambiar_anterior(nodo_anterior);
        if(indice == 0){
            primer_nodo = nodo_siguiente;
        }
        else{
            nodo_anterior->cambiar_siguiente(nodo_siguiente);
        }
        //delete nodo_a_eliminar;
        cantidad_datos--;
    }
    return dato_a_devolver;
}

template<typename T>
T Lista_de<T>::primero() {
    if(vacio()){
        throw Lista_exception();
    }
    return primer_nodo->obtener_dato();
}

template<typename T>
T Lista_de<T>::ultimo() {
    if(vacio()){
        throw Lista_exception();
    }
    return ultimo_nodo->obtener_dato();
}

template<typename T>
T Lista_de<T>::elemento(size_t indice) {
    if (indice > cantidad_datos){
        throw Lista_exception();
    }
    else{
        return obtener_nodo(indice)->obtener_dato();
    }
}

template<typename T>
bool Lista_de<T>::puede_avanzar() {
    bool avanzar_posible = false;
    if (cursor != nullptr){
        avanzar_posible = true;
    }
    return avanzar_posible;
}

template<typename T>
T Lista_de<T>::avanzar(bool siguiente) {
    T dato_a_devolver;
    if(puede_avanzar()){
        dato_a_devolver = cursor->obtener_dato();
        if (!siguiente){
            cursor = cursor->obtener_anterior();
        }
        else{
            cursor = cursor->obtener_siguiente();
        }
    }
    else{
        throw Lista_exception();
    }

    return dato_a_devolver;
}

template<typename T>
void Lista_de<T>::reiniciar_cursor(bool principio) {
    if (vacio()){
        cursor = nullptr;
        indice_cursor = -1;
    }
    else if (principio){
        cursor = primer_nodo;
        indice_cursor = 0;
    }
    else{
        cursor = ultimo_nodo;
        indice_cursor = cantidad_datos - 1;
    }
}

template<typename T>
size_t Lista_de<T>::tamanio() {
    return cantidad_datos;
}
template<typename T>
bool Lista_de<T>::vacio() {
    return cantidad_datos == 0;
}

template<typename T>
Lista_de<T>::~Lista_de() {
    for (size_t i = 0; i < cantidad_datos; i++){
        baja();
    }
}
template<typename T>
void Lista_de<T>::mostrar() {
    Nodo_de<T> * aux = primer_nodo;
    for(size_t i = 0; i < cantidad_datos; i++){
        aux = aux->obtener_siguiente();
    }
}