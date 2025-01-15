
/**
 * \file testa_conta_palavras.cpp
 */

#define CATCH_CONFIG_MAIN
#include "conta_palavras.hpp"
#include "catch.hpp"
#include <fstream>
  


//TEST_CASE( "Testa velha", "[single-file]" ) {
//	int teste1[3][3]= {   { 2, 0, 1 }, 
//	                      { 2, 0, 1 },
//						  { 0, 2, 1 }
//					  };
//    REQUIRE( VerificaVelha(teste1) == 1 );
//
//
//} 
 

TEST_CASE("Teste de Abertura de Arquivo", "[arquivo]") {
    std::ifstream arquivo("input.txt");
    REQUIRE(arquivo.is_open());
}

TEST_CASE("Ler conteúdo do arquivo", "[arquivo]") {
    std::vector<std::string> conteudo = lerArquivo("input.txt");

    REQUIRE_FALSE(conteudo.empty());
}

TEST_CASE("Ler palavras do arquivo", "[arquivo]") {
    std::vector<std::string> resultado = lerArquivo("test.txt");

    REQUIRE(resultado.size() == 5);

    REQUIRE(resultado[0] == "Olá");
    REQUIRE(resultado[1] == "mundo");
    REQUIRE(resultado[2] == "e");
    REQUIRE(resultado[3] == "outros");
    REQUIRE(resultado[4] == "lugares");
}