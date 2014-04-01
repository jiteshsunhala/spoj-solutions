#include<cstdio>
#include<iostream>
#define scan(n) n=0;while((c = getchar_unlocked()) != 10 && c != EOF && c != ' '){n*=10;n+=(c-48);}
using namespace std;
 
int minval, val, cnt1, cnt2, check1[811], check2[811];
bool intersect;
 
int init(){
    for(int i=0;i<811;i++)
        check1[i] = check2[i] = -1;
    return 0;
}
 
int nextnum(int a){
    int m=0, r;
    while(a){
        r = a%10;
        m += (r*r);
        a /= 10;
    }
    return m;
}
 
int first(int a){
    while(1){
        if(a == 1 || check1[a] > 0)
            break;
        cnt1++;
        check1[a] = cnt1;
        a = nextnum(a);
    }
    if(a == 1){
		cnt1++;
		check1[a] = cnt1;
	}
    return 0;
}
 
void second(int b){
	intersect = false;
    while(1){
        cnt2++;
        if(check1[b] > 0){
			val = check1[b];
			intersect = true;
			if((val+cnt2) < minval)
				minval = val+cnt2;
		}
        if(b == 1 || check2[b] > 0)
            break;
        check2[b] = cnt2;
        b = nextnum(b);
    }
}
 
int main(){
    int a, b, c;
    while(1){
        scanf("%d%d", &a, &b);
        cnt1 = cnt2 = 1;
        minval = 10000000;
        if(!a && !b)
            break;
        if(a==b){
            printf("%d %d %d\n", a, b, cnt1+cnt2);
        }else if(a < 811 && b < 811){
            init();
            check1[a] = cnt1;
            check2[b] = cnt2;
            first(nextnum(a));
            if(check1[b] > 0){
				val = check1[b];
                printf("%d %d %d\n", a, b, val + cnt2);
			}
            else{
                second(nextnum(b));
                if(intersect)
                    printf("%d %d %d\n", a, b, minval);
                else
                    printf("%d %d 0\n", a, b);
            }
        }else if(a < 811){
            init();
            check1[a] = cnt1;
            first(nextnum(a));
            second(nextnum(b));
            if(intersect)
                printf("%d %d %d\n", a, b, minval);
            else
                printf("%d %d 0\n", a, b);
        }else if(b < 811){
            init();
            check1[b] = cnt1;
            first(nextnum(b));
            second(nextnum(a));
            if(intersect)
                printf("%d %d %d\n", a, b, minval);
            else
                printf("%d %d 0\n", a, b);
        }else{
            init();
            first(nextnum(a));
            second(nextnum(b));
            if(intersect)
                printf("%d %d %d\n", a, b, minval);
            else
                printf("%d %d 0\n", a, b);
        }
    }
    return 0;
}
