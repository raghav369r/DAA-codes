#include<stdio.h>
#include<stdlib.h>
void floyd_warshall(int **,int);
int min(int,int);

int main(){
	int i,j,v;
	printf("Enter no of vertices: ");
	scanf("%d",&v);
	printf("Enter weight adjacency matrix: ");
	int **w=calloc(v,sizeof(int *));
	for(i=0;i<v;i++){
		w[i]=calloc(v,sizeof(int));
		for(j=0;j<v;j++)
			scanf("%d",&w[i][j]);
	}
	floyd_warshall(w,v);
	free(w);
}
void floyd_warshall(int **w,int v){
	int i,j,k;
	int ***d=calloc(2,sizeof(int **));
	for(i=0;i<2;i++){
		d[i]=calloc(v,sizeof(int**));
		for(j=0;j<v;j++)
			d[i][j]=calloc(v,sizeof(int));
	}
	d[0]=w;
	for(i=0;i<v;i++){
		for(j=0;j<v;j++){
			for(k=0;k<v;k++){
				int p,q;
				if(i%2==0) p=0,q=1;
				else p=1,q=0;
				//int a=d[p][j][k];
				//int b=d[p][j][i]+d[p][i][k];
				//d[q][j][k]=(a<=b)?a:b;
				d[q][j][k]=min(d[p][j][k],d[p][j][i]+d[p][i][k]);
			}
		}
	}
	printf("weight adjacency matrix of all pairs shortest paths: \n");
	int a=(i%2==1)?1:0;
	for(i=0;i<v;i++){
		for(j=0;j<v;j++)
			printf("%d ",d[a][i][j]);
		printf("\n");
	}
	free(d);
}
int min(int a,int b){
	return (a<=b)?a:b;
}
/*
4
0 11 1 6
11 0 7 3
1 7 0 2
6 3 2 0

*/
