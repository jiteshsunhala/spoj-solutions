#include<cstdio>
#include<cmath>
using namespace std;
typedef long long int L;
#define mymax(x, y) ((x > y)?(x):(y))
int main(){
	
	L max, i=1, l, b, h, t, tot, cnt;
	scanf("%lld", &t);
	while(i<=t){
		scanf("%lld%lld%lld", &l, &b, &h);
		tot = l * b * h;
		printf("Case #%lld: %lld ", i, tot - 1);
		i++;
		cnt = 0;
		while(1){
			if(l==1 && b==1 && h==1)
				break;
			max = mymax(l, mymax(b, h));
			if(max == l)
				l = (L)ceil((double)max/2.0);
			else if(max == b)
				b = (L)ceil((double)max/2.0);
			else
				h = (L)ceil((double)max/2.0);
			cnt++;
		}
		printf("%lld\n", cnt);
	}
    return 0;
}
