//Merge sort index strting with 0

#include<stdio.h>
#include<math.h>
void sort(int *,int ,int);
void merge(int *,int ,int ,int);
int main(){
	int n,i;
	printf("enter no of elements: ");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,0,n-1);
	for(i=0;i<n;i++) printf("%d-->",a[i]);
}
void sort(int *a,int start,int end){
	if(start<end){
		int mid=(start+end)/2;
		sort(a,start,mid);
		sort(a,mid+1,end);
		merge(a,start,mid,end);
	}
}
void merge(int *a,int start,int mid,int end){
	printf("\n%d %d %d\n",start,mid,end);
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
