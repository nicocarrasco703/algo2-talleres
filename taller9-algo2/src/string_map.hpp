// Nombre: Andrés Nicolas Carrasco
// LU: 1905/21

template <typename T>
typename string_map<T>::Nodo* string_map<T>::copiar(string_map::Nodo *elem, string_map::Nodo *padre) {
    T* def = nullptr;
    if (elem->definicion != nullptr){ //si el significado del nodo a copiar estaba definido la copiamos
        def = new T(*elem->definicion);
    }
    Nodo* copia = new Nodo(def, padre); // creamos un nuevo nodo con el significado del nodo a copiar y su padre
    copia->siguientes = elem->siguientes; // copiamos los siguientes del nodo a copiar
    for(int i = 0; i < tamAlf; i++){ //copiamos los hijos del nodo a copiar
        if (copia->siguientes[i] != nullptr){
            copia->siguientes[i] = copiar(copia->siguientes[i], copia);
        }
    }
    return copia;
}

template <typename T>
string_map<T>::string_map() : raiz(new Nodo(nullptr)), _size(0){
}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    Nodo* nodoraiz = copiar(d.raiz, nullptr);
    int tam = d._size;
    this->raiz = nodoraiz;
    this->_size = tam;
    return *this;
}

template <typename T>
string_map<T>::~string_map(){
    destruir(raiz);
}

template <typename T>
void string_map<T>::destruir(string_map::Nodo* elem) {
    if(elem != nullptr){
        delete elem->definicion;
        for (int i = 0; i < tamAlf; i++){
            destruir(elem->siguientes[i]);
        }
        delete elem;
    }
}

template <typename T>
T& string_map<T>::operator[](const string& clave){
    this->at(clave);
}


template <typename T>
int string_map<T>::count(const string& clave) const{
    Nodo* actual;
    int i = 0;
    if (raiz != nullptr){  // si existe raiz empezamos buscando
        actual = raiz;
        while(i < clave.size()) {
            int caracter = clave[i]; //tomamos un caracter
            if (actual->siguientes[caracter] != nullptr) { // si el puntero al siguiente caracter es no nulo pasamos a ese
                actual = actual->siguientes[caracter];
            }else{
                return 0; // si es nulo, la clave no esta definida
            }
            i++;
        }
        return (actual->definicion != nullptr) ? 1 : 0; //la clave esta definida si en el nodo del ultimo caracter de la clave tiene un significado
    }
    return 0; //si no hay raiz no hay definida ninguna clave
}

template <typename T>
const T& string_map<T>::at(const string& clave) const {
    Nodo* actual = raiz;
    int i = 0;
    while(i < clave.size()){
        int caracter = clave[i];
        actual = actual->siguientes[caracter];
        i++;

    }
    return *actual->definicion;
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    Nodo* actual = raiz;
    int i = 0;
    while(i < clave.size()){
        int caracter = clave[i];
        actual = actual->siguientes[caracter];
        i++;
    }
    if (actual->definicion == nullptr) {
        actual->definicion = new T();
    }

    return *actual->definicion;
}

template <typename T>
void string_map<T>::erase(const string& clave) {
    Nodo* actual = raiz;
    int i = 0;
    while(i < clave.size()){ //buscamos el nodo a borrar
        int caracter = clave[i];
        actual = actual->siguientes[caracter];
        i++;
    }
    delete actual->definicion; //borramos su significado
    actual->definicion = nullptr;
    while (actual->padre != nullptr){ //empezamos a subir
        Nodo* pad = actual->padre;
        if (esNodoInutil(actual)){ //si encontramos un nodo inutil lo borramos y seguimos subiendo
            for (int k = 0; k < tamAlf; k++){
                if (pad->siguientes[k] == actual){
                    pad->siguientes[k] = nullptr;
                }
            }
            delete actual;
        }
        actual = pad;
    }
}

template <typename T>
int string_map<T>::size() const{
    return _size;
}

template <typename T>
bool string_map<T>::empty() const{
    return _size == 0;
}

template <typename T>
void string_map<T>::insert(const pair<string, T>& elem){
    Nodo* actual = raiz;
    string clave = elem.first; //guardamos la clave para insertarla
    T* def = new T(elem.second); //creamos un puntero con el significado de la clave que queremos insertar
    int i = 0;
    while(i < clave.size()){
        int caracter = clave[i];
        if (actual->siguientes[caracter] == nullptr){ // si no habia un puntero al proximo caracter lo creamos y entramos
            actual->siguientes[caracter] = new Nodo(actual);
        }
        actual = actual->siguientes[caracter];
        i++;
    }
    if (actual->definicion == nullptr){
        _size++; //si no estaba definido, aumentamos el tamaño del trie
    } else {
        delete actual->definicion; // si ya estaba definido, borramos el puntero al significado antiguo
    }
    actual->definicion = def; //agregamos en su definicion el significado
};

template <typename T>
bool string_map<T>::esNodoInutil(string_map::Nodo *elem) {
    bool res = false;
    Nodo* hijo;
    int hijos = 0;
    for(int i = 0; i < tamAlf; i++){ //contamos cuantos hijos tiene
        if(elem->siguientes[i] != nullptr){
            hijos++;
            hijo = elem->siguientes[i];
        }
    }
    bool def = elem->definicion != nullptr; // vemos si el nodo tiene un significado
    if (hijos > 1){
        res = false;
    } else if (hijos == 0 && !def || hijos == 1 && esNodoInutil(hijo)){
        res = true;
    }
    return res;
}