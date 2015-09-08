bool sassenfeld(int n, vector< vector<double> > A) //garante que gaussSeidel vai funcionar
{
    vector<double> B(n, 1);
    for (int i = 0; i < n; i++)
    {
        double soma = 0;
        for (int j = 0; j < n; j++)
            if (j != i)
                soma += fabs(A[i][j])*B[j];
        B[i] = soma / A[i][i];
        if (B[i] >= 1)
            return 0;
    }
    return 1;
}
 
vector<double> gaussSeidel(int n, vector< vector<double> > A, vector<double> b, double Toler, int IterMax)
{
    vector<double> x(n);
    vector<double> v(n);
    for (int i = 0; i < n; i++)
    {
        double r = 1 / A[i][i];
        for (int j = 0; j < n; j++)
            if (i != j)
                A[i][j] *= r;
        b[i] *= r;
        x[i] = b[i];
    }
    int Iter = 0;
    double DifMax;
    do
    {
        Iter++;
        for (int i = 0; i < n; i++)
        {
            double Soma = 0;
            for (int j = 0; j < n; j++)
                if (i != j)
                    Soma += A[i][j] * x[j];
            v[i] = x[i];
            x[i] = b[i] - Soma;
        }
        double Norma1 = 0;
        double Norma2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (abs(x[i] - v[i]) > Norma1)
                Norma1 = abs(x[i] - v[i]);
            if (abs(x[i]) > Norma2)
                Norma2 = abs(x[i]);
        }
        DifMax = Norma1 / Norma2;
    }while (DifMax >= Toler && Iter < IterMax);
    bool Erro = (DifMax >= Toler);
    return x;
}
