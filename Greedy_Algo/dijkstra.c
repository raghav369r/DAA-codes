#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
	int v;
	int dis;
	int piq;
	int pre;
};
typedef struct node node;
int heapsize;
void min_hepify(node **q,int i){
	int l,r,min;
	l=2*i+1;
	r=2*i+2;
	if(l<=heapsize && q[l]->dis<q[i]->dis)
		min=l;
	else min=i;
	if(r<=heapsize && q[r]->dis<q[min]->dis)
		min=r;
	if(min!=i){
		node *tmp=q[i];
		q[i]->piq=min;
		q[min]->piq=i;
		q[i]=q[min];
		q[min]=tmp;
		min_hepify(q,min);
	}
}
void build_min_heap(node **q,int n){
	heapsize=n-1;
	for(int i=n/2-1;i>=0;i--)       ////--
		min_hepify(q,i);
}
int extract_min(node **q){
	int ind=q[0]->v;
	q[0]->piq=heapsize;
	node *tmp=q[0];
	q[0]=q[heapsize];
	q[heapsize]=tmp;
	q[0]->piq=0;
	heapsize--;
	min_hepify(q,0);
	return ind;	
}
void relax(int u,int v,int **gw,node **q,node **h){
	if(h[u]->dis+gw[u][v]<h[v]->dis){
		h[v]->dis=h[u]->dis+gw[u][v];
		int i=h[v]->piq;
		while(i>0 && q[i]<q[i/2]){
			node *tmp=q[i];
			q[i]->piq=i/2;
			q[i/2]=tmp;
			q[i]->piq=i;
		}
	}
}
void dijistra(int **gw,int s,int n){
	int i,j;
	node **q=calloc(n,sizeof(node*));
	node **h=calloc(n,sizeof(node*));
	for(i=0;i<n;i++){
		q[i]=malloc(sizeof(node));
		q[i]->v=i;
		q[i]->dis=(int)INFINITY;
		q[i]->piq=i;
		h[i]=q[i];
	}	
	q[s]->dis=0;
	build_min_heap(q,n);
	while(heapsize!=-1){
		int u=extract_min(q);
		for(int v=0;v<n;v++)
			if(gw[u][v]!=0) relax(u,v,gw,q,h);
	}
	printf("shortest paths to all verices from %d: \n",s);
	for(i=0;i<n;i++)
		printf("%d %d\n",h[i]->v,h[i]->dis);	
}
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
/*
5
0 10 5 0 0
0 0 2 1 0 
0 3 0 9 2
0 0 0 0 4
7 0 0 6 0
*/
/*
3 0 1 3 0 0 1 0 1 0
3 0 3 1 0 0 1 0 1 0
4 0 1 5 2 2 0 5 1 0 4 0 5 0 6 1 0
*/

