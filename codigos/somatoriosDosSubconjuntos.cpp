// T: theta(nK), M: theta(K), sendo K o maior valor de interesse
vector<bool> somatoriosDosSubconjuntos(int conj[], int n, int K) {
	vector<bool> pos(K + 1, false);
	pos[0] = true;

	for(int i = 0; i < n; i++)
		for(int j = K; j >= conj[i]; j--)
			if(pos[j - conj[i]])
				pos[j] = true;

	return pos;
}
