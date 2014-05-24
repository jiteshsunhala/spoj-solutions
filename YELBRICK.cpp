#include<cstdio>
#include<algorithm>

using namespace std;

long long int arr[1000];

int gcd(int a, int b){
	if (b==0)
		return a;
	return gcd(b,a%b);
}

int main(){

	int n, a, b, c;
	while(true){
		scanf("%d", &n);
		if(!n)
			break;
		int i=0;
		scanf("%d%d%d", &a, &b, &c);
		arr[i] = a * b * c;
		int g = arr[i];
		i++;
		while(i < n){
			scanf("%d%d%d", &a, &b, &c);
			arr[i] = a * b * c;
			g = __gcd((int)arr[i], g);
			i++;
		}
		long long int total = 1;
		
		for(int i=2;true;i++){
			int cube = i * i * i;
			if(cube > g)
				break;
			if(g % cube == 0)
				total = cube;
		}
		long long int tsum = 0;
		for(int i=0;i<n;i++){
			tsum += (arr[i] / total);
		}
		
		printf("%lld\n", tsum);
	}
	return 0;
}
