#include<iostream>
#include<stdlib.h>
using namespace std;
void arr_filler(int arr[], int noe); // To initilize array elements
void arr_display(int arr[], int noe); // To display array elements
int bin_search(int arr[], int first, int last, int key); // Function for 'binary search' algorithm

int main() {

	int arr[30],noe,key,index;

	cout<<"Enter no of elements in array: ";
	cin>>noe;
	arr_filler(arr, noe);
	arr_display(arr,noe);
	cout<<"\nEnter the key to be searched: ";
	cin>>key;

	index = bin_search(arr, 0, noe-1, key);
	if(index>=0)
		cout<<"Number was found at index: "<<index<<endl;
	else
		cout<<"Number was not present in the array\n";

	return 0;
}


void arr_filler(int arr[], int noe) {

	int t_ind = 0;

	arr[0] = rand()%6;
	for(int i = 1; i<noe ; i++)
		arr[i] = arr[t_ind++] + rand()%6;
}


void arr_display(int arr[], int noe) {

	cout<<"The array is:";
	for(int i=0;i<noe;i++)
		cout<<"  "<<arr[i];
}


int bin_search(int arr[], int first, int last, int key) {

	int index = 0, mid;

	if(first > last)
		return -1;

	mid = (first + last) / 2;

	if(arr[mid] < key) {
		index = bin_search(arr, mid + 1, last, key);
	}

	else {
		if(arr[mid] > key) {
			index = bin_search(arr, first, mid - 1, key);	
		}
		else {
			index = mid;
		}
	}	
	
	return index;
}


/* 

noe        ->        No. of elements
arr        ->        Array
t_ind      ->        Temporary Index
loc        ->        Location 
mid        ->        Index for middle number/element
bin_search ->        Function for Binary search
 
*/
