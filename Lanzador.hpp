#pragma once
#include "Pelota.hpp"


class Lanzador {
private:
	Pelota** arrPelotas;
	int n;
public:
	Lanzador(void);
	~Lanzador();

	//Métodos
	int getN();
	void agregarPelota(Pelota* objPelota);
	void lanzarPelotas();
};

//Implementar
Lanzador::Lanzador(void) {
	arrPelotas = nullptr;
	n = 0;
}

Lanzador::~Lanzador() {}

//GET
int Lanzador::getN() {
	return n; //retorna el numero de pelotas que tiene el arreglo
}

void Lanzador::agregarPelota(Pelota* objPelota) {
	Pelota** arrtemporal = new Pelota * [n + 1];
	for (int i = 0; i < n; i++) {
		arrtemporal[i] = arrPelotas[i];
	}
	arrtemporal[n] = objPelota; //Agregar al final
	n += 1;

	if (arrPelotas != nullptr) {
		delete[] arrPelotas;
	}
	arrPelotas = arrtemporal;
}

void Lanzador::lanzarPelotas() { //Para cada una de los objetos pelota
	for (int i = 0; i < n; i++) {
		arrPelotas[i]->borrar();
		arrPelotas[i]->mover();
		arrPelotas[i]->dibujar();
	}
}