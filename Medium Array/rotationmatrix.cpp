#include<bits/stdc++.h>
using namespace std;
// Bruteforce 👍 
vector<vector<int>> rotatematrix(vector<vector<int>> &mat, int n, int m){
    vector<vector<int>> ans(n, vector<int>(n, 0));
    cout << " hello";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++){
            int x= (n-1)-i;
            ans[j][x] = mat[i][j];
        }
    }
    return ans;
}
// Optimal
vector<vector<int>> rotatematrixo(vector<vector<int>> &mat, int n, int m){
    for(int i=0;i<n-2;i++){
        for(int j=i+1; j<n; j++){
            swap(mat[i][j],mat[j][i]);
        }
    }
    for(int i=0; i<n; i++)
    {
        reverse(mat[i].begin(),mat[i].end());
    }
    return mat;
}
int main(){
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans = rotatematrixo(matrix, n, m);

    cout << "The Final matrix is: \n";
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}