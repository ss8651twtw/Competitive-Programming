#include <cstdio>
#include <map>
using namespace std;
map<int,int> p;
int main(){
	int n,cnt=0;
	while(scanf("%d",&n)&&n){
		if(cnt&&n==-1){
			map<int,int>::iterator itr=p.begin();
			printf("%d ",itr->first);
			itr->second--;
			if(!itr->second)p.erase(itr->first);
			cnt--;
		}
		else if(cnt&&n==-2){
			map<int,int>::reverse_iterator itr=p.rbegin();
			printf("%d ",itr->first);
			itr->second--;
			if(!itr->second)p.erase(itr->first);
			cnt--;
		}
		else if(n!=-1&&n!=-2){
			p[n]++;
			cnt++;
		}
	}
}
