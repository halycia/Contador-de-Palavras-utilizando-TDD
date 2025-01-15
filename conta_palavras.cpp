/**
 * \file  conta_palavras.cpp
 */

 
#include "conta_palavras.hpp"
#include <fstream>
#include <vector>
#include <string>

/**
 * @brief ler o conteúdo do arquivo input.txt
 *
 * @param nomeArquivo [const std::string& - somente arquivo .txt]

 * @return retorna o vetor linhas com cada linha lida. Se não for aberto, o programa não faz nada e retorna o vetor vazio.
 *
 * @note
 * ### Assertivas de Entrada:
 *  - arquivo .txt
 *
 * ### Assertivas de Saída:
 *  - retorna o vetor linhas com cada linha lida. Se não for aberto, o programa não faz nada e retorna o vetor vazio.
 */
std::vector<std::string> lerArquivo(const std::string& nomeArquivo) {
	std::ifstream arquivo(nomeArquivo);
    std::vector<std::string> linhas;
    std::string linha;

    if (arquivo.is_open()) {
        while (std::getline(arquivo, linha)) {
            linhas.push_back(linha);
        }
        arquivo.close();
    }

    return linhas;
	}

