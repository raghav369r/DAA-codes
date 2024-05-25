#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int isavilable(int **,int *,int,int);
int tsp(int**,int *,int,int);
int minc=(int)INFINITY;
int *soln;
int main(){
	int i,j,n;
	printf("Enter no of verices: ");
	scanf("%d",&n);
	int **g=calloc(n,sizeof(int*));
	printf("Enter weight adjacency matrix: ");
	int *sol=calloc(n+1,sizeof(int));
	soln=calloc(n+1,sizeof(int));
	for(i=0;i<n;i++){
		sol[i]=-1;
		g[i]=calloc(n,sizeof(int));
		for(j=0;j<n;j++)
			scanf("%d",&g[i][j]);
	}
	sol[0]=0;
	tsp(g,sol,1,n);
	printf("minimum cost= %d\npath: ",minc);
	for(i=0;i<n+1;i++)
		printf("%d ",soln[i]);
	
}
int tsp(int **g,int *sol,int l,int n){
	if(l==n){
		if(g[sol[l-1]][0]==0) return 0;
		sol[l]=sol[0];
		int cost=0;
		for(int i=0;i<n-1;i++)
			cost+=g[sol[i]][sol[i+1]];
		cost+=g[sol[n-1]][sol[0]];
		if(cost<minc){
			minc=cost;
			for(int i=0;i<=l;i++)
				soln[i]=sol[i];
			soln[n]=sol[0];
		}
		return 1;	
	}
	for(int i=0;i<n;i++){
		if(isavilable(g,sol,l,i)){
			sol[l]=i;
			tsp(g,sol,l+1,n);
		}
	}
}
int isavilable(int **g,int *sol,int l,int i){
	if(g[sol[l-1]][i]==0) return 0;
	for(int j=0;j<l;j++)
		if(sol[j]==i) return 0;
	return 1;
}
/*
4
0 1 2 3
1 0 4 2
1 2 0 5
3 4 1 0
*/
