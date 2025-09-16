# LingParERP - Linguagem de Programação

**Características da Linguagem:**
- Target: MicrowaveVM (Máquina Virtual de Microondas)
- Estilo: Baseado em C com palavras-chave em inglês
- Tipos de dados: Apenas números inteiros
- Foco: Simplicidade e clareza para programação de receitas
- Aplicação: Controle de tempo, potência e operações do microondas

## Como funciona?

A linguagem funciona com uma máquina virtual que simula um microondas real. Ela tem:

- **Controles básicos**: `TIME` (tempo) e `POWER` (potência)
- **Simulação**: `TEMP` (temperatura) e `WEIGHT` (peso)
- **Comandos**: `SET`, `INC`, `DECJZ`, `GOTO`, `PRINT`, `HALT`

Basicamente, você escreve o código em LingParERP e ele vira comandos que a máquina virtual entende para controlar o microondas.

## Gramática da Linguagem

### Tokens (o que a linguagem reconhece)

```
IDENTIFIER = [a-zA-Z_][a-zA-Z0-9_]*
NUMBER = [0-9]+
OPERATOR = \+ | \- | \* | \/ | == | != | < | > | =
PUNCTUATION = \( | \) | \{ | \} | ;
KEYWORD = program | end | var | if | else | while | print
```

### Regras (como escrever programas)

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

O que esse programa faz:
- Define tempo e potência para aquecer
- Mostra se é potência alta ou baixa
- Conta o tempo regressivamente
- Simula o aquecimento aumentando a temperatura
