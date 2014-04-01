#include<cstdio>
#include<algorithm>

using namespace std;

bool myfunction (int i,int j) { return (i<j); }

int main(){
	
	int min, diff, a[20000], t, n, k;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		for(int i=0;i<n;i++)
			scanf("%d", &a[i]);
		sort(a, a+n, myfunction);
		min = a[k-1] - a[0];
		for(int i=1, j=k;j<n;j++, i++){
			if(a[j] - a[i] < min)
				min = a[j] - a[i];
		}
		printf("%d\n", min);
	}
    return 0;
}
