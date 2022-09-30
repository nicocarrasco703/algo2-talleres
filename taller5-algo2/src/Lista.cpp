#include "Lista.h"

<<<<<<< HEAD
Lista::Lista() : prim(NULL) , ult(NULL){
=======
Lista::Lista() : longitud(0), prim(NULL), ult(NULL){
>>>>>>> refs/remotes/origin/main
    // Completar
}

Lista::Lista(const Lista& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

Lista::~Lista() {
    destruir();
}

Lista& Lista::operator=(const Lista& aCopiar) {
    // Completar
    return *this;
}

void Lista::agregarAdelante(const int& elem) {
    // Completar
}

void Lista::agregarAtras(const int& elem) {
    Nodo* nuevo = new Nodo(elem, NULL, NULL);
    if (prim = NULL){
        prim = nuevo;
        return;
    }
    Nodo* actual = prim;
    if (actual->sig != NULL){
        actual = actual -> sig;
    }
    actual->sig = nuevo;
}

void Lista::eliminar(Nat i) {
    // Completar
}

int Lista::longitud() const {
    // Completar
    return -1;
}

const int& Lista::iesimo(Nat i) const {
    // Completar
    assert(false);
}

int& Lista::iesimo(Nat i) {
    // Completar (hint: es igual a la anterior...)
    assert(false);
}

void Lista::mostrar(ostream& o) {
    // Completar
}

void Lista::copiar(const Lista &l) {
    Nodo* actual = l.prim;
    while (actual != nullptr){

    }
}

void Lista::destruir() {
    Nodo* actual = prim;
    while(actual != nullptr){
        Nodo* siguiente = actual->sig;
        delete actual;
        actual = siguiente;
    }
}