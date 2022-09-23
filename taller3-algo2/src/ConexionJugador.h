#ifndef CONEXIONJUGADOR_H
#define CONEXIONJUGADOR_H

#include "Internet.h"
#include <string>

using namespace std;

class ConexionJugador {
  public:
    ConexionJugador(string ip);
    void enviarMensaje(string mensaje);
    string ip() const;
    void reasignar(string ip);

  private:
    string _ip;

    Internet* _internet = &Internet::internet(); //puntero al tipo Internet, tengo acceso a los metodos y variables privadas de la clase

};

#endif
