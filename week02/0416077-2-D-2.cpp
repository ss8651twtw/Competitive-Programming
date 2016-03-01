#include <cstdio>
#include <iostream>
#include <string>
#include <set>
using namespace std;
set<string> ans;
int chk(int tmp){
	if(tmp<10)return tmp;
	int ans=0;
	do{
		ans+=tmp%10;
		tmp/=10;
	}while(tmp>0);
	return chk(ans);
}
void go(string s,int n,int num){
	string tmp=s,a="0123456789";
	for(int i=0;i<n;i++){
		ans.insert(tmp.insert(i,a,num,1));
		tmp=s;
	}
}
int main(){
	int n,r,tmp=0;
	string s;
	scanf("%d%d",&n,&r);getchar();
	getline(cin,s);
	for(int i=0;i<n-1;i++)tmp+=s[i]-'0';
	for(int i=0;i<10;i++)
		if(chk(tmp+i)==r)
			go(s,n,i);
	set<string>::iterator itr=ans.begin();
	ans.erase(itr);
	itr=ans.end();
	itr--;
	ans.erase(itr);
	for(itr=ans.begin();itr!=ans.end();itr++)puts(itr->c_str());
}
