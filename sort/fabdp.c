#include<stdio.h>
#include<stdlib.h>
int **fun;
int fabi(int n){
	if(fun[0][n]==1)
		return fun[1][n];
	if(n==0){
		printf("0 ");
		fun[0][0]=1;
		fun[0][1]=0;
		return 0;
	}
	else if(n==1){
		printf("1 ");
		fun[1][0]=1;
		fun[1][1]=1;
		return 1;
	}
	else{
		int f=fabi(n-2)+fabi(n-1);
		fun[0][n]=1;
		fun[1][n]=f;
		printf("%d ",f);
		return f;
	}
}
int main(){
	int n=11;
	fun=calloc(2,sizeof(int*));
	for(int i=0;i<2;i++)
		fun[i]=calloc(n,sizeof(int));
	printf("\nsum of first %d fabii= %d",n,fabi(n-1));
}
