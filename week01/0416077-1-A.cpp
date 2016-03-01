#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)&&(n||m)){
		char s[70];
		scanf("%s",s);
		long long tmp=0;
		bool chk=0;
		int len=strlen(s);
		for(int i=0;i<len;i++){
			if(s[i]=='-'){
				chk=1;
				continue;
			}
			if(s[i]>='0'&&s[i]<='9')tmp=tmp*n+s[i]-'0';
			else tmp=tmp*n+s[i]-'A'+10;
		}
		char ans[70]={0};
		len=0;
		while(tmp>0){
			int num=tmp%m;
			ans[len]=(num>9)?(num-10+'A'):(num+'0');
			tmp/=m;
			len++;
		}
		if(chk)putchar('-');
		for(int i=len-1;i>=0;i--)putchar(ans[i]);
		puts("");
	}
}

