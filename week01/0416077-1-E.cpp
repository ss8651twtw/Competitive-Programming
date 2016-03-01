#include <cstdio>
#include <vector>
#define N 46341
using namespace std;
int main(){
	bool sieve[N]={0};
	vector<int> p;
	for(int i=2;i<N;i++){
		if(!sieve[i])p.push_back(i);
		for(int j=0;i*p[j]<N;j++){
			sieve[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
	int psize=p.size(),t;
	scanf("%d",&t);
	while(t--){
		int tmp;
		scanf("%d",&tmp);
		if(tmp<2){
			puts("no");
			continue;
		}
		bool chk=0;
		for(int i=0;i<psize&&p[i]*p[i]<=tmp;i++)
			if(tmp%p[i]==0){
				chk=1;
				break;
			}
		chk?puts("no"):puts("yes");
	}
} 

