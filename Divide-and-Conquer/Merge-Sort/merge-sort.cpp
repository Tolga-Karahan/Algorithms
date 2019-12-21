#include <iostream>
using namespace std;

int* split_array(int*, int, int);
int* merge(int*, int*, int, int);
void print_array(int*, int);

// Merge sort enhances time complexity comparing to basic
// sorting algorithms, but requires more memory
int* merge_sort(int* arr, int size){

	// If array's size is 1 then there is no need to sort it
	if(size == 1)
		return arr;

	// Find middle index of the array
	int mid = size / 2;

	// Split arrays into two halves
	int* first_half  = split_array(arr, 0, mid);
	int* second_half = split_array(arr, mid, size);
	int size1 = mid;
	int size2 = size - mid;
	
	// Sort the halves
	int* sorted_first_half  = merge_sort(first_half, size1);
	int* sorted_second_half = merge_sort(second_half, size2);
	
	// Merge the halves
	int* sorted_array = merge(sorted_first_half, sorted_second_half, size1, size2);

	return sorted_array;
}

int* split_array(int* arr, int begin, int end){

	int new_size = end-begin;
	int* new_array = new int[new_size];

	// Copy elements
	for(int i = 0; i < new_size; i++)
		new_array[i] = arr[begin + i];

	return new_array;
}

int* merge(int* sorted1, int* sorted2, int size1, int size2){

	int size = size1 + size2;
	int* sorted_array = new int[size];
	int i = 0;
	int j = 0;
	int k = 0;

	while(k < size){

		if(sorted1[i] <= sorted2[j])
			sorted_array[k++] = sorted1[i++];
		else
			sorted_array[k++] = sorted2[j++];

		if(i >= size1)
			while(k < size)
				sorted_array[k++] = sorted2[j++];

		if(j >= size2)
			while(k < size)
				sorted_array[k++] = sorted1[i++];		

	}
	
	return sorted_array;
}

void print_array(int* arr, int size){
	cout << "[";
	for(int i = 0; i < size; i++)
		cout << " " << arr[i];
	cout << " ]" << endl;	 
}

int main(){

	int an_array[] = {7, 4, 3, 8, 6, 10, -2, -5, 1};
	int size = (sizeof(an_array) / sizeof(*an_array));
	
	cout << "Input array: ";
	print_array(an_array, size);

	cout << "Sorted array: ";
	int* sorted_array = merge_sort(an_array, size);
	print_array(sorted_array, size);

	return 0;
}