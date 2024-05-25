#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int heapsize;
void dijistra(int **,int ,int );
void build_min_heap(int *,int *,int );
void min_hepify(int *,int *,int );
int extract_min(int *,int *);
void relax(int ,int,int **,int *,int *,int);


int main(){
	int **gw,n,i,j;
	printf("Enter no fo vertices: ");
	scanf("%d",&n);
	gw=calloc(n,sizeof(int*));
	printf("Enter weight adjacency matrix matrix: ");
	for(i=0;i<n;i++){
		gw[i]=calloc(n,sizeof(int));
		for(j=0;j<n;j++)
			scanf("%d",&gw[i][j]);
	}
	dijistra(gw,0,n);
}
void dijistra(int **gw,int s,int n){
	int i,j;
	int *dis=calloc(n,sizeof(int));
	for(i=0;i<n;i++)
		dis[i]=INFINITY;
	dis[s]=0;
	int *q=calloc(n,sizeof(int));
	for(i=0;i<n;i++) q[i]=i;
	build_min_heap(q,dis,n);
	while(heapsize!=-1){
		int u=extract_min(q,dis);
		for(int v=0;v<n;v++){
			if(gw[u][v]!=0) relax(u,v,gw,dis,q,n);
		}
	}
	for(i=0;i<n;i++)
		printf("%d ",dis[i]);
		
}
/*
0 10 5 0 0
0 0 2 1 0 
0 3 0 9 2
0 0 0 0 4
7 0 0 6 0
*/
void build_min_heap(int *q,int *dis,int n){
	heapsize=n-1;
	for(int i=n/2-1;i>=0;i--)       ////--
		min_hepify(q,dis,i);
}
void min_hepify(int *q,int *d,int i){
	int l,r,min;
	l=2*i+1;
	r=2*i+2;
	if(l<=heapsize && d[q[l]]<d[q[i]])
		min=l;
	else min=i;
	if(r<=heapsize && d[q[r]]<d[q[min]])
		min=r;
	if(min!=i){
		int tmp=q[i];
		q[i]=q[min];
		q[min]=tmp;
		min_hepify(q,d,min);
	}
}
int extract_min(int *q,int *d){
	int ind=q[0];
	q[0]=q[heapsize--];
	min_hepify(q,d,0);
	return ind;	
}
void relax(int u,int v,int **gw,int *d,int *q,int n){
	if(d[u]+gw[u][v]<d[v]){
		d[v]=d[u]+gw[u][v];
		build_min_heap(q,d,n);
	}
	
}
