#include<stdio.h>
#include<stdlib.h>
void nqueens(int *,int,int);
int isavilable(int *,int,int);

int main(){
	int n;
	printf("Enter no of queens: ");
	scanf("%d",&n);
	int *q=calloc(n,sizeof(int));
	nqueens(q,0,n);
}
void nqueens(int *q,int l,int n){
	if(l==n){
		for(int i=0;i<n;i++)
			printf("%d ",q[i]);
		printf("\n");
		return;
	} 
	int i,j;
	for(i=0;i<n;i++){
		if(isavilable(q,i,l)){
			q[l]=i;
			nqueens(q,l+1,n);
		}
	}
	return;  //
}
int isavilable(int *q,int p,int l){
	if(l==0) return 1;
	for(int i=0;i<l;i++){
		if(p==q[i]||p==q[i]+l-i||p==q[i]-l+i) return 0;
	}
	return 1;
}