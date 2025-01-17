#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define arrsize 100
int heap[arrsize];
int heapsize;
void hepify(int );
int delete(int );
void tree();
int min();
void heap_sort();
void build_maxheap();
void insert(int ele){
	int i;
	heapsize++;				
	heap[heapsize]=ele;		//add new ele at the end of the heap
	for(i=heapsize;i>=0 && heap[(i-1)/2]<ele;i=(i-1)/2){ 
		int a=heap[i];
		heap[i]=heap[(i-1)/2];	       //swap with its parent until parent is grater or root node is found
		heap[(i-1)/2]=a;
	}
}
int search(int ele){
	for(int i=0;i<=heapsize;i++)
		if(heap[i]==ele)
			return i;
	return -1;
}
int main(){
	heapsize=-1;
	int op,ele,idx,i;
	while(1){
		printf("1.insert\t6.print heap\n2.delete\t7.find min\n3.show\t\t8.find max\n4.search\t9.heap sort\n5.exit\t\nEnter ur choice: ");
		scanf("%d",&op);
		switch(op){
			case 1:
				printf("Enter element to insert: ");
				scanf("%d",&ele);
				insert(ele);
				break;
			case 2:
				printf("Enter element to delete: ");
				scanf("%d",&ele);
				if(delete(ele)==-1) printf("Element not found to delete!!\n");
				else printf("%d deleted\n",ele);
				break;
			case 3:
				for(i=0;i<=heapsize;i++) printf("%d  ",heap[i]);
				printf("\n");
				break;
			case 4:
				printf("Enter element to search: ");
				scanf("%d",&ele);
				idx=search(ele);
				if(idx==-1) printf("Element not found in the heap!!\n");
				else printf("Element found at index %d\n",idx);
				break;
			case 5:
				return 0;
			case 6:
				tree();
				break;
			case 7:
				printf("min= %d\n",min());
				break;
			case 8:
				printf("max= %d\n",heap[0]);
				break;
			case 9:
				//heap_sort();
				break;
		}
	}
}
// 1 100 1 70 1 60 1 50 1 56 1 48 1 55 1 10 1 20 1 -1 1 30 1 40 1 45 1 0 1 -10 1 2
void heapify(int i){
	int lc=2*i+1,rc=2*i+2,lar=i;;
	if(lc<=heapsize && heap[lc]>heap[lar])
		lar=lc;
	if(rc<=heapsize && heap[rc]>heap[lar])
		lar=rc;
	if(lar!=i){
		int a=heap[i];
		heap[i]=heap[lar];
		heap[lar]=a;
		heapify(lar);
	}
}
int delete(int ele){
	int inx=search(ele);
	if(inx==-1) return -1;			
	heap[inx]=heap[heapsize];	//put the last element in the place of the element which we want to delete
	heapsize--;			//decrease the heap size
	heapify(inx);			//now the right and left tress are in max heap
	return 1;			//so apply heapify on that node to get max heap
}
void tree(){
	int n=heapsize,i,j,m,s,k=0;
	int h=(int)(log(n)/log(2));
	for(m=h,i=1;k<=n;i*=2,m--){
		//printf("pow(2,h-s)-1= %d",(int)pow(2,h-s)-1);
		for(s=0;s<pow(2,m)-1;s++) printf("  ");
		for(j=1;j<=i&&k<=n;j++){
			printf("% d",heap[k++]);
			for(s=0;s<pow(2,m+1)-1;s++) printf("  ");
			
		}
		printf("\n\n");
	}
	//printf("Height= %d",h);
}
int min(){
	int n=heapsize;
	if(n==-1) return -9999;
	int min=heap[n/2],i;
	for(i=(n/2)+1;i<=n;i++)
		if(heap[i]<min) min=heap[i];
	return min;	
}
