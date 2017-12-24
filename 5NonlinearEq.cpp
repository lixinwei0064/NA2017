#include <iostream>
#include <cmath>
using namespace std;
//Original function, the derivative, the iterator for Newton method and the iterator for secant method, respectively
double f(double x){
    return x*x*x/3-x;
}
double df(double x){
    return x*x-1;
}
double g(double x){
    return x-f(x)/df(x);
}
double h(double x,double y){
    return x-f(x)*(x-y)/(f(x)-f(y));
}
int main(){
    double eps = 1.0E-8;
    int step;
    cout<<"Newton Method"<<endl;
    double x0[4]={0.1,0.2,0.9,9.0};
    double x1;
    for(int i=0;i<4;i++){
        cout<<"Initial = "<<x0[i]<<",";
        step = 0;
        while(1){
            x1 = g(x0[i]);
            step++;
            if(fabs(x1-x0[i])<eps){
                cout<<"Root = "<<x1<<","<<"Step = "<<step<<endl;
                break;
            }
            x0[i]=x1;
        }     
    }
    cout<<"Secant Method"<<endl;
    double y0[4]={-0.1,-0.2,-2,0.9};
    double y1[4]={0.1,0.2,0.9,9};
    double y2;
    for(int i=0;i<4;i++){
        cout<<"Initial = "<<y0[i]<<","<<y1[i]<<",";
        step = 0;
        while(1){
            y2 = h(y0[i],y1[i]);
            step++;
            if(fabs(y2-y1[i])<eps){
                cout<<"Root = "<<y2<<","<<"Step = "<<step<<endl;
                break;
            }
            y0[i]=y1[i];
            y1[i]=y2;
        }
    }
    return 0;
}