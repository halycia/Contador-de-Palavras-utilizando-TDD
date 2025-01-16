#include "conta_palavras.hpp"
#include <iostream>
#include <locale.h>

/**
 * @brief função main() do file conta_palavras.cpp 
 **/

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    std::vector<std::string> palavras = lerArquivo("input.txt");

    std::vector<std::pair<std::string, int>> ocorrencias = contarOcorrencias(palavras);

    ordenarPalavras(ocorrencias);

    for (const auto& par : ocorrencias) {
        std::cout << par.first << ": " << par.second << std::endl;
        std::cout.flush();
    }

    return 0;
}