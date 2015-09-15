#include<iostream>
#include<cstdio>
#include<cstdlib>
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
#define INF 100000000
#define SIZE 11

using namespace std;
char maze[SIZE][SIZE];
int a[] = {-2, -2, -1, 1, 2, 2, 1, -1}, b[] = {-1, 1, 2, 2, 1, -1, -2, -2}, visitedNodes;

void init(){
    for(int i=0;i<SIZE;i++)
        for(int j=0;j<SIZE;j++)
            maze[i][j] = '#';
}

void display(){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++)
            cout << maze[i][j];
        cout << endl;
    }
    cout << visitedNodes << endl;
    system("pause");
}

void dfs(int x, int y, int r, int c, int cntNodes){
    //cout << "visiting " << x << " " << y << endl;
    maze[x][y] = 'v';
    bool noRoute = true;
    for(int i=0;i<8;i++){
        int tmpX = x + a[i];
        int tmpY = y + b[i];
        if(in_range(tmpX, tmpY, r, c) && maze[tmpX][tmpY] == '.'){
            noRoute = false;
            //cout << "back to " << x << " " << y << endl;
            /*if(x == 0 && y == 0)
                cout << "at position " << i << endl;*/
            dfs(tmpX, tmpY, r, c, cntNodes + 1);
        }
    }
    if(noRoute){
        if(visitedNodes < cntNodes)
            visitedNodes = cntNodes;
        //display();
    }
    maze[x][y] = '.';
}

int main(){
    int r, x, y, cnt, cas=1;
    while(true){
        scanf("%d", &r);
        if(r == 0)
            break;
        init();
        cnt = 0;
        visitedNodes = -INF;
        for(int i=0;i<r;i++){
            scanf("%d%d", &x, &y);
            for(int j=x;j<x + y;j++){
                maze[i][j] = '.';
                cnt++;
            }
        }
        //display();
        dfs(0, 0, SIZE, SIZE, 1);
        int res = cnt - visitedNodes;
        if(res == 1)
            printf("Case %d, 1 square can not be reached.\n", cas++);
        else
            printf("Case %d, %d squares can not be reached.\n", cas++, res);
    }
    return 0;
}
