#include<bits/stdc++.h>
using namespace std;
// basic idea of this problem is we have an 2-D arrar[i][j] = 1 1 1 0
//                                                            0 1 1 1
//                                                            1 1 1 1
//                                                            0 1 1 1
// now the output should be zero where 0 is in col and row
// Bruteforce 😲 
void matrixrow(vector<vector<int>> &matrix, int i,int m){
    for(int j=0; j<m; j++){
        if(matrix[i][j]!=0){
            matrix[i][j]=-1;
        }
    }
}
void matrixcol(vector<vector<int>> &matrix, int j,int n){
    for(int i=0; i<n; i++){
        if(matrix[i][j]!=0){
            matrix[i][j]=-1;
        }
    }
}
vector<vector<int>> setzero(vector<vector<int>> &matrix, int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j]==0){
                matrixcol(matrix,j,n);
                matrixrow(matrix,i,m);
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j]==-1){
                matrix[i][j]=0;
            }
        }
    }
    return matrix;
}
// Better 👍
vector<vector<int>> setzerob(vector<vector<int>> &matrix, int n, int m){
    int col[m] ={0};
    int row[n] ={0};
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j]==0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(row[i]==1 || col[j]==1){
                matrix[i][j]=0;
            }
        }
    }
    return matrix;
}
// optimal
vector<vector<int>> setzeroo(vector<vector<int>> &matrix, int n, int m){
    int col0=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j]==0){
                // i-th row
                matrix[i][0] = 0;
                if(j!=0){
                    matrix[0][j] = 0;
                }else{
                    col0=0;
                }
            }
        }
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(matrix[i][j]!=0){
                if(matrix[0][j]==0 || matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
        }
    }
    if(matrix[0][0]==0){
        for(int j=0; j<m; j++){
            matrix[0][j]=0;
        }
    }
    if(col0==0){
        for(int i=0; i<n; i++){
            matrix[i][0]=0;
        }
    }
    return matrix;
}
int main(){
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans = setzerob(matrix, n, m);

    cout << "The Final matrix is: \n";
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;

}