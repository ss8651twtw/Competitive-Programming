#include <cstdio>
using namespace std;
int main(){
	char c;
	while((c=getchar())!=EOF){
		long long sum=0;
		ungetc(c,stdin);
		while((c=getchar())!='\n'){
			if(c==' ')continue;
			if(c=='-'||(c>='0'&&c<='9')){
				ungetc(c,stdin);
				int tmp;
				scanf("%d",&tmp);
				sum+=tmp;
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}

