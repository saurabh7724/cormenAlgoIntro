//insertion sort in C
#include<stdio.h>
#include<stdlib.h>
//sorting method
int* sort(int l, int *unsorted){
	int temp;
	int *sort = (int *)malloc(sizeof(int)*l);
	*(sort)=*(unsorted);
	for(int i=1;i<l;i++){
		*(sort+i)=*(unsorted+i);
		for(int j=0;j<i;j++){
			if(*(sort+j) > *(sort+i)){
				temp=*(sort+j);
				*(sort+j)=*(sort+i);
				*(sort+i)=temp;
			}
		}
	}
	return sort;
}
/* Main Method to input the values */
int main(){
	printf("Enter the number of elements to sort\n");
	int l;
	scanf("%d",&l);
	int *a=malloc(l*sizeof(int));
	for(int i=0;i<l;i++)
		scanf("%d",(a+i));
	int *s = sort(l,a);
	for(int i=0;i<l;i++)
		printf("%d ",*(s+i));
	
return(0);
}
			