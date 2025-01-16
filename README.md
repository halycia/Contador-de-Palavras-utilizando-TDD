**Objetivo**:
Este projeto tem como objetivo contar as palavras diferentes de um arquivo texto, diferenciando maiúsculas e minúsculas, e listar as palavras com o número de ocorrências em ordem alfabética. O projeto deve ser desenvolvido utilizando TDD (Test-Driven Development), em C++, com o uso de testes utilizando o Catch framework. A cada passo de desenvolvimento, o código deve ser verificado e revisado de acordo com as especificações fornecidas.

**Estrutura do Programa**:
- O código será dividido em módulos:
  - `main.cpp` (permite separar a lógica do programa da execução e dos testes)
  - `conta_palavras.cpp` (implementação da contagem de palavras)
  - `conta_palavras.hpp` (declarações da função de contagem de palavras)
  - `testa_conta_palavras.cpp` (testes para verificar a funcionalidade)
  - `Makefile` (para compilar o código)
  - `input.txt` (arquivo de entrada)
  - `script_doxygen.py` (para rodar o Doxygen e gerar documentação)

**Compilação**:
Para compilar o programa, use o comando `make`. O Makefile foi configurado para compilar o projeto corretamente.

**Comandos Importantes (Windows)**:
Para compilar e executar apenas o programa principal (sem os testes):
`make main`
Para compilar e executar o programa junto com os testes:
`make all`
Para rodar o Doxygen e gerar a documentação:
`make javadoc`
Para rodar apenas os testes:
`make test`
Para limpar os arquivos gerados:
`make clean`

**Especificação**:
- O arquivo de entrada deve conter palavras separadas por espaços ou quebras de linha. As palavras não devem ser normalizadas para minúsculas, conforme a especificação.
- A saída deve ser no formato `palavra: quantidade`, onde `palavra` é a palavra encontrada e `quantidade` é o número de ocorrências.

**Processo de Desenvolvimento**:
O desenvolvimento deve seguir a metodologia TDD, com os seguintes passos:
1. Escrever um teste que falha.
2. Implementar o código necessário para passar o teste.
3. Refatorar o código, se necessário.
4. Realizar um commit para cada mudança significativa.

**Javadoc**:
Para documentar os códigos dos arquivos main.cpp e conta_palavras.cpp, será utilizado o estilo de comentários Javadoc. Estes comentários são usados para gerar documentação automática através do Doxygen. Cada função no código deve ser precedida por um comentário no estilo Javadoc, contendo:
- Uma breve descrição da função
- Descrição dos parâmetros, se houver
- Descrição do valor de retorno, se houver

**Testes**:
Os testes devem ser escritos no arquivo `testa_conta_palavras.cpp` e devem ser desenvolvidos utilizando o framework Catch versão v1.12.1. A cada novo teste, um commit deve ser realizado. Os testes devem cobrir:
- Contagem de palavras em um arquivo com separação por espaços e quebras de linha.
- Diferença entre maiúsculas e minúsculas.
- Ordenação das palavras por ordem alfabética.
