#include "Proxy2.h"

Proxy::Proxy(ConexionJugador **conn) : _conn(conn) {}

void Proxy::enviarMensaje(string msg) {
    _conne = *_conn;
    _conne->enviarMensaje(msg);
}