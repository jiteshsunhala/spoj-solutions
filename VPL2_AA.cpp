#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main(){
    double p0, p1, ti, p, logC, result;
    int t, cas = 1;
    scanf("%d", &t);
    while(t--){
        scanf("%lf%lf%lf%lf", &p0, &p1, &ti, &p);
        logC = log(p1 / p0) / ti;
        result = log(p / p0) / logC;
        printf("Scenario #%d: %.2lf\n", cas++, result);
    }
    return 0;
}
