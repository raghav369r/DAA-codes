#include<stdio.h>
//#define length 10
int length;
int heapsize;
void swap(int *a,int *b){
	int c=*b;
	*b=*a;
	*a=c;
}
void Max_Heapify(int *a,int i){
	int leftchild=2*i+1,rightchild=2*i+2,lar;
	if(a[leftchild]>a[i]&& leftchild<=heapsize)
		lar=leftchild;
	else lar=i;
	if(a[rightchild]>=a[lar] && rightchild<=heapsize)
		lar=rightchild;
	if(lar!=i){
		swap(&a[lar],&a[i]);
		Max_Heapify(a,lar);
	}
}
void Build_maxheap(int *a){
	for(int i=length/2-1;i>=0;i--)
		Max_Heapify(a,i);
}
void heapsort(int *a){
	Build_maxheap(a);
	for(int i=length-1;i>=1;i--){
		swap(&a[0],&a[i]);
		heapsize--;
		Max_Heapify(a,0);
	}
}
int main(){
	int i;
	printf("Enter no of elements: ");
	scanf("%d",&length);
	heapsize=length-1;
	int a[length];
	for(i=0;i<length;i++){
		scanf("%d",&a[i]);
	}
	heapsort(a);	
	for(i=0;i<length;i++) printf("%d->",a[i]);
}




