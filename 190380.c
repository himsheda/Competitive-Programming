#include<stdio.h>
#include<math.h>
double l(int i,double x,double *xi,int n){
    double ans=1;
    for(int j=0;j<=n;j++){
        if(i!=j){
            ans*=(x-xi[j])/(xi[i]-xi[j]);
        }
    }
}
double fx(double x){
    return 1/(1+25*x*x);
}
double p_n(double x,double *xi,int n){
    double ans=0;
    for(int i=0;i<=n;i++){
        ans+=l(i,x,xi,n)*fx(xi[i]);
    }
    return ans;
}
int main(){
    int n=10;
    // scanf("Enter degree n of interpolating polynomial: %d",n);
    double xi[n+1];
    for(int i=0;i<=n;i++){
        xi[i]=2*i/n-1;
    }
    // FILE *fp=fopen("/prunge.dat","w+");
    int m=1001;
    double max_error=0, x_max=0;
    for(int i=0;i<=m;i++){
        double z=2*i/m-1;
        printf("%lf\t%lf\t%lf\n",z,fx(z),p_n(z,xi,n));
        double error=fabs(fx(z)-p_n(z,xi,n));
        if(error>max_error){
            x_max=z;
            max_error=error;
        }
    }
    printf("||f-P_9|| = %lf occurs at x=%lf",max_error,x_max);
    // FILE *fptr;
    // fclose(fp);
    return 0;
}