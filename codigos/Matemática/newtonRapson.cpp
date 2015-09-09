M�todo num�rico para encontrar o zero de uma fun��o, dada tamb�m a sua derivada.

double newtonRaphson(double X0, double (*f)(double), double (*df)(double), double precisao) {
    double Xk = X0, Xk_1;
 
    do {
        Xk_1 = Xk;
        Xk = Xk_1 - f(Xk_1) / df(Xk_1);
    } while (fabs(Xk - Xk_1) >= precisao);
 
    return Xk;
}
 

