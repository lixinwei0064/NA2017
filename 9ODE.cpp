#include <iostream>
#include <cmath>
using namespace std;
double f(double x, double y){
    return -x*x*y*y;
}
int main(){
    double h,yn,yn1,k1,k2,k3,k4,es;
    double concise = 3./(1.+pow(1.5,3.));
    for(int l=0;l<4;l++){
        h = 0.1/pow(2.,l);
        yn=3.;
        for(int i=0;i*h<1.5;i++){
            k1=f(i*h,           yn);
            k2=f(i*h+1./3.*h,   yn+1./3.*h*k1);
            k3=f(i*h+2./3.*h,   yn+1./3.*h*k1+h*k2);
            k4=f(i*h+h,         yn+h*k1-h*k2+h*k3);
            yn1=yn+             h/8.*(k1+3*k2*3*k3+k4);
            yn=yn1;
        }        
        cout<<"h="<<h<<",err="<<abs(yn-concise);
        if(l==0){
            es=fabs(yn-concise);
            cout<<endl;
        }
        if(l!=0)
            cout<<",ok="<<log(es/fabs(yn-concise))/l/log(2)<<endl;
    }
}