#include "Instrucao.h"
#include "Ler.h"
#include "Dependencias.h"

int main(int argc, char const *argv[])
{
	// Cria coleção de instruções 
	std::vector<Instrucao> v;
	if (argc > 1){
		Ler(v, argv[1]);
		print(v);
	} else {
		std::cout << "Especifique o arquivo de entrada!" << std::endl;
	}

	// Tabela de Dependencias
	std::vector< par > dep;
	Dependencias(v, dep);

	// Simulador
	//Sim_Pipeline(v, dep);

	return 0;
}