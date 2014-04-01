#include<cstdio>
#define in_range(i, j, r, c) (i >= 0 && j >= 0 && i < r && j < c)
using namespace std;

int count;

void dfs(int mat[250][250], bool visited[250][250], int i, int j, int r, int c){
	
	visited[i][j] = true;
	count++;
	
	if(in_range(i-1, j, r, c) && mat[i-1][j] == 1 && !visited[i-1][j])
		dfs(mat, visited, i-1, j, r, c);
		
	if(in_range(i+1, j, r, c) && mat[i+1][j] == 1 && !visited[i+1][j])
		dfs(mat, visited, i+1, j, r, c);
	
	if(in_range(i, j-1, r, c) && mat[i][j-1] == 1 && !visited[i][j-1])
		dfs(mat, visited, i, j-1, r, c);
		
	if(in_range(i, j+1, r, c) && mat[i][j+1] == 1 && !visited[i][j+1])
		dfs(mat, visited, i, j+1, r, c);
	
}

int main(){
	
	int no_of_results[62501], mat[250][250], r, c, tot_count;
	bool visited[250][250];
	
	while(true){
		scanf("%d%d", &r, &c);
		if(!r && !c)
			break;
		tot_count = 0;
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++){
				visited[i][j] = false;
				scanf("%d", &mat[i][j]);
				no_of_results[i*c+j+1] = 0;
			}
		
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(mat[i][j] == 1 && !visited[i][j]){
					count = 0;
					tot_count++;
					dfs(mat, visited, i, j, r, c);
					no_of_results[count]++;
				}
			}
		}
		printf("%d\n", tot_count);
		for(int i=1;i<=r*c;i++){
			if(no_of_results[i] > 0)
				printf("%d %d\n", i, no_of_results[i]);
		}
		
	}
    return 0;
}
