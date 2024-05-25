#include<stdio.h>
#include<stdlib.h>
int *arr,n;
void sumsub(int *,int,int);
int main(){
	int sum;
	printf("Enter no of elements: ");
	scanf("%d",&n);
	arr=calloc(n,sizeof(int));
	printf("Enter elements: ");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("enter sum to find: ");
	scanf("%d",&sum);
	int *sol=calloc(n,sizeof(int));
	sumsub(sol,0,sum);
}
void sumsub(int *s,int ind,int sum){
	if(sum==0){
		for(int i=0;i<n;i++)
			printf("%d ",s[i]);
		printf("\n");
		return;
	}
	else if(sum<0||ind==n) return;
	s[ind]=1;
	sumsub(s,ind+1,sum-arr[ind]);
	s[ind]=0;
	sumsub(s,ind+1,sum);
}


/*void sumsub(int *s,int tot,int ind,int sum){
	if(tot==sum){
		for(int i=0;i<n;i++)
			printf("%d ",s[i]);
		printf("\n");
		return;
	}
	else if(tot>sum||ind==n) return;
	s[ind]=1;
	sumsub(s,tot+arr[ind],ind+1,sum);
	s[ind]=0;
	sumsub(s,tot,ind+1,sum);
}*/
