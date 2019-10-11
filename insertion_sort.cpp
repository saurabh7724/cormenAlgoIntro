#include<bits/stdc++.h>
using namespace std;
void inserSort(int n,vector<int>& insort){
	int key,i,j;
	for(i=1;i<n;i++){
		key=insort.at(i);
		j=i-1;
		while(j>=0 && insort.at(j)>key){
			insort.at(j+1)=insort.at(j);
			j--;
		}
		insort[j+1]=key;
	}
}
void printSorted(int n,vector<int>& insort){
	cout << "Sorted: ";
	for(int i=0;i<n;i++){
		cout << insort.at(i)<<' ';
	}
}
void getArray(int n,vector<int>& insort){
	int t;
	for(int i=0;i<n;i++){
		cin >> t;
		insort.push_back(t);
	}
}
int main(){
	int n;
	cin >> n;
	vector<int> insort;
	getArray(n,insort);
	inserSort(n,insort);
	printSorted(n,insort);
	cout<<'\n';
	return(0);
}