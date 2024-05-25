#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
	int u,v,w;
	//struct *node;
};
typedef struct node node;
void kruskal(node*,int**,int,int);
void union1(int *,int,int);
void sort(node*,int ,int );
void merge(node*,int ,int ,int);
int find(int *,int);

int main(){
	int n,v,e,i,j;
	printf("Enter no of vertices and edges: ");
	scanf("%d%d",&n,&e);
	//node *ed=calloc(e,sizeof(node));
	int **mst=calloc(n,sizeof(int*));
	node ed[e];
	for(i=0;i<e;i++)
		scanf("%d%d%d",&ed[i].u,&ed[i].v,&ed[i].w);
	for(i=0;i<n;i++)
		mst[i]=calloc(n,sizeof(int));
	kruskal(ed,mst,v,e);
	free(mst);
}
void kruskal(node *ed,int **mst,int n,int e){
	int *set=calloc(n,sizeof(int));
	sort(ed,0,e-1);
	int i,j;
	for(i=0;i<n;i++)
		set[i]=-1;
	for(i=0;i<e;i++){
		int u = ed[i].u, v = ed[i].v ,w = ed[i].w;
	        int parent_u = find(set, u);
	        int parent_v = find(set, v);
	        if (parent_u != parent_v) {
	            printf("%d %d %d\n", u, v, w);
	            mst[u][v] = 1;
	            mst[v][u] = 1;
	            set[parent_u] = parent_v;  //union
	        }
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%d ",mst[i][j]);
		printf("\n");
	}
	//free(set);
}
void sort(node *a,int start,int end){
	if(start<end){
		int mid=(start+end)/2;
		sort(a,start,mid);
		sort(a,mid+1,end);
		merge(a,start,mid,end);
	}
}
void merge(node *a,int start,int mid,int end){
	//printf("\n%d %d %d\n",start,mid,end);
	int len1=mid-start+1,len2=end-mid,i,j,k;
	node right[len1+1];
	node left[len2+1];
	for(i=0;i<len1;i++) right[i]=a[start+i];
	for(j=0;j<len2;j++) left[j]=a[mid+1+j];
	node new;
	new.w=(int)INFINITY;
	right[len1]=left[len2]=new;
	i=j=0;
	for(k=start;k<=end;k++){
		if(left[j].w<=right[i].w)
			a[k]=left[j++];
		else 
			a[k]=right[i++];
	}
}
void union1(int *set, int u, int v) {
    int rootU = find(set, u);
    int rootV = find(set, v);
    if (rootU != rootV) {
        set[rootV] = rootU;
    }
}

int find(int *set, int u) {
    if (set[u] == -1) {
        return u;
    }
    return find(set, set[u]);
}
/*
6
0 11 6 10 5 0
11 10 13 0 0 0
6 13 0 4 1 0
10 0 4 0 8 12
5 0 1 8 0 20
0 0 0 12 20 0

5 8
1 3 8
2 3 2 
3 4 9
0 1 15 
0 2 10
0 4 14
0 3 1
1 2 5


*/
	//int **gw=calloc(n,sizeof(int*));
	//int **mst=calloc(n,sizeof(int*));
	/*printf("Enter no of vertices: ");
	scanf("%d",&n);
	printf("enter weight adjacency matrix: ");
	for(i=0;i<n;i++){
		mst[i]=calloc(n,sizeof(int));
		gw[i]=calloc(n,sizeof(int));
		for(j=0;j<n;j++){
			mst[i][j]=0;
			scanf("%d",&gw[i][j]);
		}
	}*/
