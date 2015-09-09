Método numérico para encontrar o zero de uma função, estimado para estar entre x0 e x1.

#include <math.h>
#define MAX_ITERACOES 30
float secantes(float (*func)(float), float x0, float x1, float tolerancia) {
    void nrerror(char error_text[]);
    int j;
    float x2,f0,f1;
    f0=(*func)(x0);
    for (j=1; j<=MAX_ITERACOES; j++) {
        fl=(*func)(x1);
        x2=x1-(xl-x0)*f1/(f1-f0);
        if (fabs(x2-x1) < tolerancia || f == 0.0) return x2;
        x0=x1;
        x1=x2;
        f0=f1;
    }
    nrerror("Número máximo de iterações excedido!");
    return 0.0; //não é executado
}
