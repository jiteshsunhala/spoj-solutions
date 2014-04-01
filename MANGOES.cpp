#include<cstdio>
#define size 1000001
using namespace std;

int main(){
    unsigned long long int sq;
    int m, n, t, r;
    scanf("%d", &t);
    
    while(t--){
        scanf("%d", &n);
        m = (n-1)/2;
        sq = m * m;
        r = sq % n;
        printf("%d\n", r);
    }
    return 0;
}
