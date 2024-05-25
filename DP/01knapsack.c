#include<stdio.h>
#include<stdlib.h>
int knapsack(int m,int *w,int *p,int n){
	int arr[n+1][m+1],i,j,q;
	for(i=0;i<=m+1;i++) arr[0][i]=0;
	for(i=1;i<=n;i++){
		arr[i][0]=0;
		for(j=1;j<m+1;j++){
			arr[i][j]=arr[i-1][j];			//if(w[i]<=j && p[i]+arr[i-1][j-w[i]]>arr[i-1][j])
			if(w[i]<=j){				//	arr[i][j]=p[i]+arr[i-1][j-w[i]];
				q=p[i]+arr[i-1][j-w[i]];	//else arrr[i][j]=arr[i-1][j];
				if(q>arr[i][j]) arr[i][j]=q;	//
			}
		}
	}
	return arr[n][m];
}
int main(){
	int w[5]={1,2,4,1,3};
	int p[5]={10,12,28,13,30};
	printf("%d ",knapsack(6,w,p,5));
	
}

