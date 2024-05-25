#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
	float p;
	float w;
	float r;
};
typedef struct node node;
void sort(node*,int,int);
void merge(node*,int,int,int);
int knapsack(node *,int,int);
int main(){
	int n,i,m;
	printf("Enter no of objects: ");
	scanf("%d",&n);
	node arr[n];
	printf("Enter profit and weight of objects: \n");
	for(i=0;i<n;i++){
		scanf("%f%f",&arr[i].p,&arr[i].w);
		arr[i].r=arr[i].p/arr[i].w;
	}	
	printf("Enter max weight of bag: ");
	scanf("%d",&m);
	knapsack(arr,n,m);	
}
int knapsack(node *arr,int n,int m){
	sort(arr,0,n-1);
	int p=0,i;
	for(i=0;i<n;i++){
		if(m>0 && m>=arr[i].w){
			//printf("%d ",i);
			m=m-arr[i].w;
			p=p+arr[i].p;
		}
		else
			break;
	}
	if(m>0)
		p=p+(arr[i].p/arr[i].w)*m;
	printf("max profit= %d",p);
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
	new.r=-INFINITY;
	right[len1]=left[len2]=new;
	i=j=0;
	for(k=start;k<=end;k++){
		if(left[j].r>=right[i].r)
			a[k]=left[j++];
		else 
			a[k]=right[i++];
	}
}// 10 5 20 20 30 20 40 5 30
