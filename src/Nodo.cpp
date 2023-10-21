#include "../include/Nodo.hpp"

template<typename T>
Nodo<T>::Nodo(T dato) {
    this->dato = dato;
}

template<typename T>
Nodo<T> *Nodo<T>::obtener_siguiente() {
    return siguiente;
}

template<typename T>
void Nodo<T>::cambiar_siguiente(Nodo<T> *nuevo) {
    siguiente = nuevo;
}

template<typename T>
T Nodo<T>::obtener_dato() {
    return dato;
}

template<typename T>
Nodo<T>::~Nodo() {

}