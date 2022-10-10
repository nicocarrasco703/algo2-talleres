// Nombre: Nicolas Carrasco
// LU: 1905/21

#include "Lista.h"

Lista::Lista() : prim(nullptr) , ult(nullptr){}


Lista::Lista(const Lista& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

Lista::~Lista() {
    destruir();
}

Lista& Lista::operator=(const Lista& aCopiar) {
    copiar(aCopiar);
    return *this;
}

void Lista::agregarAdelante(const int& elem) {
    Nodo *nuevo = new Nodo(elem, prim, nullptr);
    if (prim == nullptr) { //si no hay elementos en la lista
        ult = nuevo; //se agrega el nuevo nodo como primer elemento
    } else {
        prim->ant = nuevo;
        nuevo->sig = prim;
    }
        prim = nuevo;
}

void Lista::agregarAtras(const int& elem) {
    Nodo* nuevo = new Nodo(elem, nullptr, ult);
    if (prim == nullptr){ //si no hay elementos en la lista
        agregarAdelante(elem);
        delete nuevo;
    }else {
        ult->sig = nuevo;
        nuevo->ant = ult;
        ult = nuevo;
    }
}

void Lista::eliminar(Nat i) {
    Nodo* actual = prim;
    if(i == 0){ // quiero eliminar el primer nodo
        if (actual->sig == nullptr){ // si solo hay un nodo
            prim = nullptr;
            ult = nullptr;
        }
        else {
            prim = actual->sig; // si hay mas de uno
        }
    } else if (actual == ult){ // si
        ult = actual->ant;
    } else {
        for(int j = 0; j < i && actual->sig != nullptr; j++){
            actual = actual->sig;
        }
        actual->ant->sig = actual->sig;
    }
    delete actual;
}

int Lista::longitud() const {
    Nodo* k = prim;
    int res = 0;
    while(k != nullptr){
        res++;
        k = k->sig;
    }
    return res;
}

const int& Lista::iesimo(Nat i) const {
    Nodo* res = prim;
    int k = 0;
    while (i != k){
        res = res->sig;
        k++;
    }
    return res->valor;
}

int& Lista::iesimo(Nat i) {
    Nodo* res = prim;
    int k = 0;
    while (i != k){
        res = res->sig;
        k++;
    }
    return res->valor;
}

void Lista::mostrar(ostream& o) {
    // Completar
}

void Lista::copiar(const Lista &l) {
    destruir();
    Nodo* actual = l.prim;
    while (actual != nullptr){
        agregarAtras(actual->valor);
        actual = actual->sig;
    }
}

void Lista::destruir() {
    Nodo* actual = prim;
    while(actual != nullptr){
        Nodo* siguiente = actual->sig;
        delete actual;
        actual = siguiente;
    }
    prim = nullptr;
    ult = nullptr;
}