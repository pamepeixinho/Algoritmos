double interpolacaoNewton(int m, vector<double> x, vector<double> y, double z)
{
    vector<double> Dely = y;
    for (int k = 1; k <= m - 1; k++)
        for (int i = m; i >= k+1; i--)
            Dely[i-1] = (Dely[i-1] - Dely[i-2]) / (x[i-1] - x[i-k-1]);
    double r = Dely[m-1];
    for (int i = m - 1; i >= 1; i--)
        r = r*(z - x[i-1]) + Dely[i-1];
    return r;
}
