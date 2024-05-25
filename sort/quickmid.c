//middle element as pivot
#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b){
	int c=*a;
	*a=*b;
	*b=c;
}
int partition(int *arr,int s,int e){
	printf("%d %d\n",s,e);
	swap(&arr[(s+e)/2],&arr[e]);
	int tmp=s-1,tmp1,pivot=e;
	for(tmp1=s;tmp1<pivot;tmp1++)
		if(arr[tmp1]<arr[pivot]) swap(&arr[tmp1],&arr[++tmp]);
	swap(&arr[pivot],&arr[++tmp]);
	return tmp;
}
void quick_sort(int *arr,int s,int e){
	if(s>=e) return;
	int q=partition(arr,s,e);
	quick_sort(arr,s,q-1);
	quick_sort(arr,q+1,e);
}
int main(){
	int arr[]={1,2,3,4,5,6,7,8,9,10},n=10;
	quick_sort(arr,0,9);
	for(int i=0;i<n;i++) printf("%d ",arr[i]);
}





/*
int partition(int *arr,int s,int e){
	int pivot=(s+e)/2,tmp1,tmp2=pivot+1;
	for(tmp1=s;tmp<pivot;tmp1++){
		while(tmp2<=e){
			if(arr[tmp2]<=arr[pivot]) break;
			tmp2++; 
		}
		if(arr[tmp1]>arr[pivot]){
			if(tmp2<=e) swap(&arr[tmp2++],&arr[tmp1]);
			
		}
	}
}*/
