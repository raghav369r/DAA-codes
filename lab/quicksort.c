#include<stdio.h>
#include<stdlib.h>
void swap(int *,int*);
void quicksort(int *,int ,int);
int part(int *,int ,int);
int main(){
	int n,i;
	printf("enter no of elements: ");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	quicksort(a,0,n-1);
	for(i=0;i<n;i++) printf("%d-->",a[i]);
}
void swap(int *a,int *b){
	int c=*a;
	*a=*b;
	*b=c;
}
int part(int *arr,int start,int end){
	int pivot=arr[end],Q,tmp1=start-1,tmp2;
	for(tmp2=start;tmp2<end;tmp2++)
		if(arr[tmp2]<=pivot) swap(&arr[++tmp1],&arr[tmp2]);
	swap(&arr[end],&arr[++tmp1]);
	return tmp1;
	
}
void quicksort(int *arr,int start,int end){
	if(start<end){
		int Q=part(arr,start,end);
		quicksort(arr,start,Q-1);
		quicksort(arr,Q+1,end);
	}
}

