#pragma once

#include <iostream>

using namespace System;
using namespace std;

class Pelota {
private:
	int x;
	int y;
	int dx;
	int dy;
	char forma;
public:
	Pelota(void);
	~Pelota();

	//Métodos:
	void borrar();
	void mover();
	void dibujar();
};
//Implementación
Pelota::Pelota(void) {
	//Valores fijos
	x = 39; //x = 2;
	y = 25; //y = 20;
	dx = 1;
	dy = 1;
	forma = 79; //O
}

Pelota::~Pelota() {}

void Pelota::borrar() {
	Console::SetCursorPosition(x, y);
	cout << " ";
}
void Pelota::mover() {
	//Restricciones
	if (x > 78 || x < 2) {
		dx *= -1;
	}
	if (y > 38 || y < 2) {
		dy *= -1;
	}

	x += dx;
	y += dy;
}

void Pelota::dibujar() {
	Console::SetCursorPosition(x, y);
	cout << char(forma);
}