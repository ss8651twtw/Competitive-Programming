#include <bits/stdc++.h>
using namespace std;
int ar[205], dp[205][205];
int run(int p, int q){
    if(dp[p][q] != 0)return dp[p][q];
    if(p == q)return dp[p][q] = 1;
    if(ar[p] == ar[q])return dp[p][q] = min(run(p + 1, q), run(p, q - 1));
    if(ar[p] == ar[p + 1])return dp[p][q] = run(p + 1, q);
    if(ar[q] == ar[q - 1])return dp[p][q] = run(p, q - 1);
    int MIN = 2147483647;
    for(int i = p; i < q; i++)
        MIN = min(MIN, run(p, i) + run(i + 1, q));
    return dp[p][q] = MIN;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        memset(dp, 0, sizeof(dp));
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; i++)cin >> ar[i];
        cout << run(0, n - 1) << endl;
    }
}
