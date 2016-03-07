void SWE_SHO1e(double **mat, int step, double max){
	double Step;
	double position = 0;
	double step_size;
	Step = step;

	step_size = max/(Step+1);

	//fill matrix with SWE
		for (int i = 0; i<step-1; i++){
		mat[i+1][i] = -1/(step_size*step_size);
		mat[i][i+1] = -1/(step_size*step_size);}

		for (int i=0; i<step; i++){
			mat[i][i] = (2/(step_size*step_size)) + (i+1)*(i+1)*step_size*step_size;
		}
}


void SWE_SHO2e(double **mat, int step, double max, double omega){
	double Step;
	double position = 0;
	double step_size;
	Step = step;

	step_size = max/(Step + 1);

	//fill matrix with SWE
		for (int i = 0; i<step-1; i++){
		mat[i+1][i] = -1/(step_size*step_size);
		mat[i][i+1] = -1/(step_size*step_size);}

		for (int i=0; i<step; i++){
			mat[i][i] = (2/(step_size*step_size)) + (i+1)*(i+1)*step_size*step_size*omega*omega + 1/((i+1)*step_size);
		}

		/*
		for (int i = 0; i<step; i++){
			for (int j = 0; j<step; j++){
				cout << mat[i][j] <<" ";
			}
			cout << endl;
		}
		*/
}

void Normalize_Vec(double **EVector, int size){
	double b;
	
	for (int i = 0; i < size; i++){
		b = 0;

      for (int j = 0; j < size; j++){
		  b += EVector[j][i]*EVector[j][i];
	  }

	  for (int k = 0; k < size; k++) {
		  EVector[k][i] = EVector[k][i]/sqrt(b);  
	  }

	}

}



void Lanczo(double **Mat, int step){
	



	for (int i=0; i<30; i++){




	}
	
	




}










