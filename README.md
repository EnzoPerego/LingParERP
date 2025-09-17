# LingParERP - Linguagem de Programação

**Características da Linguagem:**
- Target: MicrowaveVM (Máquina Virtual de Microondas)
- Estilo: Baseado em C com palavras-chave em inglês
- Tipos de dados: Apenas números inteiros
- Foco: Simplicidade e clareza
- Aplicação: Ligar, desligar, definir tempo e potência do microondas

## Como funciona?

A linguagem funciona com uma máquina virtual que simula um microondas real. Ela tem:

- **Controles básicos**: `TIME` (tempo) e `POWER` (potência)
- **Comandos**: `SET` (define valor), `INC` (incrementa), `DECJZ` (decrementa e pula se zero), `GOTO` (pula para linha), `PRINT` (mostra na tela), `HALT` (para execução)

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

## Exemplo de Programa

```lingpar
program microondas
    var tempo = 30;        // 30 segundos
    var potencia = 70;     // 70% de potência
    
    print "Ligando microondas...";
    print "Tempo: " + tempo + " segundos";
    print "Potência: " + potencia + "%";
    
    while (tempo > 0) {
        print "Tempo restante: " + tempo + " segundos";
        tempo = tempo - 1;
    }
    
    print "Microondas desligado!";
end
```

O que esse programa faz:
- Liga o microondas
- Define tempo e potência
- Conta o tempo regressivamente
- Desliga quando termina

## Notações EBNF

A gramática usa as notações padrão EBNF:
- `::=` para definição de regras
- `|` para alternativas (ou)
- `[ ]` para opcional
- `{ }` para repetição zero ou mais vezes
- `( )` para agrupamento
- `*` e `+` para quantificadores
