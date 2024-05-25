//starting element as pivot
#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b){
	int c=*a;
	*a=*b;
	*b=c;
}
int partition(int *arr,int s,int e){
		printf("%d %d\n",s,e);
	int tmp1=e+1,tmp2,pivot=arr[s];
	for(tmp2=e;tmp2>s;tmp2--)
		if(arr[tmp2]>=pivot)
			swap(&arr[tmp2],&arr[--tmp1]);
	swap(&arr[s],&arr[--tmp1]);
	return tmp1;
}
void quick_sort(int *arr,int s,int e){
	if(s<e){
		int q=partition(arr,s,e);
		quick_sort(arr,s,q-1);
		quick_sort(arr,q+1,e);
	}
}
int main(){
	int n,i,*arr;
	printf("ENter no of elements and elements: ");
	scanf("%d",&n);
	arr=calloc(n,sizeof(int));
	for(i=0;i<n;i++) scanf("%d",&arr[i]);
	quick_sort(arr,0,n-1);
	for(i=0;i<n;i++) printf("%d  ",arr[i]);
}
