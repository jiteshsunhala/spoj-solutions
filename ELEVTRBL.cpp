#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#define INF 100000000
#define in_range(x, f) (x >= 1 && x <= f)

using namespace std;
vector<int> dis;

void bfs(int f, int s, int g, int u, int d){
    dis.resize(f + 1);
    fill(dis.begin(), dis.end(), INF);
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int floor = q.front();
        q.pop();
        if(floor == g)
            return;
        if(in_range(floor + u, f) && dis[floor + u] > dis[floor] + 1){
            dis[floor + u] = dis[floor] + 1;
            q.push(floor + u);
        }
        if(in_range(floor - d, f) && dis[floor - d] > dis[floor] + 1){
            dis[floor - d] = dis[floor] + 1;
            q.push(floor - d);
        }
    }
}

int main(){
    int f, s, g, u, d;
    scanf("%d%d%d%d%d", &f, &s, &g, &u, &d);
    bfs(f, s, g, u, d);
    if(dis[g] == INF)
        printf("use the stairs");
    else
        printf("%d", dis[g]);
    return 0;
}
