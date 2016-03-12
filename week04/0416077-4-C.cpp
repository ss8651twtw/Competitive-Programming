#include <cstdio>
#include <cstring>
#include <algorithm>
#define M 100005
using namespace std;
int n,a[M],b[M];
long long ans;
void divide(int,int);
void conquer(int,int);
void divide(int l,int r){
    int mid=(l+r)/2;
    if(l==r)return;
    if(r!=mid)divide(l,mid);
    if(l!=mid)divide(mid,r);
    conquer(l,r);
}
void conquer(int l,int r){
    if(l==r-1){
        b[l]=a[l];
        return;
    }
    int mid=(l+r)/2;
    int p=l,q=mid;
    for(int i=l;i<r;i++){
        if(p==mid)b[i]=a[q++];
        else if(q==r)b[i]=a[p++];
        else if(a[p]<=a[q])b[i]=a[p++];
        else if(a[p]>a[q])b[i]=a[q++],ans+=mid-p;
    }
    for(int i=l;i<r;i++)a[i]=b[i];
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ans=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        divide(0,n);
        printf("%lld\n",ans);
    }
}