Nao funciona para numeros muito grandes, visto que n^2 estoura a capacidade do double.

bool isPerfectSquare(int x) {
    double s = sqrt(x);
    return (s == floor(s));
}

// T: O(logn), M: O(1)
bool isFibonacci(double n) {
    return isPerfectSquare(5*n*n + 4) ||
           isPerfectSquare(5*n*n - 4);
}
