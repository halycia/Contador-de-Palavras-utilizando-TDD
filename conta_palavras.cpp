/**
 * \file  conta_palavras.cpp
 */

#include "conta_palavras.hpp"
#include <iostream>
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
std::vector<std::string> lerArquivo(const std::string &nomeArquivo)
{
	std::ifstream arquivo(nomeArquivo);
	std::vector<std::string> palavras;
	std::string linha, palavra;

	if (arquivo.is_open())
	{
		while (std::getline(arquivo, linha))
		{
			std::istringstream stream(linha);
			while (stream >> palavra)
			{
				palavras.push_back(palavra);
			}
		}
		arquivo.close();
	}

	return palavras;
}

/**
 * @brief Conta a quantidade de ocorrências de cada palavra em um vetor de palavras.
 *
 * @param palavras [const std::vector<std::string>&] - Vetor contendo as palavras a serem analisadas.
 *
 * @return Retorna um vetor de pares, onde cada par contém uma palavra e a quantidade de vezes que ela apareceu.
 *
 * @note
 * ### Assertivas de Entrada:
 *  - O vetor de palavras deve ser composto apenas por strings não vazias.
 *  - A função diferencia entre maiúsculas e minúsculas (ex: "Palavra" e "palavra" são tratadas como palavras distintas).
 *
 * ### Assertivas de Saída:
 *  - A função retorna um vetor de pares (palavra, quantidade), onde cada palavra é única e a quantidade corresponde ao número de vezes que ela apareceu no vetor de entrada.
 *  - Se o vetor de palavras estiver vazio, a função retorna um vetor vazio.
 */
std::vector<std::pair<std::string, int>> contarOcorrencias(const std::vector<std::string> &palavras)
{
	std::vector<std::pair<std::string, int>> ocorrencias;

	for (const auto &palavra : palavras)
	{
		auto it = std::find_if(ocorrencias.begin(), ocorrencias.end(),
							   [&palavra](const std::pair<std::string, int> &p)
							   {
								   return p.first == palavra;
							   });

		if (it != ocorrencias.end())
		{
			it->second++;
		}
		else
		{
			ocorrencias.push_back({palavra, 1});
		}
	}

	return ocorrencias;
}

/**
 * @brief Ordena um vetor de pares palavra-contagem de acordo com a ordem alfabética, começando pelas letras acentuadas, 
 * depois minúsculas, depois suas correspondentes maiúsculas e por fim, o tamanho da palavra, priorizando palavras menores.
 *
 * @param ocorrencias [std::vector<std::pair<std::string, int>>&] - Vetor contendo as palavras e as contagens a serem ordenadas.
 *
 * @note
 * ### Assertivas de Entrada:
 *  - O vetor de pares deve conter palavras compostas por caracteres presentes na string `ordem`.
 *  - A string `ordem` define a ordem desejada das letras, considerando que a ordem de prioridade é letras acentuadas,
 * 	minúsculas, maiúsculas e, por fim, tamanho da palavra.
 *
 * ### Assertivas de Saída:
 *  - A função retorna um vetor ordenado de pares (palavra, contagem), onde as palavras são ordenadas conforme a string `ordem`.
 *  - Se o vetor de pares estiver vazio, a função retorna um vetor vazio.
 */
void ordenarPalavras(std::vector<std::pair<std::string, int>>& ocorrencias) {
    std::string ordem = "áàâãaÁÀÂÃAbBçcÇCdDéêeÉÊEfFgGhHíiÍIjJkKlLmMnNóôõoÓÔÕOpPqQrRsStTúuÚUvVwWxXyYzZ";

    auto comparador = [&ordem](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
        size_t i = 0;
        while (i < a.first.size() && i < b.first.size()) {
            size_t posA = ordem.find(a.first[i]);
            size_t posB = ordem.find(b.first[i]);

            if (posA != posB) {
                return posA < posB;
            }
            i++;
        }

        return a.first.size() < b.first.size();
    };

    std::sort(ocorrencias.begin(), ocorrencias.end(), comparador);
}

