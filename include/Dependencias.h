#ifndef DEPENDENCIAS_H
#define DEPENDENCIAS_H

	#include "Instrucao.h"

	#include <vector>
	#include <iostream>

	struct par
	{
		size_t x;
		size_t y;	
	};

	void Dependencias(std::vector<Instrucao> v, std::vector< par > &_dep);

#endif // DEPENDENCIAS_H