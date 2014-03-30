#include<cstdio>
#define max(x, y) ((x>y)?(x):(y))
using namespace std;

int main(){
	long long int cnt=1, a[1000], t, n;
	scanf("%lld", &t);
	while(cnt <= t){
		scanf("%lld", &n);
		for(int i=0;i<n;i++)
			scanf("%lld", &a[i]);
		printf("Case %lld: ", cnt);
		cnt++;
		if(n==0)
			printf("0");
		else if(n==1)
			printf("%lld", a[0]);
		else if(n==2)
			printf("%lld", max(a[0], a[1]));
		else if(n==3)
			printf("%lld", max(a[0]+a[2], a[1]));
		else{
			a[2] += a[0];
			long long int max_no = a[0];
			int k=1;
			for(int j=3;j<n;j++){
				max_no = max(max_no, a[k]);
				k++;
				a[j] += max_no;
			}
			max_no = a[0];
			for(int i=1;i<n;i++)
				if(a[i] > max_no)
					max_no = a[i];
			printf("%lld", max_no);
		}
		printf("\n");
	}
    return 0;
}
