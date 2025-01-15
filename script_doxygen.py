import re

# Caminho do arquivo C++ a ser documentado
arquivo_cpp = 'conta_palavras.cpp'

# Modelo de comentário Javadoc
template_doc = """
/**
 * @brief [DESCREVA AQUI O PROPÓSITO DA FUNÇÃO]
 *
{parametros}
 * @return [DESCREVA O RETORNO DA FUNÇÃO]
 *
 * @note
 * ### Assertivas de Entrada:
 *  - [DESCREVA AS CONDIÇÕES DE ENTRADA]
 *
 * ### Assertivas de Saída:
 *  - [DESCREVA AS GARANTIAS DE SAÍDA]
 */
"""

# Função para gerar documentação com base nos parâmetros
def gerar_documentacao(func_match):
    assinatura = func_match.group(0)
    nome_funcao = func_match.group(2)
    parametros_brutos = func_match.group(3)
    parametros = parametros_brutos.split(',') if parametros_brutos.strip() else []

    # Monta a parte dos parâmetros no template
    doc_parametros = ''
    for param in parametros:
        param = param.strip()
        if param:
            tipo, nome = param.rsplit(' ', 1)
            doc_parametros += f" * @param {nome} [{tipo} - DESCREVA O PARÂMETRO]\n"
    if not doc_parametros:
        doc_parametros = " * @param [SEM PARÂMETROS]\n"

    # Insere a documentação antes da função
    return template_doc.format(parametros=doc_parametros) + assinatura

# Expressão regular para encontrar funções
padrao_funcao = re.compile(r'(\w[\w\s\*&:<>,]*)\s+(\w+)\s*\(([^)]*)\)\s*\{')

# Lê o arquivo C++
with open(arquivo_cpp, 'r+', encoding='utf-8') as f:
    conteudo = f.read()

    # Divida o conteúdo em linhas
    linhas = conteudo.splitlines()

    # Verifica se a função já tem comentário Doxygen na linha anterior
    def adicionar_documentacao(func_match):
        assinatura = func_match.group(0)
        func_inicio = func_match.start()

        # Encontre a linha onde a função começa
        linha_func = conteudo.count('\n', 0, func_inicio)  # Número da linha onde a função começa
        linha_anterior = linhas[linha_func - 1] if linha_func > 0 else ""

        # Verifica se a linha anterior contém o final de um comentário Doxygen
        if "*/" in linha_anterior:
            return assinatura  # Se já houver, não adiciona a documentação

        # Caso contrário, gera a documentação
        return gerar_documentacao(func_match)

    # Adiciona a documentação apenas se a função não tiver documentação Doxygen
    documentado = padrao_funcao.sub(adicionar_documentacao, conteudo)
    
    # Volta ao início do arquivo e sobrescreve
    f.seek(0)
    f.write(documentado)
    f.truncate()

print("Documentação adicionada no arquivo conta_palavras.cpp")
