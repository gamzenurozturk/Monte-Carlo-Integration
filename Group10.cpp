
// GROUP 10
//Topic:Monte Carlo integration for numerically unsolvable functions


#include <iostream> 
#include <cstdlib> // c++ library for rand()
#include <cmath>   //c++ library for mathematical oparations
using namespace std;

double MathFunction(double a);	//defined functions
double random();
double MonteCarlo(double lowerlimit,double upperlimit,double Number);

main(){
	
	int N;					// numbers of iteration
	double upper=1,lower=0; // limits of integrations
	double estimate;

	for(int j=1;j<11;j++){  //loop for different iteration values
		N=100*pow(j,2);
		estimate=MonteCarlo(lower,upper,N);
		cout<<"Monte Carlo Integration's  (in " <<N<< " iteration) solution for 0 to 1 is:"<<"\t"<<estimate<<endl;
	}
	
}

double MonteCarlo(double x,double y,double Number){ //Function which is calculate monte carlo integration
	
	double riesum=0,result,assign,calc;				// Defined variable
	
	for(int i=0;i< Number-1;i++){					//Loop for rieamann sum
		
		calc=(y-x)*random()+x;
		assign= MathFunction(calc);					//Put recevieved calc value in MathFunction
		riesum += assign;							//Summing variable whenever a value comes from the loop 
		
	}
	
	result=(y-x)/Number*riesum;	
						
	return result;
	
}

double random(){ //Monte Carlo methods use large sets of random numbers,
				 //so we generally place the rand() function inside a large loop.

      return ((double)rand()/(RAND_MAX));
}

double MathFunction(double a){  // function which used for integration
	
	return exp(a)*pow(2,-a);	// f(a)=e^a*2^-a

}
