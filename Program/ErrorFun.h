double TotalError(double CalculatedValue, double x){
	double TrueValue = TrueSolution(x);
	double TotError = abs(TrueValue - CalculatedValue);
    return TotError;
}

double RelativeError(double CalculatedValue, double x){
	double TrueValue = TrueSolution(x);
	double RelError =(log10(abs((TrueValue-CalculatedValue)/TrueValue)));
	return RelError;
}