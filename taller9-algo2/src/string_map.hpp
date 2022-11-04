template <typename T>
string_map<T>::string_map() : raiz(nullptr), _size(0){
    // COMPLETAR
}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    // COMPLETAR
}

template <typename T>
string_map<T>::~string_map(){
    // COMPLETAR
}

template <typename T>
T& string_map<T>::operator[](const string& clave){
    // COMPLETAR
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
    // COMPLETAR
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    // COMPLETAR
}

template <typename T>
void string_map<T>::erase(const string& clave) {
    // COMPLETAR
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
void string_map<T>::insert(const pair<string, T>&){

};