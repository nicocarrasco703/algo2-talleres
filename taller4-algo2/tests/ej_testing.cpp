#include "gtest-1.8.1/gtest.h"
#include "../src/Libreta.h"
#include "../src/Truco.h"
#include <map>
#include <cmath>

using namespace std;

// Ejercicio 4
TEST(Aritmetica, suma) {
    int res = 15 + 7;
    EXPECT_EQ(22,res);
}

// Ejercicio 5
TEST(Aritmetica, potencia){
    float res = pow(10,2);
    EXPECT_EQ(100,res);
}

// Ejercicio 6
TEST(Aritmetica, potencia_general){
    for(float i = -5; i < 5; i++){
        float res = pow(i,2);
        if (i=!0){
            EXPECT_EQ(res, i * i);
        }
    }
}

//Ejercicio 7
TEST(Diccionario, obtener){
    map<int,int> dic;
    dic.insert(make_pair(3,6));
    EXPECT_EQ(dic.at(3),6);
}

//Ejercicio 8
