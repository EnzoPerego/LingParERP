%{
#include <stdio.h>
#include <stdlib.h>

// Declaração da função yylex (gerada pelo Flex)
extern int yylex(void);

// Função para reportar erros sintáticos
void yyerror(const char *s);

// Contador de erros
int error_count = 0;

// Função para imprimir mensagens de sucesso
void print_success(const char *message);
%}

// Definir union para valores dos tokens
%union {
    int number;
    char *string;
}

// Definir os tokens (mesmos valores do Flex)
%token <string> IDENTIFIER STRING
%token <number> NUMBER
%token PROGRAM VAR PRINT END IF ELSE WHILE
%token ASSIGN PLUS MINUS MULTIPLY DIVIDE
%token EQUALS NOT_EQUALS GREATER_EQUALS LESS_EQUALS GREATER_THAN LESS_THAN
%token LEFT_PAREN RIGHT_PAREN LEFT_BRACE RIGHT_BRACE SEMICOLON

// Definir precedência dos operadores
%left PLUS MINUS
%left MULTIPLY DIVIDE
%left EQUALS NOT_EQUALS GREATER_EQUALS LESS_EQUALS GREATER_THAN LESS_THAN

// Definir o símbolo inicial
%start program

%%

/* Programa principal */
program:
    PROGRAM IDENTIFIER LEFT_BRACE statement_list RIGHT_BRACE END {
        print_success("Programa válido!");
    }
    ;

/* Lista de comandos */
statement_list:
    /* vazio */
    | statement_list statement
    ;

/* Tipos de comandos */
statement:
    declaration
    | assignment
    | conditional
    | loop
    | print_statement
    ;

/* Declaração de variáveis */
declaration:
    VAR IDENTIFIER optional_assignment SEMICOLON {
        print_success("Declaração de variável válida");
    }
    ;

optional_assignment:
    /* vazio */
    | ASSIGN expression
    ;

/* Atribuição */
assignment:
    IDENTIFIER ASSIGN expression SEMICOLON {
        print_success("Atribuição válida");
    }
    ;

/* Condicional */
conditional:
    IF LEFT_PAREN expression RIGHT_PAREN LEFT_BRACE statement_list RIGHT_BRACE optional_else {
        print_success("Condicional válida");
    }
    ;

optional_else:
    /* vazio */
    | ELSE LEFT_BRACE statement_list RIGHT_BRACE
    ;

/* Loop */
loop:
    WHILE LEFT_PAREN expression RIGHT_PAREN LEFT_BRACE statement_list RIGHT_BRACE {
        print_success("Loop válido");
    }
    ;

/* Comando print */
print_statement:
    PRINT expression SEMICOLON {
        print_success("Comando print válido");
    }
    ;

/* Expressões */
expression:
    IDENTIFIER
    | NUMBER
    | STRING
    | LEFT_PAREN expression RIGHT_PAREN
    | expression PLUS expression
    | expression MINUS expression
    | expression MULTIPLY expression
    | expression DIVIDE expression
    | expression EQUALS expression
    | expression NOT_EQUALS expression
    | expression GREATER_EQUALS expression
    | expression LESS_EQUALS expression
    | expression GREATER_THAN expression
    | expression LESS_THAN expression
    ;

%%

// Função para reportar erros sintáticos
void yyerror(const char *s) {
    error_count++;
    printf("Erro sintático: %s\n", s);
}

// Função para imprimir mensagens de sucesso
void print_success(const char *message) {
    printf("%s\n", message);
}

// Função principal
int main(int argc, char *argv[]) {
    printf("=== Parser LingParERP ===\n");
    printf("Analisando programa...\n\n");
    
    int result = yyparse();
    
    if (result == 0 && error_count == 0) {
        printf("\nPrograma válido! Análise sintática concluída com sucesso.\n");
    } else {
        printf("\nPrograma inválido! %d erro(s) encontrado(s).\n", error_count);
    }
    
    return result;
}
