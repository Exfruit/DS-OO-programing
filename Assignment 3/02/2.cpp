/*input
11
4 9 6 5 1 8 7 2 0 3 10
*/
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
  
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int median_of_three(int arr[], int start, int end){
    if(max(arr[start], max(arr[(end + start) / 2 + 1], arr[end])) == arr[start] || 
            min(arr[start], min(arr[(end + start) / 2 + 1], arr[end])) == arr[end]){
        // cout << (end + start) / 2 + 1 << endl;
        return ((end + start) / 2 + 1);
    }
    else if(max(arr[start], max(arr[(end + start) / 2 + 1], arr[end])) == arr[end] || 
                min(arr[start], min(arr[(end + start) / 2 + 1], arr[end])) == arr[start]){
        // cout << (end + start) / 2 + 1 << endl;
        return ((end + start) / 2 + 1);
    }
    else if(max(arr[start], max(arr[(end + start) / 2 + 1], arr[end])) == arr[(end + start) / 2 + 1] || 
                min(arr[start], min(arr[(end + start) / 2 + 1], arr[end])) == arr[start]){
        // cout << end<< endl;
        return end;
    }
    else if(max(arr[start], max(arr[(end + start) / 2 + 1], arr[end])) == arr[start] || 
                min(arr[start], min(arr[(end + start) / 2 + 1], arr[end])) == arr[(end + start) / 2 + 1]){
        // cout << end << endl;
        return end;
    }
    else{
        // cout << start << endl;
        return start;
    }
}
int partition(int arr[], int start, int end){
    // swap(&arr[start], &arr[end]);
    swap(&arr[median_of_three(arr, start, end)], &arr[end]);
    int pivot = arr[end];
    int pivot_position = start;
  
    for(int j = start; j < end; j++) {
        if(arr[j] < pivot) {
            swap(&arr[pivot_position], &arr[j]);
            pivot_position++;
        }
    }
    swap(&arr[pivot_position], &arr[end]);
    return pivot_position;
}

void Qsort(int arr[], int length){
    int start = 0, end = length - 1;
    stack<int> s;

    s.push(start);
    s.push(end);

    while(!s.empty()){
        end = s.top();
        s.pop();
        start = s.top();
        s.pop();

        // cout << "start : " << start << " end : " << end << endl;

        int position = partition(arr, start, end);
        // cout << position << endl;

        if(position - 1 > start){
            s.push(start);
            s.push(position - 1);
        }
        if(position + 1 < end){
            s.push(position + 1);
            s.push(end);
        }
    }
}

int main(int argc, char const *argv[]){
    int n;  cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    Qsort(arr, n);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}













  
