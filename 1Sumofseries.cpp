//Calculating the sum of a given series so that the truncation error is less than 10^-6
#include <math.h>
#include <cstdio>
double func1(double x, double k){
    return 1.0/(k*(k+x));
}
double func2(double i){
    return 1.0/(i*i);
}
int main(){
    double x[7]={0,0.5,1,sqrt(2),10,100,300};
    double y[7]={0};
    int n;
    //find n
    double sum=0;
    for(n=1;;n++){
        sum+=func2(n);
        if(M_PI*M_PI/6-sum<1.0E-6) break;
    }
    //calculate the series
    for(int size=0;size<=6;size++){
        for(int i=1;i<=n;i++){
            y[size]+=func1(x[size],i);
        }
        printf("x=%.1f,y=%.15f\n",x[size],y[size]);
    }
    return 0;
}