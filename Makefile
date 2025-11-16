# Makefile para LingParERP Parser
# Compila Flex + Bison para gerar o parser

CC = gcc
CFLAGS = -Wall -Wextra -std=c99
FLEX = flex
BISON = bison

# Nome do executável
TARGET = parser

# Arquivos fonte
LEX_FILE = lingpar_flex.l
YACC_FILE = lingpar_simples.y

# Arquivos gerados
LEX_C = lex.yy.c
YACC_C = lingpar_simples.tab.c
YACC_H = lingpar_simples.tab.h

# Arquivos objeto
OBJS = $(LEX_C:.c=.o) $(YACC_C:.c=.o)

# Regra principal
all: $(YACC_H) $(TARGET) codegen

# Compilar o executável
$(TARGET): $(OBJS)
	@echo "Linkando executável..."
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
	@echo "Parser compilado com sucesso!"

# Compilar arquivo Flex (depende do header do Bison)
$(LEX_C): $(LEX_FILE) $(YACC_H)
	@echo "Gerando analisador léxico..."
	$(FLEX) $(LEX_FILE)
	@echo "Flex concluído!"

# Compilar arquivo Bison
$(YACC_C) $(YACC_H): $(YACC_FILE)
	@echo "Gerando analisador sintático..."
	$(BISON) -d $(YACC_FILE)
	@echo "Bison concluído!"

# Compilar arquivos objeto
%.o: %.c
	@echo "Compilando $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Compilar codegen
codegen: codegen.c
	@echo "Compilando gerador de código..."
	$(CC) $(CFLAGS) -o codegen codegen.c
	@echo "Gerador de código compilado com sucesso!"

# Limpar arquivos gerados
clean:
	@echo "Limpando arquivos..."
	rm -f $(LEX_C) $(YACC_C) $(YACC_H) $(OBJS) $(TARGET) codegen output.mwasm *.mwasm
	@echo "Limpeza concluída!"

# Testar o parser
test: $(TARGET)
	@echo "Testando parser..."
	@echo "Teste 1: Programa válido"
	@echo 'program teste { var tempo = 30; print tempo; } end' | ./$(TARGET)
	@echo ""
	@echo "Teste 2: Programa com erro"
	@echo 'program teste { var tempo = 30 print tempo; } end' | ./$(TARGET)

# Mostrar ajuda
help:
	@echo "📋 Comandos disponíveis:"
	@echo "  make          - Compilar o parser"
	@echo "  make clean    - Limpar arquivos gerados"
	@echo "  make test     - Testar o parser"
	@echo "  make help     - Mostrar esta ajuda"

# Marcar como phony (não são arquivos)
.PHONY: all clean test help
