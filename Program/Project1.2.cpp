#include <iostream>
#include <cmath>
#include <fstream>


using namespace std;
#include "lib.h"
#include "time.h"
#include "Functions.h"
#include "GaussianElimination.h"

//Start Main Program
int main(){

	//while vector is simply what the poisson equation is equal to
	
double **Matrix;	
double *Vector;
double *Solution;
double *Vector2;
double *SolutionCalc;
double *RelError;

int *Index;
double *Pivot;
double *TrueSolnLU;


ofstream Error;
//seting up dynamic variable input
int j;
double k;

// Loop to determine how many times you want to run the program
int v;
cout << "How many times do you want to run through the program? ";
cin >> v;
cin.get();

//create file to look at relative error (need to go the the bottom for other part of error code

Error.open("RelativeError.txt");

clock_t start, finish;


for (int i = 0; i<v; i++){
	


	//determine the size of the matrix
	cout << "what is matrix size? ";
	cin >> j;
	cin.get();
	k=j+1;
double step = 1/k;
	
	//Finish defining pointers
    Vector = new double[j];
	Solution = new double[j+2];
	Vector2 = new double[j];
	SolutionCalc = new double[j+2];
	RelError = new double[j];
	Matrix = new double*[j];
	
	//new stuff for MatrixLibrary functions
	Pivot = new double;
	Index = new int[j];
	TrueSolnLU = new double[j];

	for(int i = 0; i < j; ++i){
   Matrix[i] = new double[j];
	}

	//Fill Matrix with zeros
	for (int i=0; i<j; i++){
		for (int n = 0; n<j; n++){
			 Matrix[i][n]=0;}
		
	}

	//Fill the Matrix
	for (int i = 0; i<j; i++){
		Matrix[i][i] = 2;
	}
	for (int i = 0; i<j-1; i++){
		Matrix[i+1][i] = -1;
		Matrix[i][i+1] = -1;}

	
	//start the clock
	start = clock();

	//Lu Decomposition
	ludcmp(Matrix,j,Index,Pivot);

	for (int i=0; i<j; i++){
		double v = i;
        
	TrueSolnLU[i] = Function(step*(v+1));
	
	}

    lubksb(Matrix,j,Index,TrueSolnLU);

	for (int i=0; i<j; i++){
		cout << TrueSolnLU[i]*step*step << endl;
	}
	
	
	//fill vectors and the calculated solution
	 for (int i=0; i<j; i++){
		double v = i;
		Vector[i] = Function(step*(v+1));
	    Vector2[i] = 2;
		SolutionCalc[i+1]=TrueSolution(step*(v+1));
	 }
	
	 //Apply the Dirichlet Boundary Conditions to the solutions
	 Solution[0]=0;
	 Solution[j+1]=0;
	 SolutionCalc[0] = 0;
	 SolutionCalc[j+1] = 0;
	 
/*
	 //Solve Poissons Equation
	VecSolve(Vector2, Vector, j);
	for (int i=1; i<j+1; i++){
		Solution[i] = (Vector[i-1]*step*step)/Vector2[i-1];
		//RelError[i-1]= log10(abs((Solution[i]-SolutionCalc[i])/SolutionCalc[i]));
		//cout << Solution[i]<< endl;

	}
	*/
	
	//Second part of error code
	/*
	//find the max value of the realtive error
	double num = 0;
	for (int i=0; i<j; i++){
		if(RelError[i]<num);
		num = RelError[i];
	}

	cout << num << endl;

	Error << log10(step) << " " << j << " " << num << endl;
	*/




	//write the solutions to a text file

	/*
	double Position = 0;
ofstream PoissonSoln;
PoissonSoln.open("PoissonGrid1000.txt");
	for (int i = 0; i<j+2; i++){
		
		PoissonSoln << Position <<" "<< SolutionCalc[i] <<" "<< Solution[i]  << endl;
		Position = Position + step;
	}

	PoissonSoln.close();
	*/
	finish = clock();

	
	cout << ((finish - start)/CLOCKS_PER_SEC) << endl;
	
}


cin.get();
return 0;


}