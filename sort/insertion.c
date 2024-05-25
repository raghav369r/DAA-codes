#include<stdio.h>
#include<stdlib.h>
void insertion_sort(int *arr,int n){
	for(int i=1;i<n;i++){
		int tmp=arr[i];
		int j=0;
		while(j<i){
			if(arr[j]>tmp){
				int a=tmp;
				tmp=arr[j];
				arr[j]=a;
			}
			j++;		
		}
		arr[i]=tmp;
	}
}
int main(){
	int *arr,n;
	printf("Enter no of elements: ");
	scanf("%d",&n);
	arr=calloc(n,sizeof(int));
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	insertion_sort(arr,n);
	for(int i=0;i<n;i++) printf("%d  ",arr[i]);
}
