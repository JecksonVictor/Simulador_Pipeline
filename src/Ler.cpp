#include <Ler.h>

void Ler (std::vector<Instrucao> &v, const char * arquivo){
	char pasta[] = "data/";
	strcat(pasta, arquivo);

	std::ifstream _arquivo;
	_arquivo.open(pasta);
	if (_arquivo.is_open() == false){
		std::cout << "Arquivo não encontrado!" << std::endl;
		return;
	}

	char c;
	size_t _index = 1;
	while(!_arquivo.eof()) { 
		_arquivo.get(c);

		// Se c for um número:
		if (48 < c && c < 58){
			Instrucao i;

			// Recebe seu número de instrucao
			i.index = _index;
				_index++;

			// Remove o ponto e espaço
			_arquivo.get(c);
			_arquivo.get(c);

			// Lê o nome da instrucao
			_arquivo.get(c);
			do{
				i.instrucao += c;
				_arquivo.get(c);
			} while(c != ' ');

			// Agora verifica as dependencias de cada instrução
			// Se add ou sub
			if (
				(strcmp(i.instrucao.c_str(), "add") == 0) ||
				(strcmp(i.instrucao.c_str(), "sub") == 0)
			){
				for (size_t j = 0; j < 3; ++j)
				{
					for (size_t k = 0; k < 3; ++k)
					{
						_arquivo.get(c);
						i.registradores[j] += c;
					}

					//Remove virgula ou \n
					_arquivo.get(c);
					//Remove ' '
					if (j != 2)
						_arquivo.get(c);

				}
				v.push_back(i);
			} else

			if (
				(strcmp(i.instrucao.c_str(), "beq") == 0) ||
				(strcmp(i.instrucao.c_str(), "bne") == 0)
			) {
				for (size_t j = 0; j < 2; ++j)
				{
					for (size_t k = 0; k < 3; ++k)
					{
						_arquivo.get(c);
						i.registradores[j] += c;
					}

					// Remove ',' e ' '
					_arquivo.get(c);
					_arquivo.get(c);
				}
				// Lê o número da instrucao
				_arquivo.get(c);
				while (c != '\n') {
				    i.registradores[2] += c;
				    _arquivo.get(c);
				}

				v.push_back(i);
			} else
			// Se sw ou lw:
			if (
				(strcmp(i.instrucao.c_str(), "sw") == 0) ||
				(strcmp(i.instrucao.c_str(), "lw") == 0)
			) {
				// Le o primeiro registrador
				for (size_t j = 0; j < 3; ++j){
					_arquivo.get(c);
					i.registradores[0] += c;
				}

				// Remove ',' e ' '
				_arquivo.get(c);
				_arquivo.get(c);

				// Le o valor
				_arquivo.get(c);
				while (c != '(') {
				    i.registradores[1] += c;
				    _arquivo.get(c);
				}

				// Le o segundo registrador
				for (size_t k = 0; k < 3; ++k){
					_arquivo.get(c);
					i.registradores[2] += c;
				}

				// Remove ')' e '\n'
				_arquivo.get(c);
				_arquivo.get(c);

				v.push_back(i);

			} else
			// Se jump
			if ((strcmp(i.instrucao.c_str(), "j") == 0))
			{
				// Le numero da instrucao
				_arquivo.get(c);
				while(c != '\n') {
				    i.registradores[0] += c;
				    _arquivo.get(c);
				}
				i.registradores[1] = ' ';
				i.registradores[2] = ' ';

				v.push_back(i);

			} else {
				std::cout << "Houve algum erro na leitura das instruções!" << std::endl;
			}
		}
	}
}

void print (std::vector<Instrucao> v){
	for (int i = 0; i < v.size(); ++i)
	{
		std::cout << v[i].index << '.' << ' ' << v[i].instrucao << ' ';
		for (int j = 0; j < 3; ++j)
		{
			std::cout << v[i].registradores[j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}