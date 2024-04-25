#include<bits/stdc++.h>
using namespace std;
// basic idea of this problem is we have an arr[] = [10,22,12,3,0,6]
// so the output should be [22,12,6] becuse those numbers are larger then its right side but 3 and 10 are not 👍
// jumping on optimal approach 🐱‍🏍
void leadersinarray(int arr[], int n){
    vector<int> leaders;
    int maxnum = INT_MIN;
    for(int i=n-1; i>=0; i--){
        if(arr[i] > maxnum){
            leaders.push_back(arr[i]);
        }
        maxnum = max(maxnum,arr[i]);
    }
    for(auto it : leaders){
        cout << it << " ";
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    leadersinarray(arr,n);

}