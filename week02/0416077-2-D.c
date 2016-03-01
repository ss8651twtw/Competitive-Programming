#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n,r;
char in[35],tmp[35];
struct num{
	char key[35];
}ans[500];
int cmp(const void *a,const void *b){
	const struct num *p1=a,*p2=b;
	return strcmp(p1->key,p2->key);
}
int getnum(char *s){
	int len=strlen(s),sum=0,i;
	for(i=0;i<len;i++)sum+=s[i]-'0';
	return sum;
}
int root(int n){
	if(n<10)return n;
	int sum=0;
	while(n>0){
		sum+=n%10;
		n/=10;
	}
	root(sum);
}
char *chg(char *in,int pos,int n){
	memset(tmp,0,sizeof(tmp));
	strcpy(tmp,in);
	int len=strlen(tmp),i;
	for(i=len;i>pos;i--)tmp[i]=tmp[i-1];
	tmp[pos]=n+'0';
	return tmp;
}
int main(){
	int i,j;
	scanf("%d%d%s",&n,&r,in);
	for(i=0;i<10;i++)
		for(j=0;j<n;j++)
			strcpy(ans[i+j*10].key,chg(in,j,i));
	qsort(ans,10*n,sizeof(struct num),cmp);
	int end=n*10;
	j=0;
	char fin[end][35],pre[35]={0};
	memset(fin,0,sizeof(fin));
	for(i=0;i<end;i++)
		if(root(getnum(ans[i].key))==r&&strcmp(pre,ans[i].key)){
			memset(pre,0,sizeof(pre));
			strcpy(pre,ans[i].key);
			strcpy(fin[j++],ans[i].key);
		}
	for(i=1;i<j-1;i++)puts(fin[i]);
}
