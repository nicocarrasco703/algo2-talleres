#ifndef ALGO2_LABO_CLASE5_ALGORITMOS_H
#define ALGO2_LABO_CLASE5_ALGORITMOS_H

#include <utility>
#include <iterator>
#include <vector>

// Completar con las funciones del enunciado

//ej 1
/*template<class Contenedor>
typename Contenedor::value_type minimo(const Contenedor& c){
    typename Contenedor::value_type it = *(c.begin());
    for (auto i : c){
        if(i < it) {
            it = i;
        }
    }
    return it;
};*/

//ej 8
template<class Contenedor>
typename Contenedor::value_type minimo(const Contenedor& c){
    auto it = c.begin();
    for (auto val = c.begin();val != c.end();val++){
        if(*val < *it) {
            it = val;
        }
    }
    return *it;
};

template<class Contenedor>
typename Contenedor::value_type promedio(const Contenedor& c){
    auto sum = 0;
    double total = 0;
    for (auto k : c){
        sum += k;
        total++;
    }
    return sum / total;
};

//ej 3
/*template<class Iterator>
typename Iterator::value_type minimoIter(const Iterator& desde, const Iterator& hasta){
    typename Iterator::value_type min = *desde;
    for (auto it = desde; it != hasta; ++it){
        if (*it < min){
            min = *it;
        }
    }
    return min;
};*/
//ej 8
template<class Iterator>
typename Iterator::value_type minimoIter(const Iterator& desde, const Iterator& hasta){
    auto min = desde;
    auto it = desde;
    while (it != hasta){
        if (*it < *min){
            min = it;
        }
        it++;
    }
    return *min;
};


template<class Iterator>
typename Iterator::value_type promedioIter(const Iterator& desde, const Iterator& hasta){
    auto sum = 0;
    double total = 0;
    for (auto it = desde; it != hasta; ++it){
        sum += *it;
        total++;
    }
    return sum / total;
};

template<class Contenedor>
void filtrar(Contenedor &c, const typename Contenedor::value_type& elem){
    auto it = c.begin();
    while (it != c.end()){
        if (*it == elem){
            it = c.erase(it); // devuelve el iterador al proximo elemento despues de borrar
        }else{
            it++;
        }
    }
};

template<class Contenedor>
bool ordenado(Contenedor &c){
    bool res = true;
    auto ant = c.begin();
    for(auto i : c){
        if (*ant > i){
            res = false;
            break;
        }
    }
    return res;
};

template<class Contenedor>
std::pair<Contenedor, Contenedor> split(const Contenedor & c, const typename Contenedor::value_type& elem){
    Contenedor mas;
    Contenedor menos;
    auto j = mas.begin();
    auto i = menos.begin();
    for (auto k : c){
        if(elem > k){
            i = menos.insert(i,k);
            i++;
        }else{
            j = mas.insert(j,k);
            j++;
        }
    }
    return std::make_pair(menos,mas);
};

template <class Contenedor>
void merge(const Contenedor& c1, const Contenedor & c2, Contenedor & res){
    auto k = res.end();
    auto i = c1.begin();
    auto j = c2.begin();

    while (i != c1.end() && j != c2.end()){
        if (*i < *j){
            k = res.insert(k,*i);
            i++;
        }
        else{
            k = res.insert(k,*j);
            j++;
        }
        k++;
    }

    while(i != c1.end()){
        k = res.insert(k,*i);
        i++;
        k++; //como el insert inserta el elemento a la izquierda de donde apunta debemos aumentarlo para insertar el proximo elemento a la derecha del que pusimos
    }

    while(j != c2.end()){
        k = res.insert(k,*j);
        j++;
        k++;
    }
};


#endif //ALGO2_LABO_CLASE5_ALGORITMOS_H
