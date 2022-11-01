// Nombre: Nicolas Carrasco
// LU: 1905/21

template <class T>
Conjunto<T>::Conjunto() : _raiz(nullptr), _cardinal(0) {
}

template <class T>
Conjunto<T>::~Conjunto() {
    destruir(_raiz);
}

template <class T>
void Conjunto<T>::destruir(Nodo* elem) {
    if (elem != nullptr){
        destruir(elem->izq);
        destruir(elem->der);
        delete elem;
    }
}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {
    Nodo* actual = this->_raiz;
    while (actual != nullptr && actual->valor != clave){ // el ciclo sigue hasta que llegue a una hoja o encuentre el valor
        if(clave < actual->valor){
            actual = actual->izq;
        } else{
            actual = actual->der;
        }
    }
    return actual != nullptr; // si llegue a una hoja y no encontre el valor entonces no está
}

template <class T>
void Conjunto<T>::insertar(const T& clave) {
    if(!pertenece(clave)) { // si ya pertenecia entonces no se inserta
        Nodo* padretemp = nullptr;
        Nodo* actual = this->_raiz;
        while (actual != nullptr){ // busco el lugar donde debe insertarse
            padretemp = actual; //guardo el nodo actual antes de tomar un camino (será el padre luego de tomar un camino)
            if(clave < actual->valor){
                actual = actual->izq;
            } else{
                actual = actual->der;
            }
        }// llego lugar donde se deberia ubicar
        Nodo* nuevo = new Nodo(clave);
        this->_cardinal++; //se aumenta el cardinal del conjunto
        if (padretemp == nullptr){ //el caso en que el conjunto sea vacio, la raiz pasara a ser el valor insertado (padre = NULL)
            this->_raiz = nuevo;
        }
        else if (clave < padretemp->valor){ // determinamos en que lugar debemos ubicar el nuevo elemento respecto al padre y lo insertamos
            padretemp->izq = nuevo;
            padretemp->izq->padre = padretemp; // asignamos el padre del nuevo nodo
        }else{
            padretemp->der = nuevo;
            padretemp->der->padre = padretemp; // asignamos el padre del nuevo nodo
        }

    }
}

template <class T>
void Conjunto<T>::remover(const T& clave) {
    Nodo* actual = this->_raiz;
    while (actual->valor != clave && actual != nullptr){ // buscamos el valor
        if(clave < actual->valor){
            actual = actual->izq;
        } else{
            actual = actual->der;
        }
    }
    if (actual != nullptr) { //si es un conjunto vacio o el valor no se encuentra, no se hace nada
        if (actual->izq == nullptr && actual->der == nullptr) { // SI ES HOJA (no tiene hijos)
            if (actual != _raiz){
                if (actual == actual->padre->der) { //si el nodo borrado era hijo derecho
                    actual->padre->der = nullptr;
                } else { //si el nodo borrado era hijo izquierdo
                    actual->padre->izq = nullptr;
                }
                delete actual; //borramos el nodo
                _cardinal--;
            }else { // si el elemento que queremos borrar es el unico del conjuto lo borramos directamente
                delete actual; //borramos el nodo
                _raiz = nullptr;
                _cardinal--;
            }
        } else if (actual->izq != nullptr && actual->der == nullptr) { // SI TIENE SOLO UN HIJO IZQUIERDO
            if (actual != _raiz){
                actual->izq->padre = actual->padre; // el nuevo padre de su hijo izquierdo será el padre del nodo borrado
                if (actual == actual->padre->der) { //si el nodo borrado era hijo derecho
                    actual->padre->der = actual->izq;
                } else { //si el nodo borrado era hijo izquierdo
                    actual->padre->izq = actual->izq;
                }
                delete actual; //borramos el nodo
                _cardinal--;
            } else {
                _raiz = actual->izq;
                delete actual;
                _cardinal--;
            }
        } else if (actual->der != nullptr && actual->izq == nullptr) { // SI TIENE SOLO UN HIJO DERECHO
            if (actual != _raiz){
                actual->der->padre = actual->padre; // el nuevo padre de su hijo derecho será el padre del nodo borrado
                if (actual == actual->padre->der) { //si el nodo borrado era hijo derecho
                    actual->padre->der = actual->der;
                } else { //si el nodo borrado era hijo izquierdo
                    actual->padre->izq = actual->der;
                }
                delete actual; //borramos el nodo
                _cardinal--;
            } else{
                _raiz = actual->der;
                delete actual;
                _cardinal--;
            }
        } else { // SI TIENE DOS HIJOS, buscamos el sucesor inmediato
            T suc = minimoSub(actual->der); //guardamos temporalmente el valor del sucesor
            remover(suc); // se borra el nodo del sucesor
            actual->valor = suc; // se copia el valor del sucesor al nodo que se quiere borrar
        }
    }

}

template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    Nodo* actual = this->_raiz;
    while (actual->valor != clave){ // buscamos el valor
        if(clave < actual->valor){
            actual = actual->izq;
        } else{
            actual = actual->der;
        }
    }
    if (actual->der != nullptr){ //caso tiene subarbol derecho
        return minimoSub(actual->der); //devuelvo el minimo del subarbol derecho
    }else{                              // caso no hay subarbol derecho
        if(actual->padre->izq == actual){ // si es hijo izquierdo devuelvo el padre
            return actual->padre->valor;
        }else{
            actual = actual->padre; //subimos un nivel
            while(actual->padre->izq != actual){ //subo hasta que salga por la rama izquierda de un nodo
                actual = actual->padre;
            }
            return  actual->valor;
        }
    }
}

template <class T>
const T& Conjunto<T>::minimo() const {
    Nodo* actual = this->_raiz;
    while(actual->izq != nullptr){
        actual = actual->izq;
    }
    return actual->valor;
}

template <class T>
const T& Conjunto<T>::maximo() const {
    Nodo* actual = this->_raiz;
    while(actual->der != nullptr){
        actual = actual->der;
    }
    return actual->valor;
}

template <class T>
unsigned int Conjunto<T>::cardinal() const {
    return this->_cardinal;
}

template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {
    return inorder();
}

template <class T>
void Conjunto<T>::inorder() const{
    stack<Nodo*> s;
    vector<T> res;
    Nodo* actual = this->_raiz;
    while(actual != nullptr || s.empty() == false){
        while(actual != nullptr){ //voy al nodo mas a la izquierda, apilando todos los nodos en el camino
            s.push(actual);
            actual = actual->izq;
        }
        actual = s.top(); //actual es el nodo de la punta de la pila
        s.pop(); // desapilo
        cout << actual->valor << " "; //imprimo el valor
        actual = actual->der; //me voy a la derecha
    }
}


template <class T>
const T& Conjunto<T>::minimoSub(Nodo* k) const {
    while(k->izq != nullptr){
        k = k->izq;
    }
    return k->valor;
}