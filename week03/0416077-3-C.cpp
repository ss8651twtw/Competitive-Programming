#include <cstdio>
#include <cstring>
#include <algorithm>
#define out(i,j) ((i)<0||(i)>9||(j)<0||(j)>9)
using namespace std;
char map[10][10];
int st;
inline char line(char c){
	return c=='O'?'#':'O';
}
void change(char (&s)[10][10],int i,int j){
	s[i][j]=line(s[i][j]);
	if(!out(i-1,j))s[i-1][j]=line(s[i-1][j]);
	if(!out(i+1,j))s[i+1][j]=line(s[i+1][j]);
	if(!out(i,j-1))s[i][j-1]=line(s[i][j-1]);
	if(!out(i,j+1))s[i][j+1]=line(s[i][j+1]);
}
int sol(){
	char tmp[10][10];
	memcpy(tmp,map,sizeof(map));
	int cnt=0;
	bool chk=true;
	for(int i=1,j=0;i<1024;i<<=1,j++)if(i&st)change(tmp,0,j),cnt++;
	for(int i=1;i<10;i++)
		for(int j=0;j<10;j++)
			if(tmp[i-1][j]=='O')
				change(tmp,i,j),cnt++;
	for(int i=0;i<10;i++)if(tmp[9][i]=='O')chk=false;
	return chk?cnt:1000;
}
int main(){
	char s[100];
	while(scanf("%s",s)){
		if(!strcmp(s,"end"))break;
		for(int i=0;i<10;i++)scanf("%s",map[i]);
		printf("%s ",s);
		st=0;
		int sum=1000,ma=1024;
		while(st<ma){
			sum=min(sum,sol());
			st++;
		}
		printf("%d\n",sum>100?-1:sum);
	}
} 
