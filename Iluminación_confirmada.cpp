#include "pch.h"
#include "Lanzador.hpp"
#include <conio.h>

using namespace System;

int main() {
    Console::SetWindowSize(80, 40);
    Console::CursorVisible = false;

    //crear el objeto lanzador
    Lanzador* objLanzador = new Lanzador();

    //puntero Pelota
    Pelota* objPelota;
    
    //Dibujar el lanzador
    Console::SetCursorPosition(39, 25); //Console::SetCursorPosition(39 , 25);
    //Cambiar el color
    Console::ForegroundColor = ConsoleColor::Red;
    cout << "#>";
    Console::ForegroundColor = ConsoleColor::White;

    while (true) {
        //agregar pelotas
        if (kbhit()) {
            char tecla = getch(); //Capturar la tecla presionada
            if (toupper(tecla) == 'L') {
                //Crear una instancia de pelota
                objPelota = new Pelota();
                //Agregar al arreglo de pelotas
                objLanzador->agregarPelota(objPelota);
            }
        }
        //validar si hay pelotas en el arreglo, entonces las lanzo
        if (objLanzador->getN() > 0) {
            //Lanza las pelotas
            objLanzador->lanzarPelotas();
        }

        _sleep(100); //retardo;
    }

    return 0;
}
