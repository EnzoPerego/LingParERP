# LingParERP - Linguagem de Programação para MicrowaveVM

## Visão Geral

**LingParERP** é uma linguagem de programação de alto nível desenvolvida como parte da Atividade Prática Supervisionada da disciplina de Linguagens de Programação. A linguagem foi projetada para controlar um microondas virtual através da **MicrowaveVM**, uma máquina virtual minimalista e Turing-completa.

**Características da Linguagem:**
- **Target**: MicrowaveVM (Máquina Virtual de Microondas)
- **Estilo**: Baseado em C com palavras-chave em inglês
- **Tipos de dados**: Apenas números inteiros
- **Foco**: Simplicidade e clareza
- **Aplicação**: Ligar, desligar, definir tempo e potência do microondas

## Arquitetura

### Como funciona?

A linguagem funciona com uma máquina virtual que simula um microondas real. O processo completo envolve:

1. **Análise Léxica (Flex)**: Reconhece tokens do código fonte
2. **Análise Sintática (Bison)**: Valida a gramática do programa
3. **Geração de Código**: Converte para assembly da MicrowaveVM
4. **Execução na VM**: Executa o código na máquina virtual

### MicrowaveVM

A **MicrowaveVM** possui:

- **Registradores de controle**: `TIME` (tempo) e `POWER` (potência)
- **Registradores de simulação**: `TEMP` (temperatura) e `WEIGHT` (peso)
- **Instruções básicas**: 
  - `SET R n` - Define valor no registrador
  - `INC R` - Incrementa registrador
  - `DECJZ R label` - Decrementa e pula se zero
  - `GOTO label` - Salto incondicional
  - `PRINT` - Imprime valor do TIME
  - `PUSH R` / `POP R` - Operações de pilha
  - `HALT` - Para execução

## Gramática da Linguagem (EBNF)

### Tokens (Símbolos Terminais)

```
IDENTIFIER = [a-zA-Z_][a-zA-Z0-9_]*
NUMBER = [0-9]+
OPERATOR = \+ | \- | \* | \/ | == | != | < | > | <= | >= | =
PUNCTUATION = \( | \) | \{ | \} | ;
KEYWORD = program | end | var | if | else | while | print
```

### Regras de Produção (Símbolos Não-Terminais)

```
<program> ::= program IDENTIFIER <block> end
<block> ::= { <statement> }
<statement> ::= <declaration> | <assignment> | <conditional> | <loop> | <print>
<declaration> ::= var IDENTIFIER [= <expression>] ;
<assignment> ::= IDENTIFIER = <expression> ;
<conditional> ::= if ( <expression> ) <block> [else <block>]
<loop> ::= while ( <expression> ) <block>
<print> ::= print <expression> ;
<expression> ::= <term> { (+ | -) <term> }
<term> ::= <factor> { (* | /) <factor> }
<factor> ::= IDENTIFIER | NUMBER | STRING | ( <expression> )
```

## Como Usar

### Pré-requisitos

- **Flex**: Analisador léxico (`flex`)
- **Bison**: Analisador sintático (`bison`)
- **GCC**: Compilador C (`gcc`)
- **Python 3**: Para executar a MicrowaveVM

### Instalação

1. Clone o repositório:
```bash
git clone <seu-repositorio>
cd LingParERP
```

2. A MicrowaveVM já está incluída no diretório `MicrowaveVM/`

### Compilação

```bash
# Compilar o parser (Flex + Bison)
make

# Compilar o gerador de código
gcc -o codegen codegen.c
```

### Execução

#### 1. Análise Sintática

```bash
# Verificar se o programa está sintaticamente correto
./parser < teste.microondas
```

#### 2. Geração de Código Assembly

```bash
# Gerar código assembly para MicrowaveVM
./codegen teste.microondas output.mwasm
```

#### 3. Execução na VM

```bash
# Executar na MicrowaveVM
python3 MicrowaveVM/main.py output.mwasm
```

### Exemplo Completo

```bash
# 1. Analisar sintaticamente
./parser < teste.microondas

# 2. Gerar assembly
./codegen teste.microondas output.mwasm

# 3. Executar na VM
python3 MicrowaveVM/main.py output.mwasm
```

**Saída esperada:**
```
=== Parser LingParERP ===
Analisando programa...

Declaração de variável válida
Declaração de variável válida
Comando print válido
Programa válido!

Programa válido! Análise sintática concluída com sucesso.

Gerando código assembly para MicrowaveVM...
Código gerado com sucesso em output.mwasm

Loaded program from: output.mwasm
TIME: 1
TIME: 30
TIME: 70
TIME: 1
BEEEEEEP!
Final state: {'TIME': 1, 'POWER': 70}
```

## Exemplos de Programas

### Exemplo 1: Variáveis

```lingpar
program exemplo_variaveis
{
    var tempo = 60;
    var potencia = 80;
    
    print "Tempo configurado: " + tempo;
    print "Potência configurada: " + potencia;
}
end
```

### Exemplo 2: Condicionais

```lingpar
program exemplo_condicional
{
    var potencia = 70;
    
    if (potencia > 50) {
        print "Potência alta selecionada";
    } else {
        print "Potência baixa selecionada";
    }
}
end
```

### Exemplo 3: Loops

```lingpar
program exemplo_loop
{
    var tempo = 5;
    
    while (tempo > 0) {
        print "Tempo restante: " + tempo;
        tempo = tempo - 1;
    }
    
    print "Tempo esgotado!";
}
end
```

### Exemplo 4: Programa Completo

```lingpar
program microondas
{
    var tempo = 30;
    var potencia = 70;
    
    print "Ligando microondas...";
    print "Tempo: " + tempo + " segundos";
    print "Potência: " + potencia + "%";
    print "Microondas ligado!";
}
end
```

## Estrutura do Projeto

```
LingParERP/
├── README.md                    # Este arquivo
├── TESTES.md                    # Documentação de testes
├── Makefile                     # Script de compilação
│
├── Análise Léxica e Sintática
│   ├── lingpar_flex.l           # Analisador léxico (Flex)
│   ├── lingpar_simples.y        # Analisador sintático (Bison)
│   ├── lex.yy.c                 # Código C gerado pelo Flex
│   ├── lingpar_simples.tab.c    # Código C gerado pelo Bison
│   └── lingpar_simples.tab.h    # Header gerado pelo Bison
│
├── Geração de Código
│   ├── codegen.c                # Gerador de código para MicrowaveVM
│   └── codegen                   # Executável do gerador
│
├── Exemplos de Teste
│   ├── teste.microondas         # Programa principal de teste
│   ├── exemplo1_variaveis.microondas
│   ├── exemplo2_condicional.microondas
│   └── exemplo3_loop.microondas
│
└── MicrowaveVM/                 # Máquina Virtual (clonada)
    ├── main.py                  # Executável da VM
    ├── examples/                # Exemplos de assembly
    └── README.md                # Documentação da VM
```

## Testes

Consulte o arquivo `TESTES.md` para exemplos completos de teste e instruções detalhadas.

### Executar Suite de Testes

```bash
# Teste 1: Variáveis
./parser < exemplo1_variaveis.microondas
./codegen exemplo1_variaveis.microondas ex1.mwasm
python3 MicrowaveVM/main.py ex1.mwasm

# Teste 2: Condicionais
./parser < exemplo2_condicional.microondas
./codegen exemplo2_condicional.microondas ex2.mwasm
python3 MicrowaveVM/main.py ex2.mwasm

# Teste 3: Loops
./parser < exemplo3_loop.microondas
./codegen exemplo3_loop.microondas ex3.mwasm
python3 MicrowaveVM/main.py ex3.mwasm
```

## Características Implementadas

- **Variáveis**: Declaração e inicialização
- **Condicionais**: Estruturas if-else
- **Loops**: Estrutura while
- **Expressões**: Aritméticas e de comparação
- **Print**: Comando de saída
- **Análise Léxica**: Flex implementado
- **Análise Sintática**: Bison implementado
- **Geração de Código**: Conversão para MicrowaveVM assembly
- **Execução na VM**: Integração com MicrowaveVM

## Referências

- **MicrowaveVM**: https://github.com/raulikeda/MicrowaveVM
- **Flex**: https://github.com/westes/flex
- **Bison**: https://www.gnu.org/software/bison/

## Licença

Este projeto foi desenvolvido para fins educacionais como parte da APS de Linguagens de Programação.

## Autor

Desenvolvido como parte da Atividade Prática Supervisionada - Linguagens de Programação.

---

**Status do Projeto**: Completo e funcional