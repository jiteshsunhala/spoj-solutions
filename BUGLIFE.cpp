#include<cstdio>

int main(){
	char a[20][20];
	int cnt=1, x, y, n, m, t;
	scanf("%d", &t);
	while(cnt <= t){
		scanf("%d%d", &n, &m);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j)
					a[i][j] = 'o';
				else
					a[i][j] = 'n';
			}
		}
		
		while(m--){
			scanf("%d%d", &x, &y);
			x--;
			y--;
			a[x][y] = 'v';
			a[y][x] = 'v';
		}
		/*
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				printf("%c", a[i][j]);
			printf("\n");
		}
		printf("\n\n");*/
		bool flag = true;
		for(int i=0;i<n;i++){
			if(a[i][i] == 'o')
				a[i][i] = 'm';
			for(int j=0;j<n;j++){
				if(a[i][j] == 'v'){
					if(a[i][i] == 'm' && a[j][j] == 'o')
						a[j][j] = 'f';
					else if(a[i][i] == 'f' && a[j][j] == 'o')
						a[j][j] = 'm';
					else if((a[i][i] == 'm' && a[j][j] != 'f') || (a[i][i] == 'f' && a[j][j] != 'm')){
						flag = false;
						break;
					}
				}
			}
			
			if(!flag)
				break;
		}
		/*
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				printf("%c", a[i][j]);
			printf("\n");
		}
		printf("\n\n");*/
		
		printf("Scenario #%d:\n", cnt);
		cnt++;
		if(flag)
			printf("No suspicious bugs found!\n");
		else
			printf("Suspicious bugs found!\n");
	}
	return 0;
}
