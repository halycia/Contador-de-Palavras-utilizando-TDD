/**
 * \file  conta_palavras.cpp
 */

 
#include "conta_palavras.hpp"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

/**
 * @brief lê o conteúdo do arquivo .txt, separa por espaço e armazena suas palavras em um vetor.
 *
 * @param nomeArquivo [const std::string&] - nome do arquivo .txt a ser lido

 * @return retorna o vetor linhas com cada linha lida. Se não for aberto, o programa não faz nada e retorna o vetor vazio.
 *
 * @note
 * ### Assertivas de Entrada:
 *  - deve ser um arquivo .txt
 *
 * ### Assertivas de Saída:
 *  - Retorna um vetor com as palavras extraídas do arquivo.
 *  - Se o arquivo não for aberto corretamente, o programa não faz nada e retorna o vetor vazio.
 */
std::vector<std::string> lerArquivo(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);
    std::vector<std::string> palavras;
    std::string linha, palavra;

    if (arquivo.is_open()) {
        while (std::getline(arquivo, linha)) {
            std::istringstream stream(linha);
            while (stream >> palavra) {
                palavras.push_back(palavra);
            }
        }
        arquivo.close();
    }

    return palavras;
}

std::vector<std::pair<std::string, int>> contarOcorrencias(const std::vector<std::string>& palavras) {
	std::vector<std::pair<std::string, int>> ocorrencias;

		for (const auto& palavra : palavras) {
			auto it = std::find_if(ocorrencias.begin(), ocorrencias.end(),
				[&palavra](const std::pair<std::string, int>& p) {
					return p.first == palavra;
				});

			if (it != ocorrencias.end()) {
				it->second++;
			} else {
				ocorrencias.push_back({palavra, 1});
			}
		}

		return ocorrencias;
}