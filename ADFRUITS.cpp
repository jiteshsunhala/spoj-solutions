#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

bool sArr[105], tArr[105];
char s[105], t[105], res[210];
int sLength, tLength, matrix[105][105];

void prepareBoolArray(){
    fill(sArr, sArr + sLength, false);
    fill(tArr, tArr + tLength, false);
    for(int i=0;i<=sLength;i++)
        matrix[i][0] = 0;
    for(int j=0;j<=tLength;j++)
        matrix[0][j] = 0;
    for(int i=1;i<=sLength;i++){
        for(int j=1;j<=tLength;j++){
            if(s[i-1] == t[j-1])
                matrix[i][j] = matrix[i-1][j-1] + 1;
            else
                matrix[i][j] = max(matrix[i-1][j], matrix[i][j-1]);
        }
    }
    /*
    for(int i=0;i<=sLength;i++){
        for(int j=0;j<=tLength;j++){
            printf("%2d", matrix[i][j]);
        }
        printf("\n");
    }*/
    int x = sLength, y = tLength;
    while(true){
        if(x == 0 || y == 0)
            break;
        if(s[x-1] == t[y-1]){
            sArr[x-1] = true;
            tArr[y-1] = true;
            x--;y--;
        }
        else
            (matrix[x-1][y] >= matrix[x][y-1]) ? (x--) : (y--);
    }/*
    for(int i=0;i<sLength;i++)
        cout << sArr[i] << " ";
    cout <<endl;
    for(int i=0;i<tLength;i++)
        cout << tArr[i] << " ";
    cout <<endl;
    */
}

int main(){
    while(scanf("%s", s) != EOF){
        scanf("%s", t);
        sLength = strlen(s), tLength = strlen(t);
        prepareBoolArray();
        int i = 0, j = 0, idx = 0;
        while(i < sLength && j < tLength){
            int k = i, l = j;
            for(;k < sLength && !sArr[k];k++)
                res[idx++] = s[k];
            for(;l < tLength && !tArr[l];l++)
                res[idx++] = t[l];
            while(k < sLength && l < tLength && sArr[k] && tArr[l] && s[k] == t[l]){
                res[idx++] = s[k];
                k++;
                l++;
            }
            i = k;
            j = l;
        }
        while(i < sLength)
            res[idx++] = s[i++];
        while(j < tLength)
            res[idx++] = t[j++];
        res[idx] = 0;
        printf("%s\n", res);
    }
}
