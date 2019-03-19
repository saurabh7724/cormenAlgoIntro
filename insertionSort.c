//insertion sort in C
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
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
	clock_t t; 
	t = clock(); 
	int l;
	FILE *fp;
	fp=fopen("numbers","r");
	fscanf(fp,"%d",&l);
	int *a=malloc(l*sizeof(int));
	for(int i=0;i<l;i++)
		fscanf(fp,"%d",(a+i));
	fclose(fp);
	int *s = sort(l,a);
	for(int i=0;i<l;i++)
		printf("%d\n",*(s+i));
	printf("Sorted");
	t = clock() - t; 
	double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
  
	printf(" took %0.20lf seconds to execute \n", time_taken);
	
return(0);
}
/*
file operations in C
FILE *fp;
fp=fopen("filename","mode");
*/		
