#ifndef CONTA_PALAVRAS_HPP
#define CONTA_PALAVRAS_HPP

#include <vector>
#include <string>
#include <utility>

std::vector<std::string> lerArquivo(const std::string& nomeArquivo);

std::vector<std::pair<std::string, int>> contarOcorrencias(const std::vector<std::string>& palavras);

#endif
