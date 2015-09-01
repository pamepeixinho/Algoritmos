// T: theta(V^3), M: theta(V^2)
vector<vector<int> > floydWarshall(vector<vector<int> > d) { //!! matriz de adjacencia
	int n = d.size();
	int k, i, j;
	
	for (k = 0; k < n; k++)
            for (i = 0; i < n; i++)
                for (j = 0; j < n; j++)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                    
    return d;	
}

