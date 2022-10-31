
template <class T>
Conjunto<T>::Conjunto() : _raiz(nullptr), _cardinal(0) {
}

template <class T>
Conjunto<T>::~Conjunto() { 
    // Completar
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
        Nodo* padre = nullptr;
        Nodo* actual = this->_raiz;
        while (actual != nullptr && actual->valor != clave){ // busco el lugar donde debe insertarse
            padre = actual; //guardo el nodo actual antes de tomar un camino (será el padre luego de tomar un camino)
            if(clave < actual->valor){
                actual = actual->izq;
            } else{
                actual = actual->der;
            }
        }// llego lugar donde se deberia ubicar
        Nodo* nuevo = new Nodo(clave);
        this->_cardinal++; //se aumenta el cardinal del conjunto
        if (padre == nullptr){ //el caso en que el conjunto sea vacio, la raiz pasara a ser el valor insertado
            this->_raiz = nuevo;
        }
        else if (clave < padre->valor){ // determinamos en que lugar debemos ubicar el nuevo elemento respecto al padre y lo insertamos
            padre->izq = nuevo;
        }else{
            padre->der = nuevo;
        }

    }
}

template <class T>
void Conjunto<T>::remover(const T&) {
    assert(false);
}

template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    assert(false);
}

template <class T>
const T& Conjunto<T>::minimo() const {
    assert(false);
}

template <class T>
const T& Conjunto<T>::maximo() const {
    assert(false);
}

template <class T>
unsigned int Conjunto<T>::cardinal() const {
    return this->_cardinal;
}

template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {
    assert(false);
}

