#include<iostream>
#include<omp.h>
using namespace std;

void quick_sort(int array[], int f, int l) {

	int key = array[f], i = f + 1, j = l;

	if(f>=l)
		return;
	else {

		while(i<=j) {
		
			while( (key > array[i]) && (i < j) )
				i++;
		
			while( (key < array[j]) && (j >= 0 ) )
				j--;
		
			if(i>=j)
				break;
		
			swap(array[i],array[j]);
		}
		swap(array[f],array[j]);

		#pragma omp parallel sections 
		{
			
			#pragma omp section	
			{
				quick_sort(array, f, j-1);
			}
		
			#pragma omp section 
			{
				quick_sort(array, j+1, l);
			}
		}
	}
}


int main() {

	int array[20],noe;
	cout<<"\nNumber of elements: ";
	cin>>noe;

	cout<<"Enter elements: ";
	for (int i = 0; i < noe ; i++) 
		cin>>array[i];

	quick_sort(array, 0, noe-1);

	cout<<"The sorted elements are: ";
	for (int i = 0; i < noe ; i++) 
		cout<<array[i]<<"   ";



	cout<<endl<<endl;
	return 1;
}
