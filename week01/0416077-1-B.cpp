#include <cstdio>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        long long s[n+1];
        s[0]=0;
        for(int i=1;i<=n;i++){
            int tmp;
            scanf("%d",&tmp);
            s[i]=s[i-1]+tmp;
        }
        while(m--){
            int l,r;
            scanf("%d%d",&l,&r);
            printf("%lld\n",s[r]-s[l-1]);
        }
    }
}

