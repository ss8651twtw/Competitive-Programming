#include <cstdio>
int go(int tmp){
    unsigned long long ans=1,base=3;
    while(tmp!=0){
        if(tmp&1)ans=(ans*base)%100000007;
        base=(base*base)%100000007;
        tmp>>=1;
    }
    return (int)ans;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int tmp;
		scanf("%d",&tmp);
		printf("%d\n",go(tmp)-1);
	}
} 
