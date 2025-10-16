%option noyywrap
%option yylineno

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lingpar_simples.tab.h"
%}

%%

[ \t\r\n]+                       { }

"program"                         { return PROGRAM; }
"var"                             { return VAR; }
"print"                           { return PRINT; }
"end"                             { return END; }

"=="                              { return EQUALS; }
"!="                              { return NOT_EQUALS; }
">="                              { return GREATER_EQUALS; }
"<="                              { return LESS_EQUALS; }
">"                               { return GREATER_THAN; }
"<"                               { return LESS_THAN; }

[0-9]+                            { yylval.number = atoi(yytext); return NUMBER; }

[a-zA-Z_][a-zA-Z0-9_]*            { yylval.string = strdup(yytext); return IDENTIFIER; }

\"[^"]*\"                         { yylval.string = strdup(yytext); return STRING; }

";"                               { return SEMICOLON; }
"("                               { return LEFT_PAREN; }
")"                               { return RIGHT_PAREN; }
"{"                               { return LEFT_BRACE; }
"}"                               { return RIGHT_BRACE; }
"="                               { return ASSIGN; }
"+"                               { return PLUS; }
"-"                               { return MINUS; }
"*"                               { return MULTIPLY; }
"/"                               { return DIVIDE; }

.                                 { fprintf(stderr, "Linha %d: caractere desconhecido: '%s'\n", yylineno, yytext); }
%%