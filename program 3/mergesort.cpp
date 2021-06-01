#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define MAX 1000
#define LENGTH 8

void print_arr(int arr[], int length){
	for(int i = 0; i < length - 1; i++){
		cout << arr[i] << " ";
	}
	cout << arr[length - 1] << endl;
	return;
}
void merge(int arr[], int L[], int R[], int front, int end){
	int Lidx = 0, Ridx = 0;
    for(int i = front; i <= end; i++){
        if(L[Lidx] <= R[Ridx]){
            arr[i] = L[Lidx];
            Lidx++;
        }
        else{
            arr[i] = R[Ridx];
            Ridx++;
        }
    }
}
void yabai_mergesort(int arr[], int front, int end){
    if(front < end){
        int mid = (front + end) / 2;
        int L[mid + 1 - front + 1], R[end - mid + 1];	//distribution
        for(int i = front, j = 0, k = 0; i <= end; i++){
        	if(i % 2 == 0){
        		L[j] = arr[i];
        		j++;
        	}
        	else{
        		R[k] = arr[i];
        		k++;
        	}
        }
        L[mid + 1 - front] = MAX, R[end - mid] = MAX;
        // print in detail 
        // begin
        cout << "L: ";
        print_arr(L, mid + 1 - front);
        cout << "R: ";
        print_arr(R, end - mid);
        yabai_mergesort(L, front, mid);
        yabai_mergesort(R, front, mid);
        // end
        merge(arr, L, R, front, end);	//arr => L + R(sorted)
        // print in detail
        // begin
        cout << "Merged: ";
        print_arr(arr, end - front + 1);
        // end

    }
} 

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int arr[LENGTH];
	for(int i = 0; i < LENGTH; i++){
		arr[i] = rand() % MAX;
	}
	cout << "Before sorted: " << endl;
	print_arr(arr, LENGTH);
	cout << "In detail: " << endl;
	yabai_mergesort(arr, 0, LENGTH - 1);
	cout << "After sorted: " << endl;
	print_arr(arr, LENGTH);

	return 0;
}