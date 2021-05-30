/*input
11
4 9 6 5 1 8 7 2 0 3 10
*/
#include <iostream>
using namespace std;

#define MAX 100000

void merge(int arr[], int front, int mid, int end){
    int L[mid - front + 1 + 1], R[end - mid + 1];
    for(int i = 0; i < mid - front + 1; i++){
        L[i] = arr[front + i];
    }
    for(int i = 0; i < end - mid; i++){
        R[i] = arr[mid + 1 + i];
    }
    L[mid - front + 1] = MAX;
    R[end - mid] = MAX;
/*
    cout << "L_subarray : ";
    for(int i = 0; i <= mid - front + 1; i++){
        cout << L[i] << " ";
    }
    cout << endl << "R_subarray : ";
    for (int i = 0; i <= end - mid; i++){
        cout << R[i] << " ";
    }
    cout << endl << endl;
*/
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
void Msort(int arr[], int n){
    int current_size;
    int front, mid, end;
    // int i = 1;
    for(current_size = 1; current_size < n; current_size *= 2){
        for(front = 0; front < n - 1; front += (current_size * 2)){
            mid = min(front + current_size - 1, n - 1);
            end = min(front + (current_size * 2) - 1, n - 1);
            // cout << i++ << " : " << endl;
            merge(arr, front, mid, end);
        }
    }
} 

int main(int argc, char const *argv[]){
    int n;  cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    Msort(arr, n);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
/*
    On initially sorted, time complexity is nlog(n), 
    Worst-case computing time is also nlog(n), 
    Additonal space is O(n).
*/












  
