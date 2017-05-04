#include "Dependencias.h"

// Recebe as instruções e mostra suas dependencias
// A primeira instrução não depende de ninguém, portanto i=1
void Dependencias(std::vector<Instrucao> v, std::vector< par > &_dep){

	for (size_t i = 1; i < v.size(); ++i)
	{
		for (size_t j = 0; j < i; ++j)
		{
			for (size_t k = 0; k < 3; ++k){
				if ((v[i].registradores[k] == v[j].registradores[0]) ||
					(v[i].registradores[k] == v[j].registradores[1]) ||
					(v[i].registradores[k] == v[j].registradores[2]) )
				{
					par _p;
					_p.x = i+1;
					_p.y = j+1;
					_dep.push_back(_p);
					std::cout << "A instrução " << i+1 << " depende da instrução " << j+1 << std::endl;
				}
			}
		}
	}
}