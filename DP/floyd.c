#include<stdio.h>
#include<stdlib.h>
void floyd_warshall(int **,int);

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
	int ***d=calloc(v+1,sizeof(int **));
	d[0]=w;
	int i,j,k;
	for(i=1;i<=v;i++){
		d[i]=calloc(v,sizeof(int *));
		for(j=0;j<v;j++){
			d[i][j]=calloc(v,sizeof(int));
			for(k=0;k<v;k++){
				int a=d[i-1][j][k];
				int b=d[i-1][j][i-1]+d[i-1][i-1][k];
				d[i][j][k]=(a<=b)?a:b;
				//d[i][j][k]=min(d[i-1][j][k],d[i-1][j][i]+d[i-1][i][k]);
			}
		}
	}
	printf("weight adjacency matrix of all pairs shortest paths: \n");
	for(k=0;k<v+1;k++){
		for(i=0;i<v;i++){
			for(j=0;j<v;j++)
				printf("%d ",d[k][i][j]);
			printf("\n");
		}
		printf("\n\n");
	}
	free(d);
}

/*
4
0 11 1 6
11 0 7 3
1 7 0 2
6 3 2 0

*/
