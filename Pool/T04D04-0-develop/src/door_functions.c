#include <stdio.h>
#include <math.h>
double ANZ(double a);
double BNLL(double x);
double GPB(double x);
void is_opr(double a);
int main() {
    int n,x,p=1;
    double pi = 3.14159265358979323846;
    double iter = 2.0*pi/41;
    double i,x1,x2,x3;
    for(i =-pi; i<=pi;i+=iter){
       x1 = ANZ(i);
       x2 = BNLL(i);
       x3 = GPB(i);
       printf("%.7lf",i);
       printf("|");
       is_opr(x1);
       printf("|");
       is_opr(x2);
       printf("|");
       is_opr(x3);
       printf("\n");
    }
    return 0;
}
double ANZ( double a){
    double res;
    res = 1/(1+pow(a,2));
    return res;
}
double BNLL( double x){
    double res;
    if ((sqrt(1+4*x*x)-x*x-1) <0){
        res = -1000;
    } else {
        res = sqrt(sqrt(1+4*x*x)-x*x-1);
    }
    return res;
}
double GPB( double x){
    double res;
    res = 1.0/(x*x);
    return res;
}
void is_opr(double a){
    if (a == -1000){
        printf("-");
    } else {
        printf("%.7lf",a);
    }
}
