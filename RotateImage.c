void rotate(vector<vector<int>>& m) {
	int n = size(m), tmp;
	for(int i = 0; i < (n + 1) / 2; i++){
		for(int j = 0; j < n / 2; j++){
			tmp = m[n - 1 - j][i];
			m[n - 1 - j][i] = m[n - 1 - i][n - 1 - j];
			m[n - 1 - i][n - 1 - j] = m[j][n - 1 - i];
			m[j][n - 1 - i] = m[i][j];                
			m[i][j] = tmp;
		}
	}        
}
