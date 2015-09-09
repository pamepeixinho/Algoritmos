Para todo inteiro k <= N, decide se k é primo.

vector<bool> isPrime;

// T: O(N), M: theta(N)
void crivoErathostenes(int N) {
      int rN = (int)sqrt((double)N);
      isPrime.clear();
      isPrime.resize(N + 1, true);

      for (int m = 2; m <= rN; m++)
            if (isPrime[m])
                  for (int k = m * m; k <= N; k += m)
                        isPrime[k] = false;
}
