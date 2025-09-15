# LingParERP - Linguagem de Programação

## Visão Geral

Esta especificação define a gramática formal da linguagem de programação LingParERP, desenvolvida como parte da Atividade Prática Supervisionada da disciplina de Linguagens de Programação.

**Características da Linguagem:**
- Target: MicrowaveVM
- Estilo: Baseado em C com palavras-chave em inglês
- Tipos de dados: Apenas números inteiros
- Foco: Simplicidade e clareza

## Definição da Gramática EBNF

### Tokens (Símbolos Terminais)

A linguagem LingParERP reconhece os seguintes tokens:

```
IDENTIFIER = [a-zA-Z_][a-zA-Z0-9_]*
NUMBER = [0-9]+
OPERATOR = \+ | \- | \* | \/ | == | != | < | > | =
PUNCTUATION = \( | \) | \{ | \} | ;
KEYWORD = program | end | var | if | else | while | print
```

### Regras de Produção (Símbolos Não-Terminais)

A gramática da linguagem é definida pelas seguintes regras:

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
<factor> ::= IDENTIFIER | NUMBER | ( <expression> )
```

## Análise das Regras de Produção

### Estrutura do Programa

A regra `<program>` define que todo programa LingParERP deve seguir a estrutura:
```
<program> ::= program IDENTIFIER <block> end
```

Esta regra estabelece que um programa válido deve:
- Iniciar com a palavra-chave `program` seguida de um identificador (nome do programa)
- Conter um bloco de comandos
- Terminar com a palavra-chave `end`

### Blocos de Comandos

A regra `<block>` permite a definição de blocos de comandos:
```
<block> ::= { <statement> }
```

A notação `{ }` indica que um bloco pode conter zero ou mais comandos, permitindo blocos vazios ou com múltiplos comandos.

### Tipos de Comandos

A linguagem suporta cinco tipos de comandos:
```
<statement> ::= <declaration> | <assignment> | <conditional> | <loop> | <print>
```

### Declaração de Variáveis

As variáveis são declaradas usando a regra:
```
<declaration> ::= var IDENTIFIER [= <expression>] ;
```

A notação `[ ]` indica que a inicialização é opcional, permitindo declarações como `var x;` ou `var x = 10;`.

### Estruturas de Controle

**Condicionais:**
```
<conditional> ::= if ( <expression> ) <block> [else <block>]
```

**Loops:**
```
<loop> ::= while ( <expression> ) <block>
```

### Expressões Aritméticas

As expressões seguem a hierarquia de precedência tradicional:
```
<expression> ::= <term> { (+ | -) <term> }
<term> ::= <factor> { (* | /) <factor> }
<factor> ::= IDENTIFIER | NUMBER | ( <expression> )
```

A precedência é: parênteses > multiplicação/divisão > adição/subtração.

## Exemplo de Programa

O seguinte programa demonstra as principais características da linguagem LingParERP:

```lingpar
program exemplo
    var x = 10;
    var y = 5;
    
    if (x > y) {
        print x;
    } else {
        print y;
    }
    
    while (x > 0) {
        print x;
        x = x - 1;
    }
end
```

Este exemplo ilustra:
- Declaração e inicialização de variáveis
- Estrutura condicional com `if-else`
- Loop com `while`
- Operações aritméticas e de comparação

## Conclusão

A gramática EBNF apresentada define uma linguagem de programação simples mas completa, que atende aos requisitos básicos de uma linguagem de programação: variáveis, estruturas condicionais e loops. A escolha da MicrowaveVM como target permite uma implementação direta e eficiente, mantendo a simplicidade do design.

## 📋 Tarefas
- **Tarefa 1**: Estruturar linguagem segundo padrão EBNF (18/Set/2025)
- **Tarefa 2**: Análise Léxica e Sintática com Flex/Bison (16/Out/2025)