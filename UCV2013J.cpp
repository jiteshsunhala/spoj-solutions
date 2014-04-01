#include<cstdio>
using namespace std;

int my_log_2_val(int n){
	int log_2 = 0;
	while(n){
		log_2++;
		n >>= 1;
	}
	log_2--;
	int m = 1 << log_2;
	return m-1;
}

int main(){
	int sum, s, t, val, n, log_val;
	while(true){
		scanf("%d", &n);
		if(!n)
			break;
		sum = 0;
		log_val = my_log_2_val(n);
		for(int i=1;i<=n;i++){
			scanf("%d", &val);
			if(i > log_val)
				sum += val;
		}
		printf("%d\n", sum);
	}
    return 0;
}
