# LingParERP - Linguagem de Programação

## Visão Geral

Esta especificação define a gramática formal da linguagem de programação LingParERP, desenvolvida como parte da Atividade Prática Supervisionada da disciplina de Linguagens de Programação. A linguagem foi projetada para controlar um microondas virtual através da MicrowaveVM.

**Características da Linguagem:**
- Target: MicrowaveVM (Máquina Virtual de Microondas)
- Estilo: Baseado em C com palavras-chave em inglês
- Tipos de dados: Apenas números inteiros
- Foco: Simplicidade e clareza para programação de receitas
- Aplicação: Controle de tempo, potência e operações do microondas

## Conexão com a MicrowaveVM

A linguagem LingParERP foi desenvolvida especificamente para a **MicrowaveVM**, uma máquina virtual que simula um microondas real. A VM possui:

- **Registradores de controle**: `TIME` (tempo) e `POWER` (potência)
- **Registradores de simulação**: `TEMP` (temperatura) e `WEIGHT` (peso)
- **Instruções básicas**: `SET`, `INC`, `DECJZ`, `GOTO`, `PRINT`, `HALT`

A linguagem LingParERP traduz programas de alto nível (como o exemplo acima) para instruções de baixo nível da MicrowaveVM, permitindo programar receitas e operações de microondas de forma intuitiva.

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

O seguinte programa demonstra como usar a linguagem LingParERP para controlar um microondas virtual:

```lingpar
program aquecer_comida
    var tempo = 60;        // tempo em segundos
    var potencia = 80;     // potência em percentual
    var temperatura = 0;   // temperatura inicial
    
    print "Iniciando aquecimento...";
    
    if (potencia > 50) {
        print "Potência alta selecionada";
    } else {
        print "Potência baixa selecionada";
    }
    
    while (tempo > 0) {
        print "Tempo restante: " + tempo + " segundos";
        print "Temperatura atual: " + temperatura + "°C";
        tempo = tempo - 1;
        temperatura = temperatura + 2;  // simula aquecimento
    }
    
    print "Aquecimento concluído!";
end
```

Este exemplo ilustra:
- Controle de tempo e potência do microondas
- Estrutura condicional para diferentes níveis de potência
- Loop para contagem regressiva do tempo
- Simulação de aquecimento com variável de temperatura

## Conclusão

A gramática EBNF apresentada define uma linguagem de programação simples mas completa, especificamente projetada para controlar operações de microondas virtuais. A linguagem LingParERP atende aos requisitos básicos de uma linguagem de programação (variáveis, estruturas condicionais e loops) enquanto mantém foco na simplicidade necessária para programação de receitas e controle de tempo/potência. A escolha da MicrowaveVM como target permite uma implementação direta e eficiente, simulando realisticamente o comportamento de um microondas real através de registradores de tempo, potência e temperatura.
