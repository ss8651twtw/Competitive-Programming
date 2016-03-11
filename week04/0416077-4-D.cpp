#include<cstdio>
#include <cstdlib>
#include<algorithm>
using namespace std;
int a,b,gcd,x,y,A,B;
long long ans;
inline int exgcd(int a,int b,int &x,int &y){
    int d=a;
    if(b){
    	d=exgcd(b,a%b,y,x);
    	y-=a/b*x;
	}
    else x=1,y=0;
    return d;
}
int main(){
    scanf("%d%d",&x,&y);
    if(x<y)swap(x,y);
    if(y==1){
		printf("%d\n",x==1?1:2);
		return 0;
	}
    int gcd=exgcd(x,y,a,b);
    ans=1LL*x*y/gcd;
    if(gcd>1){
        printf("%I64d",ans);
        return 0;
    }
    if(a>0)ans=min(ans,1LL*a*x);
    else ans=min(ans,1LL*b*y);
    printf("%I64d\n",ans);
}
