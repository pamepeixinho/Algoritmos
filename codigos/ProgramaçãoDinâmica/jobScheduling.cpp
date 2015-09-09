Existindo um conjunto de trabalhos disponíveis, cada um com um lucro associado, escolher um subconjunto mais lucrativo deles para serem executados tal que nenhum par se sobreponha, ou seja, aconteçam ao mesmo tempo.
Retorna o lucro dessa solução ótima.

struct Job {
    int start, finish, profit;
};
 
bool myfunction(Job s1, Job s2) {
    return (s1.finish < s2.finish);
}

int latestNonConflict(Job arr[], int i) {
    for (int j=i-1; j>=0; j--) {
        if (arr[j].finish <= arr[i].start)
            return j;
    }
    return -1;
}

//O(n^2)
int findMaxProfit(Job arr[], int n) {
    // Sort jobs according to finish time
    sort(arr, arr+n, myfunction);
 
    // Create an array to store solutions of subproblems.  table[i]
    // stores the profit for jobs till arr[i] (including arr[i])
    int *table = new int[n];
    table[0] = arr[0].profit;
 
    // Fill entries in M[] using recursive property
    for (int i=1; i<n; i++) {
        // Find profit including the current job
        int inclProf = arr[i].profit;
        int l = latestNonConflict(arr, i);
        if (l != -1)
            inclProf += table[l];
 
        // Store maximum of including and excluding
        table[i] = max(inclProf, table[i-1]);
    }
 
    int result = table[n-1];
    delete[] table;
 
    return result;
}

