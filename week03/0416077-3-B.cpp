#include <cstdio>
#include <algorithm>
#include <set>
#include <string>
#include <cstring>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
struct num{
	char s[10000],order[10000];
	num(){
		memset(s,0,sizeof(s));
		memset(order,0,sizeof(order));
	}
	bool operator<(const num &a)const{
		return strcmp(order,a.order)<0;
	}
};
int main(){
	int n,t;
	while(scanf("%d%d",&n,&t)&&(n||t)){
		printf("Sums of %d:\n",n);
		set<num> ans;
		bool chk=true;
		int a[t],st=1,ma=1<<t;
		for(int i=0;i<t;i++)scanf("%d",&a[i]);
		sort(a,a+t,cmp);
		while(st<ma){
			int sum=0;
			for(int i=1,cnt=0;i<ma;i<<=1,cnt++)if(i&st)sum+=a[cnt];
			if(sum==n){
				num tmp;
				int ord=0;
				chk=false;
				bool f=true;
				for(int i=1,cnt=0;i<ma;i<<=1,cnt++){
					if(!(i&st))continue;
					char cat[50]={0};
					if(f){
						sprintf(cat,"%d",a[cnt]);
						f=false;
					}
					else sprintf(cat,"+%d",a[cnt]);
					strcat(tmp.s,cat);
					tmp.order[ord++]=a[cnt];
				}
				ans.insert(tmp);
			}
			st++;
		}
		if(chk)puts("NONE");
		else{
			set<num>::reverse_iterator rit;
			for(rit=ans.rbegin();rit!=ans.rend();rit++)puts(rit->s);
		}
	}
}
