#include <cstdio>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		long long x,y;
		scanf("%lld%lld",&x,&y);
		char s[5];
		while(scanf("%s",s)){
			if(s[0]=='E')break;
			int tmp;
			scanf("%d",&tmp);
			switch(s[0]){
				case 'L':x-=tmp;break;
				case 'U':y+=tmp;break;
				case 'R':x+=tmp;break;
				case 'D':y-=tmp;break;
			}
		}
		printf("%lld %lld\n",x,y);
	}
} 

