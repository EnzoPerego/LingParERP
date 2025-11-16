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
     IF = 265,
     ELSE = 266,
     WHILE = 267,
     ASSIGN = 268,
     PLUS = 269,
     MINUS = 270,
     MULTIPLY = 271,
     DIVIDE = 272,
     EQUALS = 273,
     NOT_EQUALS = 274,
     GREATER_EQUALS = 275,
     LESS_EQUALS = 276,
     GREATER_THAN = 277,
     LESS_THAN = 278,
     LEFT_PAREN = 279,
     RIGHT_PAREN = 280,
     LEFT_BRACE = 281,
     RIGHT_BRACE = 282,
     SEMICOLON = 283
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
#define IF 265
#define ELSE 266
#define WHILE 267
#define ASSIGN 268
#define PLUS 269
#define MINUS 270
#define MULTIPLY 271
#define DIVIDE 272
#define EQUALS 273
#define NOT_EQUALS 274
#define GREATER_EQUALS 275
#define LESS_EQUALS 276
#define GREATER_THAN 277
#define LESS_THAN 278
#define LEFT_PAREN 279
#define RIGHT_PAREN 280
#define LEFT_BRACE 281
#define RIGHT_BRACE 282
#define SEMICOLON 283




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 19 "lingpar_simples.y"
{
    int number;
    char *string;
}
/* Line 1529 of yacc.c.  */
#line 110 "lingpar_simples.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

