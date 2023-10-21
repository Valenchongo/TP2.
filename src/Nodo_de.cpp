#include "../include/Nodo_de.hpp"

template<typename T>
Nodo_de<T>::Nodo_de(T dato) {
    this->dato = dato;
    this->anterior = nullptr;
    this->siguiente = nullptr;
}

template<typename T>
Nodo_de<T>::Nodo_de(T dato, Nodo_de<T> *anterior, Nodo_de<T> *siguiente) {
    this->dato = dato;
    this->anterior = anterior;
    this->siguiente = siguiente;
}

template<typename T>
Nodo_de<T> *Nodo_de<T>::obtener_anterior() {
    return anterior;
}

template<typename T>
Nodo_de<T> *Nodo_de<T>::obtener_siguiente() {
    return siguiente;
}

template<typename T>
void Nodo_de<T>::cambiar_siguiente(Nodo_de<T> *nuevo) {
    siguiente = nuevo;
}

template<typename T>
void Nodo_de<T>::cambiar_anterior(Nodo_de<T> *nuevo) {
    anterior = nuevo;
}

template<typename T>
T Nodo_de<T>::obtener_dato() {
    return dato;
}

template<typename T>
Nodo_de<T>::~Nodo_de() {

}