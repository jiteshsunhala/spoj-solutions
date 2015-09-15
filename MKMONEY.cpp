#include<iostream>
#include<cstdio>
#include<algorithm>
#define SIZE 1000000

using namespace std;

int arr[SIZE];

int main(){
    double interest, tp, tr, tt, p, r, t, oneTimeRate;
    int cas = 1;
    while(true){
        scanf("%lf%lf%lf", &p, &r, &t);
        if(p == 0 && r == 0 && t == 0)
            break;
        tp = p;
        tr = r;
        tt = t;
        oneTimeRate = r / (t * 100);
        for(int i=0;i<t;i++){
            interest = p * oneTimeRate;
            p += interest;
            p *= 100;
            int num = p;
            p = ((double)num / 100);
        }
        printf("Case %d. $%.2lf at %.2lf%% APR compounded %.0lf times yields $%.2lf\n", cas++, tp, tr, tt, p);
    }
    return 0;
}
