#include <cmath>
#include <iostream>
using namespace std;
//The exact value calculated in other ways
const double intg = 0.2566401204049134;
int main(){
    int n[13]={0};
    double h;
    double simpson,trapezoid,serror,terror,so,to,sed,ted;
    for(int k=1;k<=12;k++){
        //Definition
        n[k]=pow(2,k);
        double *x = new double[n[k]+1];
        double *y = new double[n[k]+1];
        h=4./n[k];
        for(int i=0;i<=n[k];i++){
            x[i]=1+h*i;
            y[i]=sin(x[i]);
        }
        simpson=0;trapezoid=0;
        //Simpson
        for(int i=0;i<=n[k]/2-1;i++){
            simpson+=4*y[2*i+1];
            if(i>0) simpson+=2*y[2*i];
        }
        simpson+=y[0]+y[n[k]];
        simpson*=h/3;
        serror = fabs(intg-simpson);
        if(k==1) {sed=serror; so=0;}
            else so = log10(sed/serror)/(k-1)/log10(2);
        //Trapezoid
        for(int i=1;i<=n[k]-1;i++){
            trapezoid+=y[i];
        }
        trapezoid+=0.5*y[0]+0.5*y[n[k]];
        trapezoid*=h;
        terror = fabs(intg-trapezoid);
        if(k==1) {ted=terror;to=0;}
            else to = log10(ted/terror)/(k-1)/log10(2);
        //Output
        cout<<"k="<<k<<endl;
        cout<<"Trapezoid "<<trapezoid<<"\t"<<terror<<"\t"<<to<<endl;
        cout<<"Simpson "<<simpson<<"\t"<<serror<<"\t"<<so<<endl;
        delete[] x;
        delete[] y;
    }  
}