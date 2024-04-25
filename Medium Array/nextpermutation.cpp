#include<bits/stdc++.h>
using namespace std;
// basic idea about this problem is we have an array like arr[] = [3, 1, 2]
// the next permutation should be 312< ans 321 👍
void nextpermutation(int arr[], int n){
    int ind = -1;
    for(int i=n-2; i>=0; i--){
        if(arr[i]<arr[i+1]){
            ind = i;
            break;
        }
    }
    if(ind == -1){
        reverse(arr,arr+n);
    } 
    for(int i=n-1; i>=ind; i--){
        if(arr[i]>arr[ind]){
            swap(arr[i],arr[ind]);
            break;
        }
    }
    reverse(arr+ind+1,arr+n);
}
// input 7 = 2 1 5 4 3 0 0
// output = 2 3 0 0 1 4 5 😉
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    nextpermutation(arr,n);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}