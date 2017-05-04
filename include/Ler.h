#ifndef LER_H
#define LER_H

	#include <vector>
	#include <fstream>
	#include <iostream>
	#include <string>
	#include <cstring>

	#include "Instrucao.h"

	void Ler(std::vector<Instrucao> &v, const char * arquivo);
	void print (std::vector<Instrucao> v);

#endif // LER_H
