#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int t;
LL a[100005],tmp[100005], n, w, m, l, r;
bool go(LL x){
    for(int i = 0; i < n; i++)tmp[i] = (a[i] + x - 1) / x;
    LL cnt = 0;
    for(int i = 0; i < n; i++){
        LL mis = tmp[i];
        if(mis > 0){
            for(int j = 0; j < w && i + j < n; j++)tmp[i + j] -= mis;
            cnt += mis;
        }
        if(cnt > m)return 0;
    }
    return 1;
}
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%lld%lld%lld", &n, &w, &m);
        LL ma = 0;
        for(int i = 0; i < n; i++){
            scanf("%lld", a + i);
            ma = max(ma, a[i]);
        }
        l = 1;
        r = ma;
        int cnt = 0;
        bool chk = 0;
        for(int i = 0; i < n; i++){
            if(a[i])i += w - 1, cnt++;
            if(cnt > m)chk = 1;
        }
        if(chk){
            puts("-1");
            continue;
        }
        if(!cnt){
            puts("0");
            continue;
        }
        while(l < r){
            int mid = (l + r) / 2;
            if(go(mid))r = mid;
            else l = mid + 1;
        }
        printf("%lld\n", l);
    }
}
