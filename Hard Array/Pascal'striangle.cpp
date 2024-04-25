#include<bits/stdc++.h>
using namespace std;
// basic idea to deal with this prolem like we have col and row value 3 and 4 do the ans = 3
// 1         row=1 col= 1
// 1 1       row=2 col= 1 2
// 1 2 1     row=3 col= 1 2 3
// 1 3 3 1   row=4 col= 1 2 3 4 
// so nCr works like n(3)=4-1 and r(2)=3-1 loop run till 2 and res = 1 * 2 and  2/1 ☝
void nCr(int n, int r){
    long long res = 1;
    for(int i=0; i<r; i++){
        res = res * (n-i);
        res = res/(i+1);
    }
    cout << res << endl;
}
// second approach where output will be arr[] = [1 3 3 1] like col=4 ✌
void pascalcol(int n){
    int ans = 1;
    cout << ans << " ";
    for(int i=1; i<n; i++){
        ans = ans * (n-i);
        ans = ans/(i);
        cout << ans << " ";
    }
}
// 🚩 third approach where we print full pascal triangle 🔺 
vector<int> pascaltriangle(int n){
    long long ans = 1;
    vector<int> triangle;
    triangle.push_back(ans);
    for(int col=1; col<n; col++){
        ans = ans * (n-col);
        ans = ans/col;
        triangle.push_back(ans);
    }
    return triangle;
}
void combi(int n){
    vector<vector<int>> ans;
    for(int i=1; i<=n; i++){
        ans.push_back(pascaltriangle(i));
    }
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
}

int main(){

    // Method 1️⃣
    // int row,col;
    // cin >> row >> col ;
    // nCr(row-1,col-1);

    // Method ✌
    // int n;
    // cin >> n;
    // pascalcol(n);

    // Method 3️⃣
    int n;
    cin >> n;
    combi(n);


}