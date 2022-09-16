#include <iostream>

using namespace std;

using uint = unsigned int;

// Ejercicio 1

class Rectangulo {
    public:
        Rectangulo(uint alto, uint ancho);
        uint alto();
        uint ancho();
        float area();

    private:
        int _alto;
        int _ancho;

};

Rectangulo::Rectangulo(uint alto, uint ancho) : _ancho(ancho), _alto(alto) {};

uint Rectangulo::alto() {
    return _alto;
}

uint Rectangulo::ancho() {
    return _ancho;
}

float Rectangulo::area() {
    float res = _alto * _ancho;
    return res;
}

// Ejercicio 2

// Clase Elipse

// Ejercicio 3

class Cuadrado {
    public:
        Cuadrado(uint lado);
        uint lado();
        float area();

    private:
        Rectangulo _r;
};

Cuadrado::Cuadrado(uint lado): _r(lado, lado) {}

uint Cuadrado::lado() {
    // Completar
    return 0;
}

float Cuadrado::area() {
    // Completar
    return 0;
}

// Ejercicio 4

// Clase Circulo


// Ejercicio 5

ostream& operator<<(ostream& os, Rectangulo r) {
    os << "Rect(" << r.ancho() << ", " << r.alto() << ")";
    return os;
}

// ostream Elipse

// Ejercicio 6

