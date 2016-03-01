#include <cstdio>
#include <set>
using namespace std;
multiset<int> s;
int main(){
	int n,cnt=0;
	while(scanf("%d",&n)&&n){
		if(cnt&&n==-1){
			multiset<int>::iterator itr=s.begin();
			printf("%d ",*itr);
			s.erase(itr);
			cnt--;
		}
		else if(cnt&&n==-2){
			multiset<int>::iterator itr=s.end();
			printf("%d ",*(--itr));
			s.erase(itr);
			cnt--;
		}
		else if(n!=-1&&n!=-2){
			s.insert(n);
			cnt++;
		}
	}
}

