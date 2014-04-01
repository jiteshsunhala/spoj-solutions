#include<cstdio>
#include<cstring>
using namespace std;

int main(){
    char a[50][51];
    int n, t, cnt, max, node, i, j, k;
    scanf("%d", &t);
    while(t--){
        scanf("%s", a[0]);
        n = strlen(a[0]);
        for(i=1;i<n;i++)
            scanf("%s", a[i]);
	    max = node = 0;
	    for(i=0;i<n;i++){
	        cnt = 0;
	        for(j=0;j<n;j++){
	            if(i != j && a[i][j] == 'N'){
	                for(k=0;k<n;k++){
						if(a[i][k] == 'Y' && a[k][j] == 'Y'){
							cnt++;
							break;
						}
					}
				}
			}
			if(cnt > max){
				max = cnt;
				node = i;
			}
		}
		printf("%d %d\n", node, max);
	}
    return 0;
}
