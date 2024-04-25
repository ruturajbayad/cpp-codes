#include<bits/stdc++.h>
using namespace std;
// basic idea of this proble is we have an array arr[] = {-2, -3, 4, -1, -2, 1, 5, -3}
// the output will be the 7 (4,-1,-2, 1, 5)
// optimal with kadane's algoritham
int maxsubarraysum(int arr[],int n){
    int maxi=INT_MIN;
    int sum=0;
    int start=0;
    for(int i=0; i<n; i++){
        if(sum==0) start = i;
        sum = sum + arr[i];
        if(sum>maxi) {
            maxi=sum;
            int starti = start;
            int endi = i;
        }
        if(sum<0) {
            sum=0;
        }
    }
    return maxi;
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int ans = maxsubarraysum(arr,n);
    cout << ans ;
}