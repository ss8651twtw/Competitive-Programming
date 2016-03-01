#include <cstdio>
#include <algorithm>
using namespace std;
int a[10005];
int main(){
	int n;
	while(scanf("%d",&n)&&n){
		int cnt=n,sum=0;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		sort(a,a+n);
		for(int i=n-1;i>=0;i--){
			sum-=a[i];
			if(sum>=a[i])break;
			cnt--;
		}
		cnt==1?puts("0"):printf("%d\n",cnt);
	}
}
