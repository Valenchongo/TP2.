#include "../include/Cola.hpp"
#include "Nodo.cpp"
template<typename T>
Cola<T>::Cola() {
    primer_nodo = nullptr;
    ultimo_nodo = nullptr;
    cantidad_datos = 0;
}

template<typename T>
void Cola<T>::alta(T dato) {
    Nodo<T>* nuevo = new Nodo(dato);
    if (vacio()){
        primer_nodo = nuevo;
    }
    else{
        ultimo_nodo->cambiar_siguiente(nuevo);
    }
    ultimo_nodo = nuevo;
    this->cantidad_datos+=1;
}

template<typename T>
T Cola<T>::baja() {
    T dato_a_devolver;
    if(!vacio()){
        Nodo<T> * nodo_a_eliminar= primer_nodo;
        dato_a_devolver = primer_nodo->obtener_dato();
        if(cantidad_datos == 1){
            primer_nodo = nullptr;
            ultimo_nodo = nullptr;
        }
        else{
            primer_nodo = primer_nodo->obtener_siguiente();
        }
        delete nodo_a_eliminar;
        this->cantidad_datos--;
    }
    else{
        throw Cola_exception();
    }

    return dato_a_devolver;
}
template<typename T>
T Cola<T>::primero() {
    if (vacio()){
        throw Cola_exception();
    }else{
        return primer_nodo->obtener_dato();
    }
}

template<typename T>
T Cola<T>::ultimo() {
    if (vacio()){
        throw Cola_exception();
    }else{
        return ultimo_nodo->obtener_dato();
    }
}

template<typename T>
size_t Cola<T>::tamanio() {
    return cantidad_datos;
}

template<typename T>
bool Cola<T>::vacio() {
    if (cantidad_datos == 0){
        return true;
    }
    else{
        return false;
    }
}

template<typename T>
Cola<T>::~Cola() {
    while (!vacio()) {
        Nodo<T> *nodo_a_eliminar = primer_nodo;
        primer_nodo = primer_nodo->obtener_siguiente();
        delete nodo_a_eliminar;
        cantidad_datos--;
    }
}

template<typename T>
Nodo<T> *Cola<T>::buscar_nodo(size_t posicion) {
    Nodo<T> * aux = ultimo_nodo;
    size_t iteraciones_necesarias = cantidad_datos - posicion;
    for(size_t i = 0; i < iteraciones_necesarias ;i++){
        aux = aux->obtener_siguiente();
    }
    return aux;
}
