void Identity(double **a, int size){
	for (int i = 0; i<size; i++){
		for (int j=0; j<size; j++){
			a[i][j] = 0;
			if (i==j){
				a[i][i] = 1;
			}
		}
	}
}
	