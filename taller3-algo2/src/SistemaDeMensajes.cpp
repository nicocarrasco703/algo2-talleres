#include "SistemaDeMensajes.h"

using namespace std;

SistemaDeMensajes::SistemaDeMensajes() : _conns()  {
    for(int i = 0; i < 4; i++){
        _conns[i] = nullptr;
    }
}

void SistemaDeMensajes::registrarJugador(int id, string ip) {
    if(_conns[id] == nullptr){
        _conns[id] = new ConexionJugador(ip);
    } else {
        _conns[id] -> reasignar(ip); //llamo al metodo reasignar para asignar la nueva ip (variable privada del tipo) en la conexión id
    }
}

void SistemaDeMensajes::enviarMensaje(int id, string mensaje) {
    _conns[id]->enviarMensaje(mensaje);
}

bool SistemaDeMensajes::registrado(int id) const {
    return (_conns[id] != nullptr);
}

string SistemaDeMensajes::ipJugador(int id) const {
    return _conns[id]->ip();
}

void SistemaDeMensajes::desregistrarJugador(int id) {
    delete _conns[id];
    _conns[id] = nullptr;
}

/*Proxy* SistemaDeMensajes::obtenerProxy(int id) {
    Proxy* p = new Proxy(_conns[id]);
    _proxys.push_back(p);
    return p;
}*/

Proxy* SistemaDeMensajes::obtenerProxy(int id) {
    Proxy* p = new Proxy(&_conns[id]);
    _proxys.push_back(p);
    return p;
}

SistemaDeMensajes::~SistemaDeMensajes() {
    for(int i = 0; i < 4; i++){
        delete _conns[i];
    }
    for(Proxy* p : _proxys){
        delete p;
    }
}