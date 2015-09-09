long int *A;

bool bb(int procurado)
{
    int e = 0, d = N, m;
 
    while (e <= d)
    {
        m = (e + d) / 2;
        if (procurado < A[m])
            d = m - 1;
        else if (procurado > A[m])
            e = m + 1;
        else
            return 1;
    }
 
    return 0;
}
