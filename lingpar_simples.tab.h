/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     STRING = 259,
     NUMBER = 260,
     PROGRAM = 261,
     VAR = 262,
     PRINT = 263,
     END = 264,
     ASSIGN = 265,
     PLUS = 266,
     MINUS = 267,
     MULTIPLY = 268,
     DIVIDE = 269,
     EQUALS = 270,
     NOT_EQUALS = 271,
     GREATER_EQUALS = 272,
     LESS_EQUALS = 273,
     GREATER_THAN = 274,
     LESS_THAN = 275,
     LEFT_PAREN = 276,
     RIGHT_PAREN = 277,
     LEFT_BRACE = 278,
     RIGHT_BRACE = 279,
     SEMICOLON = 280
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define STRING 259
#define NUMBER 260
#define PROGRAM 261
#define VAR 262
#define PRINT 263
#define END 264
#define ASSIGN 265
#define PLUS 266
#define MINUS 267
#define MULTIPLY 268
#define DIVIDE 269
#define EQUALS 270
#define NOT_EQUALS 271
#define GREATER_EQUALS 272
#define LESS_EQUALS 273
#define GREATER_THAN 274
#define LESS_THAN 275
#define LEFT_PAREN 276
#define RIGHT_PAREN 277
#define LEFT_BRACE 278
#define RIGHT_BRACE 279
#define SEMICOLON 280




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 19 "lingpar_simples.y"
{
    int number;
    char *string;
}
/* Line 1529 of yacc.c.  */
#line 104 "lingpar_simples.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

