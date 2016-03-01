#include <cstdio>
#include <cstdlib>
#include <stack>
using namespace std;
int main(){
	int n;
	while(scanf("%d",&n)&&n){
		int a[n+5];
		while(1){
			bool chk=1,go=1;
			for(int i=0;i<n&&go;i++){
				scanf("%d",&a[i]);
				if(!a[i])go=0;
			}
			if(!go)break;
			stack<int> s;
			int cnt=1,i=0;
			while(i<n&&cnt<=n){
				if(s.empty()&&cnt<=n){
					s.push(cnt);
					cnt++;
				}
				if(a[i]==s.top()){
					s.pop();
					i++;
				}
				else{
					s.push(cnt);
					cnt++;
				}
			}
			i==n?puts("Yes"):puts("No");
		}
		puts("");
	}
}
