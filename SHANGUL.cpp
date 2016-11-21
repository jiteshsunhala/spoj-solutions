#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<queue>
#include<stack>
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;

int cnt;

struct words{
	int x, y;
	char c[3];
}arr[10000];

void init(bool vis[40][521], int r, int c){
	
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			vis[i][j] = false;

}

void horizontal_symbol(int x, int y, int r, int c, char mat[40][521], bool vis[40][521]){
	
	int j;
	for(j=y;mat[x][j] == '#' && !vis[x][j] && j < c; j++)
		vis[x][j] = true;
	
	arr[cnt].x = x;
	arr[cnt].y = y;
	
	j--;
	if(in_range(x+1, j, r, c) && mat[x+1][j] == '#' && !vis[x+1][j]){
		for(int i=x+1;mat[i][j] == '#' && !vis[i][j] && i < r;i++)
			vis[i][j] = true;
		strcpy(arr[cnt].c, "g");
	}
	else{
		int m = (j+y)/2;
		for(int i=x+1;mat[i][m] == '#' && !vis[i][m] && i < r;i++)
			vis[i][m] = true;
		strcpy(arr[cnt].c, "u");
	}
	cnt++;
}

void vertical_symbol(int x, int y, int r, int c, char mat[40][521], bool vis[40][521]){
	
	int i;
	for(i=x;mat[i][y] == '#' && !vis[i][y] && i < r;i++)
		vis[i][y] = true;
		
	arr[cnt].x = x;
	arr[cnt].y = y;
	
	i--;
	
	//		for o
	
	if(in_range(i, y-1, r, c) && mat[i][y-1] == '#' && !vis[i][y-1] && in_range(i, y+1, r, c) && mat[i][y+1] == '#' && !vis[i][y+1]){
		
		int j;
		for(j=y+1; mat[i][j] == '#' && !vis[i][j] && j < c; j++)
			vis[i][j] = true;
		for(j=y-1; mat[i][j] == '#' && !vis[i][j] && j >= 0; j--)
			vis[i][j] = true;
		j++;
		arr[cnt].x = i;
		arr[cnt].y = j;
		strcpy(arr[cnt].c, "o");
	}
	
	else if(in_range(i, y+1, r, c) && mat[i][y+1] == '#' && !vis[i][y+1]){
		
		for(int j=y+1; mat[i][j] == '#' && !vis[i][j] && j < c; j++)
			vis[i][j] = true;
			
		strcpy(arr[cnt].c, "n");
	}
	else{
		
		int m = (x+i)/2;
		if(in_range(m, y+1, r, c) && mat[m][y+1] == '#' && !vis[m][y+1]){
			for(int j=y+1; mat[m][j] == '#' && !vis[m][j] && j < c; j++)
				vis[m][j] = true;
			strcpy(arr[cnt].c, "a");
		}
		else if(in_range(m, y-1, r, c) && mat[m][y-1] == '#' && !vis[m][y-1]){
			int j;
			for(j=y-1; mat[m][j] == '#' && !vis[m][j] && j >= 0; j--)
				vis[m][j] = true;
			j++;
			arr[cnt].x = m;
			arr[cnt].y = j;
			strcpy(arr[cnt].c, "eo");
		}
		else{
			strcpy(arr[cnt].c, "i");
		}
		
	}
	
	cnt++;
}

bool compare(words a, words b){
	
	if(a.x < b.x && a.y < b.y)
		return true;
	else if(a.x < b.x && a.y == b.y)
		return true;
	else if(a.x < b.x && a.y > b.y)
		return false;
	else if(a.x == b.x && a.y < b.y)
		return true;
	else if(a.x == b.x && a.y > b.y)
		return false;
	else if(a.x > b.x && a.y < b.y)
		return true;
	else if(a.x > b.x && a.y == b.y)
		return false;
	else if(a.x > b.x && a.y > b.y)
		return false;
	
	return false;
}

void display(char mat[40][521], bool vis[40][521], int r, int c){
	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(mat[i][j] == '#' && vis[i][j])
				printf("*");
			else if(mat[i][j] == '#' && !vis[i][j])
				printf("#");
			else
				printf(".");
		}
		printf("\n");
	}
	
	for(int i=0;i<cnt;i++)
		printf("%d %d: %s\n", arr[i].x, arr[i].y, arr[i].c);
}

int main(){
	
	int r, c;
	char mat[40][521];
	bool vis[40][521];
	while(true){
		scanf("%d%d", &r, &c);
		if(!r && !c)
			break;
		cnt = 0;
		for(int i=0;i<r;i++)
			scanf("%s", mat[i]);
		
		init(vis, r, c);
		
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(mat[i][j] == '#' && !vis[i][j]){
					
					//		first check for horizontal symbols.
					
					if(in_range(i, j+1, r, c) && mat[i][j+1] == '#' && !vis[i][j+1]){
						horizontal_symbol(i, j, r, c, mat, vis);
/*						display(mat, vis, r, c);
						system("pause");*/
					}
					
					//		second check for vertical symbols.
					if(in_range(i+1, j, r, c) && mat[i+1][j] == '#' && !vis[i+1][j]){
						vertical_symbol(i, j, r, c, mat, vis);
/*						display(mat, vis, r, c);
						system("pause");*/
					}
				}
			}
		}
		
		sort(arr, arr+cnt, compare);
//		display(mat, vis, r, c);

		for(int i=0;i<cnt;i++)
			printf("%s", arr[i].c);
		printf("\n");
	}
//    system("pause");
    return 0;
}
