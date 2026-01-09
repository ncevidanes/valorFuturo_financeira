#include <math.h>       // Necessário para a função 'pow' (potência)
#include <emscripten.h> // Necessário para a macro EMSCRIPTEN_KEEPALIVE

// A macro abaixo garante que o compilador NÃO delete essa função
// durante a otimização, mantendo-a disponível para o JavaScript.
EMSCRIPTEN_KEEPALIVE
float calcular_juros_compostos(float pv, float i, int n) {

    // 1. Converte a taxa de porcentagem (10) para decimal (0.10)
    float taxa_decimal = i / 100.0;

    // 2. Calcula (1 + i)^n
    // A função pow() vem da biblioteca math.h
    float fator = pow((1 + taxa_decimal), n);

    // 3. Retorna o Valor Futuro
    return pv * fator;
}
