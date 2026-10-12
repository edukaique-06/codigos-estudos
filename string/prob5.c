#include <stdio.h>
#include <string.h>

static const int leds_por_digito[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    char v[10005];
    while (n--) {
        scanf("%s", v);

        long long total_leds = 0;
        for (int i = 0; v[i] != '\0'; i++) {
            int digito = v[i] - '0';
            total_leds += leds_por_digito[digito];
        }

        printf("%lld leds\n", total_leds);
    }
}
