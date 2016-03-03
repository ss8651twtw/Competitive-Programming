#include <cstdio>
#include <vector>
#include <algorithm>
#define GET(x,y) (x)*(x)+(y)*(y)
#define REP(x,n) for(int x=0;x<n;x++)
#define PB push_back 
using namespace std;
struct num{
	int i,j,val;
	num(){}
	num(int a,int b,int c){
		i=a;j=b;val=c;
	}
	bool operator<(const num &tmp){
		if(i==tmp.i)return j<tmp.j;
		return val<tmp.val;
	}
};
bool cmp(const num tmp,const int val){
	return tmp.val<val;
}
bool vis[130000];
vector<num> v;
int main(){
	REP(i,255)REP(j,255)
		if(!vis[GET(i,j)])v.PB(num(i,j,GET(i,j))),vis[GET(i,j)]=true;
	sort(v.begin(),v.end());
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		bool chk=true;
		REP(i,n){
			int tmp=n-i*i;
			if(tmp<0)break;
			vector<num>::iterator itr=lower_bound(v.begin(),v.end(),tmp,cmp);
			if(tmp==itr->val){
				printf("%d %d %d\n",i,itr->i,itr->j);
				chk=false;
				break;
			}
		}
		if(chk)puts("-1");
	}
} 
