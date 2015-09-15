#include<cstdio>
#define SIZE 1500
using namespace std;

char mat[SIZE][SIZE * 2];

void display(int maxRow, int maxCol){
    for(int i=0;i<maxRow;i++){
        for(int j=0;j<maxCol;j++)
            printf("%c", mat[i][j]);
        printf("\n");
    }
}

void prepareTraingleUtil(int startRow, int endRow, int startCol, int endCol, int size){
    if(size == 0)
        return;
    int startX = startRow;
    int startY = (startCol + endCol) / 2;
    for(int x = startX, y = startY, z = startY + 1;x <= endRow;x++, y--, z++){
        mat[x][y] = '/';
        mat[x][z] = '\\';
    }
    for(int y = startCol + 1;y < endCol;y++)
        mat[endRow][y] = '_';
    int midRow = (startRow + endRow) / 2;
    int rowDiff = midRow - startRow;
    //  top triangle
    prepareTraingleUtil(startRow, midRow, startY - rowDiff, startY + 1 + rowDiff, size - 1);
    //  left triangle
    prepareTraingleUtil(midRow + 1, endRow, startCol, startY, size - 1);
    //  right triangle
    prepareTraingleUtil(midRow + 1, endRow, startY + 1, endCol, size - 1);
    //display(endRow + 1, endCol + 1);
}

void prepareTriangle(int n){

    int maxRow = 1 << n;
    int maxCol = maxRow << 1;
    for(int i=0;i<maxRow;i++)
        for(int j=0;j<maxCol;j++)
            mat[i][j] = ' ';
    prepareTraingleUtil(0, maxRow - 1, 0, maxCol - 1, n);
    display(maxRow, maxCol);
}

int main(){

    int n;
    while(true){
        scanf("%d", &n);
        if(n == 0)
            break;
        prepareTriangle(n);
        printf("\n");
    }
    return 0;
}
