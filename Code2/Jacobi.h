void JacobiRotNonSym(double ** Rot, double ** EVec, int &a, int &b, int step){
	double s, c, t;
	double Rot_aa, Rot_bb, Rot_ia, Rot_ib, Rot_ai, Rot_bi, EVec_ia, EVec_ib;
	double t1, t2;
	//Find what all of the trig functions are
	if (Rot[a][b] !=0){

		
		//find what the tangent is
		if (a > b){
			
		t1= 2*Rot[b][a]/(Rot[b][b]-Rot[a][a]+sqrt((Rot[a][a]-Rot[b][b])*(Rot[a][a]-Rot[b][b]) + 4*Rot[a][b]*Rot[b][a]));
		t2= 2*Rot[b][a]/(Rot[b][b]-Rot[a][a]-sqrt((Rot[a][a]-Rot[b][b])*(Rot[a][a]-Rot[b][b]) + 4*Rot[a][b]*Rot[b][a]));
		if (fabs(t1)>=fabs(t2)){
			t = t2;}
		else{t=t1;}
		}
		else{
        t1= 2*Rot[a][b]/(Rot[b][b]-Rot[a][a]+sqrt((Rot[a][a]-Rot[b][b])*(Rot[a][a]-Rot[b][b]) + 4*Rot[a][b]*Rot[b][a]));
		t2= 2*Rot[a][b]/(Rot[b][b]-Rot[a][a]-sqrt((Rot[a][a]-Rot[b][b])*(Rot[a][a]-Rot[b][b]) + 4*Rot[a][b]*Rot[b][a]));
		if (fabs(t1)>=fabs(t2)){
			t = t2;}
		else{t=t1;}
		}





		c = 1/sqrt(1 + t*t);
		s = c*t;}

	else {
		c=1;
		s = 0;}

	//calculate the new values of the matrix being rotated

	Rot_aa = Rot[a][a];
	Rot_bb = Rot[b][b];
	Rot[a][a] = Rot_aa*c*c - (Rot[a][b]+Rot[b][a])*c*s + Rot_bb*s*s;
	Rot[b][b] = Rot_bb*c*c + (Rot[a][b]+Rot[b][a])*c*s + Rot_aa*s*s;

	if (a>b){
		Rot[b][a] = s*c*(Rot_aa-Rot_bb)-s*s*Rot[b][a]+c*c*Rot[a][b];
	}
	else{
		Rot[b][a] = s*c*(Rot_aa - Rot_bb) - s*s*Rot[a][b] + c*c*Rot[b][a];
	}

    Rot[a][b]=0;

	
	for (int i = 0; i<step; i++){
		if (i != a && i != b){
			Rot_ia = Rot[i][a];
			Rot_ib = Rot[i][b];
			Rot_ai = Rot[a][i];
			Rot_bi = Rot[b][i];
	        Rot[i][a] = Rot_ia*c - Rot_ib*s;
			Rot[i][b] = Rot_ib*c + Rot_ia*s;
			Rot[a][i] = Rot_ai*c - Rot_bi*s;
			Rot[b][i] = Rot_ai*s + Rot_bi*c;
		}


//Eigen Vecgors
EVec_ia = EVec[i][a];
EVec_ib = EVec[i][b];

EVec[i][a] = c*EVec_ia - s*EVec_ib;
EVec[i][b] = c*EVec_ib + s*EVec_ia;
	}
	





}/*
//Unit Test: Test for eigenvalues, and max value
double **TestMat;
double **TestEvector;
TestMat = new double *[4];
TestEvector = new double *[4];
for (int i=0; i<4; i++){
	TestMat[i]=new double [4];
	TestEvector[i] = new double[4];
}
Identity(TestEvector,4);
TestMat[0][0]=1;
TestMat[1][1] = 3;
TestMat[2][2] = 2;
TestMat[3][3] = 6; TestMat[1][0]=TestMat[0][1] = 2; TestMat[0][2]=TestMat[2][0] = 5; TestMat[0][3]=TestMat[3][0]=3;
TestMat[2][1]=TestMat[1][2]=1; TestMat[3][1]=TestMat[1][3]=2; TestMat[2][3]=TestMat[3][2] = 1;

while (max > tolerance && iterations < maxiter) {        
 max = offdiagfind(TestMat,a,b,4);
// if (iterations = 0){
	// cout << "The max is " <<max << endl;}
 JacobiRotSym(TestMat,TestEvector, a, b, 4);
iterations++;
}
max = tolerance+0.00000000000001;
iterations = 0;
cout << "The Eigenvalues should be 10.3087, -3.8414, 3.6799, 1.85282 " << endl;
cout << TestMat[0][0] <<" " <<TestMat[1][1]<<" "<<TestMat[2][2]<<" "<<TestMat[3][3]<<endl;

*/


/*
 //Unit test for eigenvalues
check1++;
 if (check1 == 200){
	 for (int i = 0; i < step; i++){
		 sum += EVector[i][4]*EVector[i][9];}
	 if (sum < 0.0000000001){sum=0;}
	 cout << "//////" << sum << "///////" << endl;
	 sum = 0;
	 check1 = 0; 
	 }
 */