#include <iostream>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <cstdlib>
using namespace std;

#include "lib.h"
#include "time.h"

#include "Schrodinger_Equation.h"
void main() {

//Input the size of the matrix you want to use
int step;
cout <<"How big is the matrix? If you don't tell me then I cannot do anything ";
cin >> step;
cin.get();

//input the length scale being used
double length;
cout << "What is the length scale? ";
cin>> length;
cin.get();

//get the omega for the case with electrons
double omega;
cout << "Would you be so kind as to tell me the value of omega? ";
cin >> omega;
cin.get();


//define the matrices you will need
//for the SWE and for the eigen vectors
double **SWE, **EVector;

SWE = new double *[step];
EVector = new double *[step];

for (int i = 0; i<step; i++){
	SWE[i] = new double [step];
	EVector[i] = new double [step];
}

int a;
int b;

//create identity matices
Identity(EVector, step);
Identity(SWE,step);


//Schrodinger Equation
SWE_SHO2e(SWE,step,length,omega);


double tolerance = 0.000000000001;
double max = tolerance + 0.0000000000001;
int iterations = 0;
int maxiter = 1000000;
clock_t start, finish;

/*
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
 
	 cout << "The max is " <<max << endl;
 JacobiRotSym(TestMat,TestEvector, a, b, 4);
iterations++;
}

max = tolerance+0.00000000000001;
iterations = 0;
cout << "The Eigenvalues should be 10.3087, -3.8414, 3.6799, 1.85282 " << endl;
cout << TestMat[0][0] <<" " <<TestMat[1][1]<<" "<<TestMat[2][2]<<" "<<TestMat[3][3]<<endl;
*/





//start the clock
	start = clock();


//solve for the eigenvalues and find the eigen vectors

	///int check1=0;
	//double sum=0;  

while (max > tolerance && iterations < maxiter) {         //my Jacobi Method
 max = offdiagfind(SWE,a,b,step);
 JacobiRotSym(SWE,EVector, a, b, step);

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
 iterations++;
}

finish = clock();
cout << ((finish - start)/CLOCKS_PER_SEC) << endl;


cout << iterations << endl;


//sort eigenvalues
double *eigenvalues;
double *dummy1;       //dummy variables (i am a very funny person
double *dummy2;
eigenvalues = new double[step];
dummy1 = new double[step];
dummy2 = new double[step];


for (int i=0; i<step; i++){
	eigenvalues[i] = SWE[i][i];
	//eigenvalues[i] = diag[i];
}

//my sorting algorithm for e-values and e-vectors
for (int i=0; i<step; i++){
	for (int j=i+1; j<step; j++){
	if (eigenvalues[i] > eigenvalues[j]){
		double a, b;
		a = eigenvalues[i];
		b = eigenvalues[j];
		eigenvalues[j] = a;
		eigenvalues[i] = b;

		for (int k = 0; k<step; k++){
			dummy1[k] = EVector[k][i];
			dummy2[k] = EVector[k][j];
			EVector[k][i] = dummy2[k];
			EVector[k][j] = dummy1[k];
		}
	   }
	}
}

//Normalize the first three eigenvectors
Normalize_Vec(EVector,step);

cout << eigenvalues[0] << " " << eigenvalues[1] << " " << eigenvalues[2] << endl;

	
/*
//place the vectors in a file
ofstream EigenVectors;
EigenVectors.open("5.txt");
EigenVectors << "Evalues" <<" " << eigenvalues[0] << " " << eigenvalues[1] << " " << eigenvalues[2] << endl;
double pos = length/(step+1);
for (int i = 0; i<step; i++){
	EigenVectors << pos << " "<< EVector[i][0]*EVector[i][0] << " " << EVector[i][1]*EVector[i][1] << " " << EVector[i][2]*EVector[i][2] << endl;
	pos += length/(step+1);
}

EigenVectors.close();
*/
cin.get();
}