#include <cstdio>
#include <set>
using namespace std;
set<int> s;
int a[10005]={0};
int main(){
	int n,cnt=0;
	while(scanf("%d",&n)&&n){
		if(cnt&&n==-1){
			int tmp=*s.begin();
			printf("%d ",tmp);
			a[tmp]--;
			if(!a[tmp])s.erase(tmp);
			cnt--;
		}
		else if(cnt&&n==-2){
			int tmp=*s.rbegin();
			printf("%d ",tmp);
			a[tmp]--;
			if(!a[tmp])s.erase(tmp);
			cnt--;
		}
		else if(n!=-1&&n!=-2){
			s.insert(n);
			a[n]++;
			cnt++;
		}
	}
}




