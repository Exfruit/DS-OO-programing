/*input
3 3 4
0 1 1
1 2 1
2 0 1
2 2 1
3 5 7
0 0 1
0 2 1
0 4 1
1 2 1
2 0 1
2 3 1
2 4 1
*/
#include<iostream>
#include<vector>
#include<cstring>
#include<time.h>
#define MAX 100

using namespace std;

class Element{
    public:
        Element(int row = -1, int col = -1, int val = -1): row(row), col(col), val(val){}
        int row;
        int col;
        int val; 
};

class SparseMatrix{
    public:
        SparseMatrix(){}
        SparseMatrix(int row_num, int col_num, int r): row_num(row_num), col_num(col_num), r(r){}
        SparseMatrix(const SparseMatrix &other);
        SparseMatrix operator*(SparseMatrix &other);
        void set_M();
        void set_vec();
        void display();

        int row_num;
        int col_num;
        int r;
        int M[MAX][MAX];
        vector<Element> vec;
};

SparseMatrix::SparseMatrix(const SparseMatrix &other)
{
    // your implementation here
    row_num = other.row_num;
    col_num = other.col_num;
    r = other.r;
    for(int i = 0; i < row_num; i++){
        for(int j = 0; j < col_num; j++){
            M[i][j] = other.M[i][j];
        }
    }
    vec = other.vec;
}

void SparseMatrix::set_M()
{
    memset(M, 0, sizeof(M));
    for (int i = 0; i < r; i++)
        M[vec[i].row][vec[i].col] = vec[i].val;
}

void SparseMatrix::set_vec()
{
    int count = 0;
    for (int i = 0; i < row_num; i++){
        for (int j = 0; j < col_num; j++){
            if (M[i][j] != 0){
                Element element(i, j, M[i][j]);
                vec.push_back(element);
                count++;
            }
        }
    }
    
    r = count;
}

void SparseMatrix::display()
{
    for (int i = 0; i < row_num; i++){
        for (int j = 0; j < col_num; j++){
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

SparseMatrix SparseMatrix::operator*(SparseMatrix &other)
{
    SparseMatrix mul_SM(row_num, other.col_num, 0);

    if (other.col_num * r <= row_num * other.r){
        // your implementation here  
        for(int i = 0; i < row_num; i++){
            for(int j = 0; j < other.col_num; j++){
                for(int k = 0; k < col_num; k++){
                    mul_SM.M[i][j] += (this->M[i][k] * other.M[k][j]);
                }
            }
        }
    }
    else{
        // your implementation here
        for(int i = 0; i < row_num; i++){
            for(int j = 0; j < other.col_num; j++){
                for(int k = 0; k < col_num; k++){
                    mul_SM.M[i][j] += (this->M[i][k] * other.M[k][j]);
                }
            }
        }
    }

    mul_SM.set_vec();
    return mul_SM;
}

void set_input(SparseMatrix &SM)
{
    cin >> SM.row_num >> SM.col_num >> SM.r;
    for (int i = 0; i < SM.r; i++){
        int row, col, val;
        cin >> row >> col >> val;
        Element element(row, col, val);
        SM.vec.push_back(element);
    }
    SM.set_M();
}

int main()
{
    clock_t start, end;
    double time_used;
    SparseMatrix SM1;
    SparseMatrix SM2;
    set_input(SM1);
    set_input(SM2);

    // multiplication
    SparseMatrix mul_SM = SM1 * SM2;
    cout << "multiplication result: " << endl;
    mul_SM.display();
    
    // copy 
    start = clock();
    SparseMatrix copy_SM = SM1;
    end = clock();
    cout << "copy result: " << endl;
    copy_SM.display();
    cout << "Computing time of copy constructor : "<< ((double) (end - start)) / CLOCKS_PER_SEC << '\n';

    return 0;
}