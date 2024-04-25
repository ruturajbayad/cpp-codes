#include<bits/stdc++.h>
using namespace std;
// optimal
void longestsumk(int arr[], int n, int k){
    int left=0;
    int right=0;
    long long sum = arr[0];
    int maxlen=0;
    while(right < n){
        while(sum > k && left<=right){
            sum -=arr[left];
            left++;
        }
        if(sum == k){
         maxlen = max(maxlen, (right - left + 1));
        }
        right++;
        if(right < n) sum+=arr[right];
    }
    cout << maxlen;
}
int main(){
    int n; 
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << "enter value of k" << endl;
    int k;
    cin >> k;
    longestsumk(arr,n,k);
}