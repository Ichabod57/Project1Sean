double GaussianElim(double **a, double *b, int j){
	
	
	  //Gaussian eliminate down the diagonal

	for (int i = 0; i<j-1; i++){
		a[i+1][i+1] = a[i+1][i+1] + (a[i+1][i]/a[i][i]);
		b[i+1] = b[i+1] - b[i]*(a[i+1][i]/a[i][i]);	
	}
	
	//Gaussian eliminate up the diagonal
	for (int i = 0; i<j-1; i++){
		b[j-2-i] = b[j-2-i] - b[j-1-i]*(a[j-2-i][j-1-i]/a[j-1-i][j-1-i]);
		
	}
	
	
	 return 0;


}

double VecSolve(double *a, double *b, int j){

	for (int i=0; i<j-1; i++){
		a[i+1]=a[i+1]-(1/a[i]);
		b[i+1]=b[i+1]+b[i]*(1/a[i]);
	}

	for (int i=0; i<j-1; i++){
		b[j-2-i]=b[j-2-i]+b[j-1-i]*(1/a[j-1-i]);
	}


	return 0;
}