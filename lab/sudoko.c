#include<stdio.h>
#include<stdlib.h>
int isavilable(int **puzzle,int u,int v,int n){
	int a,b,i,j;
	for(i=0;i<9;i++)
		if(puzzle[u][i]==n||puzzle[i][v]==n) return 0;
	a=i=(u/3)*3;
	b=j=(v/3)*3;
	for(int k=1;k<10;k++,j++){
		if(j==b+3) j=b,i++;
		if(puzzle[i][j]==n) return 0;
	}
	return 1;
}
int sudoko(int **puzzle,int u,int v){
	if(u==8&&v==8) return 1;
	int a,b,i,j;
	if(v==8) a=u+1,b=0;
	else a=u,b=v+1;
	if(puzzle[u][v]!=0) return sudoko(puzzle,a,b); //if index is already filled
	else{
		for(i=1;i<=9;i++){
			if(isavilable(puzzle,u,v,i)){
				puzzle[u][v]=i;
				if(sudoko(puzzle,a,b))
					return 1;
				//puzzle[u][v]=0;
				puzzle[a][b]=0;
			}
		}
		return 0;
	}
}
int main(){
	int i,j,**puzzle;
	puzzle=calloc(9,sizeof(int *));
	for(i=0;i<9;i++)
		puzzle[i]=calloc(9,sizeof(int));
	printf("Enter puzzle: ");
	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
			scanf("%d",&puzzle[i][j]);
	sudoko(puzzle,0,0);
	printf("solution: \n");
	for(i=0;i<9;i++){
		for(j=0;j<9;j++)
			printf("%d ",puzzle[i][j]);
		printf("\n");
	}
}
/*
5 3 0 0 7 0 0 0 0 
6 0 0 1 9 5 0 0 0 
0 9 8 0 0 0 0 6 7
8 0 0 0 6 1 4 2 3 
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0 
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9


5 6 8 4 2 7 0 0 0
0 4 0 0 1 0 7 0 0
1 9 0 0 0 3 0 0 2
0 0 0 6 0 0 0 0 5
7 0 0 0 0 0 2 0 0 
6 0 5 1 3 0 9 0 0 
9 0 0 0 0 1 5 0 0 
0 0 0 0 4 0 0 2 0
0 7 0 0 0 0 0 0 8

*/
