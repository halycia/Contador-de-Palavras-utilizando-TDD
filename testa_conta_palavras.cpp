
/**
 * \file testa_conta_palavras.cpp
 */

#define CATCH_CONFIG_MAIN
#include "conta_palavras.hpp"
#include "catch.hpp"
#include <fstream>


TEST_CASE("Teste de Abertura de Arquivo", "[arquivo]") {
    std::ifstream arquivo("input.txt");
    REQUIRE(arquivo.is_open());
}

TEST_CASE("Ler conteúdo do arquivo", "[arquivo]") {
    std::vector<std::string> conteudo = lerArquivo("input.txt");

    REQUIRE_FALSE(conteudo.empty());
}

TEST_CASE("Ler palavras do arquivo separadas por somente 1 espaço", "[arquivo]") {
    std::vector<std::string> resultado = lerArquivo("tests_files/test1.txt");

    REQUIRE(resultado.size() == 5);

    REQUIRE(resultado[0] == "Olá");
    REQUIRE(resultado[1] == "mundo");
    REQUIRE(resultado[2] == "e");
    REQUIRE(resultado[3] == "outros");
    REQUIRE(resultado[4] == "lugares.");
}

TEST_CASE("Ler palavras do arquivo separadas por 2 espaços", "[arquivo]") {
    std::vector<std::string> resultado = lerArquivo("tests_files/test2.txt");

    REQUIRE(resultado.size() == 5);

    REQUIRE(resultado[0] == "Olá");
    REQUIRE(resultado[1] == "mundo");
    REQUIRE(resultado[2] == "e");
    REQUIRE(resultado[3] == "outros");
    REQUIRE(resultado[4] == "lugares.");
}

TEST_CASE("Ler palavras do arquivo separadas por 1 espaço e 3 espaços adicionais no início e fim da string", "[arquivo]") {
    std::vector<std::string> resultado = lerArquivo("tests_files/test3.txt");

    REQUIRE(resultado.size() == 5);

    REQUIRE(resultado[0] == "Olá");
    REQUIRE(resultado[1] == "mundo");
    REQUIRE(resultado[2] == "e");
    REQUIRE(resultado[3] == "outros");
    REQUIRE(resultado[4] == "lugares.");
}

TEST_CASE("Ler palavras do arquivo separadas por quebra de linha", "[arquivo]") {
    std::vector<std::string> resultado = lerArquivo("tests_files/test4.txt");

    REQUIRE(resultado.size() == 5);

    REQUIRE(resultado[0] == "Olá");
    REQUIRE(resultado[1] == "mundo");
    REQUIRE(resultado[2] == "e");
    REQUIRE(resultado[3] == "outros");
    REQUIRE(resultado[4] == "lugares.");
}

TEST_CASE("Ler palavras do arquivo separadas por tab", "[arquivo]") {
    std::vector<std::string> resultado = lerArquivo("tests_files/test5.txt");

    REQUIRE(resultado.size() == 5);

    REQUIRE(resultado[0] == "Olá");
    REQUIRE(resultado[1] == "mundo");
    REQUIRE(resultado[2] == "e");
    REQUIRE(resultado[3] == "outros");
    REQUIRE(resultado[4] == "lugares.");
}

TEST_CASE("Contagem de palavras no arquivo", "[contagem]") {
    std::vector<std::string> palavras = lerArquivo("tests_files/test1.txt");
    std::vector<std::pair<std::string, int>> ocorrencias = contarOcorrencias(palavras);

    REQUIRE(ocorrencias.size() == 5);

    REQUIRE(ocorrencias[0].first == "Olá");
    REQUIRE(ocorrencias[0].second == 1);

    REQUIRE(ocorrencias[1].first == "mundo");
    REQUIRE(ocorrencias[1].second == 1);

    REQUIRE(ocorrencias[2].first == "e");
    REQUIRE(ocorrencias[2].second == 1);

    REQUIRE(ocorrencias[3].first == "outros");
    REQUIRE(ocorrencias[3].second == 1);

    REQUIRE(ocorrencias[4].first == "lugares.");
    REQUIRE(ocorrencias[4].second == 1);
}

TEST_CASE("Contagem de palavras e ordenação por letras minúsculas e maiúsculas", "[arquivo]") {
    std::vector<std::string> palavras = lerArquivo("tests_files/test6.txt");
    std::vector<std::pair<std::string, int>> ocorrencias = contarOcorrencias(palavras);
	ordenarPalavras(ocorrencias);

    REQUIRE(ocorrencias[0].first == "e");
    REQUIRE(ocorrencias[1].first == "Este");
    REQUIRE(ocorrencias[2].first == "o");
    REQUIRE(ocorrencias[3].first == "que");
    REQUIRE(ocorrencias[4].first == "sera");
    REQUIRE(ocorrencias[5].first == "texto");
    REQUIRE(ocorrencias[6].first == "utilizado");

    REQUIRE(ocorrencias[0].second == 1);
    REQUIRE(ocorrencias[1].second == 1);
    REQUIRE(ocorrencias[2].second == 1);
    REQUIRE(ocorrencias[3].second == 1);
    REQUIRE(ocorrencias[4].second == 1);
    REQUIRE(ocorrencias[5].second == 2);
    REQUIRE(ocorrencias[6].second == 1);
}

TEST_CASE("Ordenação por letras minúsculas, maiúsculas e tamanho da palavra", "[ordenarPalavras]") {
    std::vector<std::string> palavras = lerArquivo("tests_files/test7.txt");
    std::vector<std::pair<std::string, int>> ocorrencias = contarOcorrencias(palavras);
	ordenarPalavras(ocorrencias);

    REQUIRE(ocorrencias[0].first == "Ba");
    REQUIRE(ocorrencias[1].first == "Ban");
    REQUIRE(ocorrencias[2].first == "Banana");
    REQUIRE(ocorrencias[3].first == "bana");
    REQUIRE(ocorrencias[4].first == "ban");
    REQUIRE(ocorrencias[5].first == "banana");
}