#include <vector>
#include <set>
#include <utility>
#include "algobot.h"
#include <iostream>

using namespace std;

// Ejercicio 1
bool pertenece(int x , vector<int> v){
    bool res = false;
    for(int i = 0; i < v.size() && !res; i++){
        if (x == v[i]){
            res = true;
        }
    }
    return res;
}

vector<int> quitar_repetidos(vector<int> s) {
    vector<int> res = {};
    for(int i = 0; i < s.size(); i++){
        if (!pertenece(s[i], res)) {
            res.push_back(s[i]);
        }
    }
    return res;
}

// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {
    set<int> c;
    for(int n : s){
        c.insert(n);
    }
    return vector<int>(c.begin(),c.end());
}

// Ejercicio 3
bool mismos_elementos(vector<int> a, vector<int> b) {
    bool res = true;
    for (int i = 0; i < a.size() && res; i++){
        if (!pertenece(a[i],b)){
            res = false;
        }
    }
    return res;
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    set<int> s;
    set<int> c;
    for(int i = 0 ; i < a.size(); i++){
        s.insert(a[i]);
    }
    for(int k = 0; k < b.size(); k++){
        c.insert(b[k]);
    }
    return (s == c);
}

// Ejercicio 5
map<int, int> contar_apariciones(vector<int> s) {
    map<int,int> res;
    for (int i = 0; i < s.size(); i++){
        int k = count(s.begin(),s.end(), s[i]);
        res[s[i]] = k;
    }
    return res;
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {
    vector<int> res = {};
    for (int i = 0; i < s.size(); i++){
        int k = count(s.begin(),s.end(), s[i]);
        if (k == 1){
            res.push_back(s[i]);
        }
    }
    return res;
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    set<int> res;
    for(int i : a){
        bool r = count(a.begin(),a.end(),i) == count(b.begin(),b.end(),i);
        if (r){
            res.insert(i);
        }
    }
    return res;
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    map<int, set<int>> res;
    for(int n : s){
        res[n % 10].insert(n);
    }
    return res;
}

// Ejercicio 9
/*vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    vector<char> res = {};
    for (char n : str){
        if(tr.size() == 0){
            res.push_back(n);
        } else {
            for (int i = 0; i < tr.size(); i++) {
                if (n == get<0>(tr[i])) {
                    res.push_back(get<1>(tr[i]));
                } else {
                    res.push_back(n);
                }
            }
        }
    }
    return res;
}*/

vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    map<char, char> trmap;
    for (pair<char, char> t: tr) {
        trmap[t.first] = t.second;
    }
    vector<char> res;
    for (char s: str) {
        res.push_back(trmap.count(s) > 0 ? trmap[s] : s);
    }
    return res;
}

// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s){
    bool res = false;
    for (Mail m1 : s){
        for (Mail m2 : s){
            if (m1.libretas() != m2.libretas()){
                for (LU lib : m1.libretas()){
                    if (m2.libretas().count(lib) > 0){
                        return true;
                    }
                }
            }
        }
    }
    return res;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
    map<set<LU>, Mail> res;
    for(Mail m : s){
        if(m.adjunto()){
            for()
        }
    }
}
