#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;

int main(){
    
    stack<char> mystack;
    char str[2001];
    int i=0, cnt;
    while(1){
        scanf("%s", str);
        if(str[0] == '-')
            break;
        i++;
        cnt = 0;
        printf("%d. ", i);
        
        for(int j=0;j<strlen(str);j++){
            
            if(str[j] == '{')
                mystack.push('{');
            else{
                if(mystack.empty()){
                    cnt++;
                    mystack.push('{');
                }
                else
                    mystack.pop();
            }
        }
        
        while(!mystack.empty()){
            cnt++;
            mystack.pop();
            mystack.pop();
        }
        
        printf("%d\n", cnt);
    }
    return 0;
}
