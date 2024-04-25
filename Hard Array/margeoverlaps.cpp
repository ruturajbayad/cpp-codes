#include<bits/stdc++.h>
using namespace std;
void margeoverlaps(vector<vector<int>>& arr, int n){
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
        if (ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        }else {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
   for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
}
int main(){
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    int n = arr.size();
    margeoverlaps(arr,n);
}