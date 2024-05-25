#include<stdio.h>
#include<math.h>
void merge(int *a,int start,int mid,int end){
	//printf("\n%d %d %d\n",start,mid,end);
	int len1=mid-start+1,len2=end-mid,i,j,k;
	int right[len1+1];
	int left[len2+1];
	for(i=0;i<len1;i++) right[i]=a[start+i];
	for(j=0;j<len2;j++) left[j]=a[mid+1+j];
	right[len1]=left[len2]=INFINITY;
	i=j=0;
	for(k=start;k<=end;k++){
		if(right[i]>=left[j]) a[k]=left[j++];
		else a[k]=right[i++];
	}
}
void merge_sort(int *a,int start,int end){
	if(start<end){
		int mid=(start+end)/2;
		merge_sort(a,start,mid);
		merge_sort(a,mid+1,end);
		merge(a,start,mid,end);
	}
}

void insertion_sort(int *arr,int n){
	int j,tmp,k;
	for(j=1;j<n;j++){
		tmp=arr[j];
		k=j-1;
		while(arr[k]>tmp && k>=0){
			arr[k+1]=arr[k];
			k--;
		}
		arr[k+1]=tmp;
	} 
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
void quick_sort(int *arr,int start,int end){
	if(start<end){
		int Q=part(arr,start,end);
		quick_sort(arr,start,Q-1);
		quick_sort(arr,Q+1,end);
	}
}
int main(){
	int arr[]={23,0,9,7,6,4,5,99,10};
	int n=9;
	insertion_sort(arr,n/2);
	printf("After insertion sort for first half: ");
	for(int i=0;i<n;i++) printf("%d  ",arr[i]);
	merge_sort(arr,n/2,n-1);
	printf("\nAfter merge sort for second half: ");
	for(int i=0;i<n;i++) printf("%d  ",arr[i]);
	quick_sort(arr,0,n-1);
	printf("\nAfter quick sort for 1+2: ");
	for(int i=0;i<n;i++) printf("%d  ",arr[i]);
}
