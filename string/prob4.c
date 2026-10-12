#include <stdio.h>
#include <string.h>
#include <ctype.h>

void resolver() {
    char str[1005];
    if (!fgets(str, sizeof(str), stdin)) return;

    // Remove quebra de linha residual se existir
    str[strcspn(str, "\r\n")] = '\0';
    int len = strlen(str);

    // Passo 1: Deslocar caracteres alfabéticos em +3
    for (int i = 0; i < len; i++) {
        if (isalpha((unsigned char)str[i])) {
            str[i] += 3;
        }
    }

    // Passo 2: Inverter a string in-place
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }

    // Passo 3: Deslocar da metade em diante em -1
    int metade = len / 2;
    for (int i = metade; i < len; i++) {
        str[i] -= 1;
    }

    printf("%s\n", str);
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        // Consome o \n deixado pelo scanf no buffer de entrada
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        while (n--) {
            resolver();
        }
    }
}
