#include<stdio.h>

int compare (const void * a, const void * b){
    return ( *(int*)a - *(int*)b );
}

int main(){
    
    int j, i, a[1000], b[1000], t, n1, n2, min, diff;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n1);
        for(i=0;i<n1;i++)
            scanf("%d", &a[i]);
        scanf("%d", &n2);
        for(i=0;i<n2;i++)
            scanf("%d", &b[i]);
            
        qsort(a, n1, sizeof(int), compare);
        qsort(b, n2, sizeof(int), compare);
        
/*        for(i=0;i<n1;i++)
            printf("%d ", a[i]);
        printf("\n");
        for(i=0;i<n2;i++)
            printf("%d ", b[i]);
        printf("\n");*/
        
        min = 1000000;
        for(i=0;i<n1;i++){
            for(j=0;j<n2;j++){
                diff = a[i] - b[j];
                if(diff < 0)
                    diff *= (-1);
                    
                if(diff < min)
                    min = diff;
            }
        }
        
        printf("%d\n", min);
    }
    return 0;
}
