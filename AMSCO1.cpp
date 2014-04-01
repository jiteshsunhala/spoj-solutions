#include<cstdio>
#include<cstring>
using namespace std;

int main(){
	
	char min, msg[300], key[20], mat[250][9];
	int key_len, len[9], msg_len, index;
	bool two, row_flag;
	while(scanf("%s%s", key, msg) != EOF){
		key_len = strlen(key);
		msg_len = strlen(msg);
		two = row_flag = true;
		for(int i=0;i<key_len;i++){
			len[i] = 0;
		}
		int j=0;
		for(int i=0;i<msg_len;){
			if(two){
				two = false;
				if(i+2 <= msg_len){
					mat[len[j]][j] = msg[i];
					mat[len[j] + 1][j] = msg[i+1];
					i+=2;
					len[j]+=2;
				}
				else{
					mat[len[j]][j] = msg[i];
					i++;
					len[j]++;
				}
			}
			else{
				two = true;
				mat[len[j]][j] = msg[i];
				i++;
				len[j]++;
			}
			j = (j+1) % key_len;
			if(j==0){
				two = !row_flag;
				row_flag = !row_flag;
			}
		}
		/*
		int tmp[9];
		for(int j=0;j<key_len;j++){
			tmp[j] = 0;
		}
		for(int j=0;j<key_len;j++){
			for(int i=0;i<len[j];i++){
				printf("%c ", mat[i][j]);
			}
			printf("\n");
		}
		*/
		for(int i=0;i<key_len;i++){
			min = key[0];
			index = 0;
			for(int j=0;j<key_len;j++){
				if(key[j] < min){
					min = key[j];
					index = j;
				}
			}
			key[index] = 'A';
			for(int j=0;j<len[index];j++)
				printf("%c", mat[j][index]);
		}
		printf("\n");
	}
    return 0;
}
