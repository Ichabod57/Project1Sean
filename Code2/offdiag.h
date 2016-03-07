double offdiagfin(double **Mat, int &a, int &b, int n){
	double max=0;

	for (int i = 0; i<n; i++){
		for (int j = i+1; j<n; j++){
			double aij = fabs(Mat[i][j]);
			if (aij >  max){
				max = aij;
				a = i;
				b = j;
			}
		}
	}

	return max;


}

double offdiagfin2(double **Mat, int &a, int &b, int n){
	double max=0;

	for (int i = 0; i<n; i++){
		for (int j = 0; j<n; j++){
			double aij = fabs(Mat[i][j]);
			if (i != j){
			if (aij >  max){
				max = aij;
				a = i;
				b = j;
			}}
		}
	}

	return max;


}