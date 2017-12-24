#include <iostream>
#include <cmath>
using namespace std;

//The interpolated function
double f(double x){
    return 1/(1+x*x);
}

//Defining and calculating the value of the Lagrange polynomial
//int n is the number of data points
//double input works in its literal sense
//int node means the type of nodes--equidistant or Chebyshev
double L(int n, double input, int node){
    double y=0;
    double *x = new double[n+1];
    //Make a list of nodes
    for(int i = 0;i < n+1;i++){
        if(node == 1) x[i]=-5.+10.*i/n;
        else x[i]=-5*cos((2.*i+1.)*M_PI/(2.*n+2.));
    }
    //Calculating the value of the Lagrange polynomial
    for(int i = 0;i <= n;i++){
        double p = f(x[i]);
        for(int j = 0;j <= n;j++){
            if(j == i) continue;
            p*=(input-x[j])/(x[i]-x[j]);
        }
        y+=p;
    }
    delete []x;
    return y;
}

int main(){

    const int nlist[4]={5,10,20,40};
    int n;

    double error1,error2,errormax1=0,errormax2=0;
    double y;

    for(int q=0;q<4;q++){
        n=nlist[q];
        errormax1=0;
        errormax2=0;
        //Finding the greatest error
        for(int j=0;j<501;j++){
            y = -5.+10.*j/500.;
            error1 = fabs(f(y) - L(n,y,1));
            if(error1 > errormax1) errormax1 = error1;
            error2 = fabs(f(y) - L(n,y,2));
            if(error2 > errormax2) errormax2 = error2;  
        }
        cout<<n<<"   nodes1   "<<errormax1<<"    nodes2    "<<errormax2<<endl;
    }
    return 0;
}