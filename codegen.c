#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Gerador de código para MicrowaveVM
// Converte programas LingParERP para assembly da MicrowaveVM

void generate_code(FILE *input, FILE *output) {
    char line[256];
    int var_tempo = 0, var_potencia = 0;
    int has_tempo = 0, has_potencia = 0;
    
    fprintf(output, "; Código gerado automaticamente para MicrowaveVM\n");
    fprintf(output, "; A partir de programa LingParERP\n\n");
    
    while (fgets(line, sizeof(line), input)) {
        // Remove espaços em branco
        char *trimmed = line;
        while (*trimmed == ' ' || *trimmed == '\t') trimmed++;
        
        // Ignora linhas vazias e comentários
        if (trimmed[0] == '\n' || trimmed[0] == '\0') continue;
        
        // Remove newline
        char *nl = strchr(trimmed, '\n');
        if (nl) *nl = '\0';
        
        // Detecta declaração de variável
        if (strstr(trimmed, "var ") != NULL) {
            char var_name[64];
            int value = 0;
            
            if (sscanf(trimmed, "var %s = %d;", var_name, &value) == 2) {
                // Remove ponto e vírgula do nome da variável
                char *semi = strchr(var_name, ';');
                if (semi) *semi = '\0';
                
                fprintf(output, "; Declaração: var %s = %d\n", var_name, value);
                
                if (strcmp(var_name, "tempo") == 0) {
                    var_tempo = value;
                    has_tempo = 1;
                    fprintf(output, "SET TIME %d\n", value);
                } else if (strcmp(var_name, "potencia") == 0) {
                    var_potencia = value;
                    has_potencia = 1;
                    fprintf(output, "SET POWER %d\n", value);
                }
            }
        }
        
        // Detecta comando print
        if (strstr(trimmed, "print") != NULL) {
            fprintf(output, "; Comando print\n");
            
            // Se print tem número (tempo ou potencia)
            if (strstr(trimmed, "tempo") != NULL) {
                if (has_tempo) {
                    fprintf(output, "SET TIME %d\n", var_tempo);
                    fprintf(output, "PRINT\n");
                }
            } else if (strstr(trimmed, "potencia") != NULL) {
                if (has_potencia) {
                    fprintf(output, "SET TIME %d\n", var_potencia);
                    fprintf(output, "PRINT\n");
                }
            } else {
                // Print de string ou mensagem - imprime um valor simbólico
                fprintf(output, "SET TIME 1\n");
                fprintf(output, "PRINT\n");
            }
        }
    }
    
    fprintf(output, "\nHALT\n");
    fprintf(output, "; Fim do programa\n");
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Uso: %s <arquivo_lingpar> <arquivo_assembly>\n", argv[0]);
        printf("Exemplo: %s teste.microondas output.mwasm\n", argv[0]);
        return 1;
    }
    
    FILE *input = fopen(argv[1], "r");
    if (!input) {
        fprintf(stderr, "Erro: não foi possível abrir %s\n", argv[1]);
        return 1;
    }
    
    FILE *output = fopen(argv[2], "w");
    if (!output) {
        fprintf(stderr, "Erro: não foi possível criar %s\n", argv[2]);
        fclose(input);
        return 1;
    }
    
    printf("Gerando código assembly para MicrowaveVM...\n");
    generate_code(input, output);
    
    fclose(input);
    fclose(output);
    
    printf("Código gerado com sucesso em %s\n", argv[2]);
    return 0;
}