#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int match(char *,char *);
int main(){
	char *str,*pat;
/*	printf("Enter string :");
	gets(str);
	printf("Enter pattern to search: ");
	gets(pat);
	printf("%s %s\n",str,pat);
*/
	str="abababcabcd";
	pat="ac";
	printf("%d",match(str,pat));	
}
int match(char *str,char *pat){
	int i,j,k;
	int l1=strlen(str);
	int l2=strlen(pat);
	for(i=0;i<=l1-l2;i++){
		k=i;
		j=0;
		while(str[k]==pat[j]&&j<l2){
			if(j==l2-1) return i;
			k++;
			j++;
		}
	}
	return -1;
}
