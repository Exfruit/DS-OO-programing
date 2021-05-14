/*input
3 4
1 2 3 4 5 6 7 8 9 10 11 12
*/
#include <iostream>
using namespace std;

void matrix_transpose(int **a, int **b, int r, int c){
	for(int i = 0; i < c; i++){
		for(int j = 0; j < r; j++){
			b[i][j] = a[j][i];
		}
	}
}
int main(int argc, char const *argv[])
{
	int row, col;
	cout << "Row : ";
	cin >> row;
	cout << "Column : ";
	cin >> col;
	cout << '\n';
	int** arr = new int*[row];
	int** transpose = new int*[col];
	for(int i = 0; i < row; i++){
		arr[i] = new int[col];
	}
	for(int i = 0; i < col; i++){
		transpose[i] = new int[row];
	}
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cin >> arr[i][j];
		}
	}
	matrix_transpose(arr, transpose, row, col);
	for(int i = 0; i < col; i++){
		for(int j = 0; j < row; j++){
			cout << transpose[i][j];
			if(j == row - 1)
				cout << '\n';
			else
				cout << " ";
		}
	}
	return 0;
}