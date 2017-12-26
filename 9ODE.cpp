#include <iostream>
#include <cmath>
using namespace std;
double f(double x,double y){
    return -x*x*y*y;
}
int main(){
    double h,yn,yn1,k1,k2,k3,k4,es;
    double concise = 3./(1.+pow(1.5,3.));//0.685714287
    //Runge-Kutta first
    cout<<"Runge-Kutta"<<endl;
    for(int l=0;l<4;l++){
        h = 0.1/pow(2.,l);
        yn=3.;
        for(int i=0;i*h<1.5;i++){
            k1=f(i*h,           yn);
            k2=f(i*h+1./2.*h,   yn+1./2.*h*k1);
            k3=f(i*h+1./2.*h,   yn+1./2.*h*k2);
            k4=f(i*h+h,         yn+h*k3);
            yn1=yn+             h/6.*(k1+2*k2+2*k3+k4);
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
    //So much for Runge-Kutta
    //Adams now
    double ynm;
    cout<<"Adams"<<endl;
    for(int l=0;l<4;l++){
        h = 0.1/pow(2.,l);
        ynm=3.;
        //Set up initial values
        k1=f(0,       3);
        k2=f(1/2*h,   3+1/2*h*k1);
        k3=f(1./2.*h, 3+1./2.*h*k2);
        k4=f(h,       3+h*k3);
        yn=3+         h/6.*(k1+2*k2+2*k3+k4);
        //Formal calculation        
        for(int i=2;i*h<=1.5;i++){
            //Estimation
            k1=f((i-1)*h,           yn);
            k2=f((i-1)*h+1./2.*h,   yn+1./2.*h*k1);
            k3=f((i-1)*h+1./2.*h,   yn+1./2.*h*k2);
            k4=f((i-1)*h+h,         yn+h*k3);
            yn1=yn+                 h/6.*(k1+2*k2+2*k3+k4);
            //Correction
            yn1=yn+                 h/12*(5*f(i*h,yn1)+8*f((i-1)*h,yn)-f((i-2)*h,ynm));

            ynm=yn;yn=yn1;
        }
        cout<<"h="<<h<<",err="<<abs(yn-concise);
        if(l==0){
            es=abs(yn-concise);
            cout<<endl;
        }
        if(l!=0)
            cout<<",ok="<<log(es/abs(yn-concise))/l/log(2)<<endl;
    }
}
// Output
// Runge-Kutta
// h=0.1,err=1.78e-05
// h=0.05,err=1.04224e-06,ok=4.09412
// h=0.025,err=6.29072e-08,ok=4.07222
// h=0.0125,err=3.86185e-09,ok=4.05677
// Adams
// h=0.1,err=0.000107541
// h=0.05,err=1.05771e-05,ok=3.34587
// h=0.025,err=1.15236e-06,ok=3.27208
// h=0.0125,err=1.33785e-07,ok=3.21692