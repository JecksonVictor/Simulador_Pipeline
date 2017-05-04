#ifndef INSTRUCAO_H
#define INSTRUCAO_H

	#include <string>
	#include <vector>

	enum Estagio
	{
		IF = 1, // Busca a próxima instrução
		ID, 	// Decodifica a instrução e busca operandos que são registradores;
		EX, 	// Executa a instrução;
		MEM,	// Leitura da memória;
		WB 		// Salva na memória ou no registrador
	};

	struct Instrucao
	{
		//Básico
		size_t index; //número da instrucao. index -1 = indice do vetor
		std::string instrucao; //nome da instrucao (add, sw...)
		std::string registradores[3]; //registradores
	};

#endif // INSTRUCAO_H
