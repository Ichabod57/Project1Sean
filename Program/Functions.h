double Function(double x){
	double r;
	r = 100* exp (-10*x);
	return r;
}

double FunctionDerivative(double x){
	double r;
	r = 0;
	return r;
}

double TrueSolution(double x){
	double r;
	double b = 10;
	r = 1-(1-exp(-b))*x-exp(-10*x);
	return r;
}
