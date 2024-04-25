#include<bits/stdc++.h>
using namespace std;
// arr[]= {7, 1, 5, 3, 6, 4} ans = 5
int buysellstock(int arr[], int n){
    int maxprofit = 0;
    int mini = arr[0];                     //7 
    for(int i=1; i<n; i++){
        int cost = arr[i] - mini;          // -6 =1 - 7   //next 4=5-1 //next 2=3-1 //next 5=6-1 //next 3=4-1
        maxprofit = max(maxprofit, cost);  // 0           // 4         //4          //5          //ans = 5
        mini = min(mini,arr[i]);           //1            // 1        //1          //1          //1
    }
    return maxprofit;
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int maxprofit = buysellstock(arr,n);
    cout << maxprofit;
}