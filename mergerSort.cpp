#include<bits/stdc++.h>
using namespace std;

void getarray(int n,vector<int>& msort){
	int t;
	for(int i{0};i<n;i++){
		cin >> t;
		msort.push_back(t);
	}
}
//q=(p+r)/2 where p and r are the starting and ending indices
void merge(vector<int>& msort,int p,int q,int r){
	int n1=q-p+1;
	int n2=r-q;
	int L[n1],R[n2];
	for(int i {0};i<n1;i++){
		L[i]=msort[p+i];
	}
	for(int i {0};i<n2;i++){
		R[i]=msort[q+1+i];
	}
	int i=0,j=0,k=p; //index for left and right sides

	while(i<n1 && j	<n2){
		if(L[i]<=R[j]){
			msort[k]=L[i];
			i++;		
		}else{
			msort[k]=R[j];
			j++;
		}k++;
	}
	while (i < n1){ 
        msort[k] = L[i]; 
        i++; 
        k++; 
    }
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2){ 
        msort[k] = R[j]; 
        j++; 
        k++; 
    }
}
void mergeSort(vector<int>& msort,int p,int r){
	int m=p+(r-p)/2;
	if(r>p){
		mergeSort(msort,p,m);
		mergeSort(msort,m+1,r);
		merge(msort,p,m,r);
	}
}
void printArray(vector<int>& msort, int n){
	for(int i {0};i<n;i++){
		cout << msort.at(i)<<' ';
	}
}
int main(){
	int n;
	cin >> n;
	vector<int> msort;
	getarray(n,msort);
	mergeSort(msort,0,n-1);
	printArray(msort,n);
	return(0);
}

/*
The Array with p<->q and q+1<->r are sorted themselves
M.e.r.g.e
merge(A,p,q,r)
n1 = q-p+1
n2 = r-q
let L=[1..n1+1] and R=[1..n2+1] be new arrays
for i = 1 to n1
	L[i]=A[p+i-1]
for i = 1 to n2
	R[i]=A[q+j]
L[n1+1]=S
R[n2+1]=S
i=1,j=1
for k=p to r
	if(L[i]<=R[i])
		A[k]=L[i]
		i++
	else
		A[k]=R[j]
		j++
*/