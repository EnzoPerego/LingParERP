# Makefile para LingParERP Parser
# Compila Flex + Bison para gerar o parser

CC = gcc
CFLAGS = -Wall -Wextra -std=c99
FLEX = flex
BISON = bison

# Nome do executável
TARGET = lingpar_parser

# Arquivos fonte
LEX_FILE = lingpar.l
YACC_FILE = lingpar.y

# Arquivos gerados
LEX_C = lex.yy.c
YACC_C = lingpar.tab.c
YACC_H = lingpar.tab.h

# Arquivos objeto
OBJS = $(LEX_C:.c=.o) $(YACC_C:.c=.o)

# Regra principal
all: $(TARGET)

# Compilar o executável
$(TARGET): $(OBJS)
	@echo "🔗 Linkando executável..."
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) -lfl
	@echo "✅ Parser compilado com sucesso!"

# Compilar arquivo Flex
$(LEX_C): $(LEX_FILE)
	@echo "🔍 Gerando analisador léxico..."
	$(FLEX) $(LEX_FILE)
	@echo "✅ Flex concluído!"

# Compilar arquivo Bison
$(YACC_C) $(YACC_H): $(YACC_FILE)
	@echo "📝 Gerando analisador sintático..."
	$(BISON) -d $(YACC_FILE)
	@echo "✅ Bison concluído!"

# Compilar arquivos objeto
%.o: %.c
	@echo "🔨 Compilando $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Limpar arquivos gerados
clean:
	@echo "🧹 Limpando arquivos..."
	rm -f $(LEX_C) $(YACC_C) $(YACC_H) $(OBJS) $(TARGET)
	@echo "✅ Limpeza concluída!"

# Testar o parser
test: $(TARGET)
	@echo "🧪 Testando parser..."
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
