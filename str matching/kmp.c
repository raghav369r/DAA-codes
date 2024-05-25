#include<stdio.h>
#include<string.h>
int kmp(char *,char *);
int main(){
	char *str,*pat;
	str="abababcabcd";
	pat="ababd";
	printf("\n%d",kmp(str,pat));
	//printf("%s %s",str,pat);
}
int kmp(char *str,char *pat){
	int i,j,k,l1,l2;
	l1=strlen(str);
	l2=strlen(pat);
	int pi[l2];
	pi[0]=0;
	for(i=1;i<l2;){
		j=0;
		while(pat[i]==pat[j]){
			pi[i]=j+1;
			j++;
			i++;
		}
		if(j==0) pi[i++]=0;
	}
	//for(i=0;i<l2;i++) printf("%d ",pi[i]);
	for(i=-1,j=0;i<l2;){
		while(1){
			if(pat[j]==str[i+1]){
				i++;
				j++;
			}
		}
		if()	
	}
}
