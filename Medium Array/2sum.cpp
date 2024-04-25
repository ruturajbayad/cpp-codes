#include<bits/stdc++.h>
using namespace std;
// better 
void towsum(int arr[], int n, int target){
    map<int,int> mpp;
    for(int i=0; i<n; i++){
        int a = arr[i];
        int more = target - a;
        if(mpp.find(more)!=mpp.end()){
            cout << mpp[more] << "," <<  i;
            return;
        }
        mpp[a]=i;
    }
    cout << "NO";
}
// optimal but only return YES and NO 
void twosumnext(int arr[], int n, int target){
    int left=0,right=n-1;
    sort(arr,arr+n);
    while(left < right){
        int sum = arr[left] + arr[right];
        if(sum==target){
            cout << "Yes" ;
            return;
        }else if(sum < target){
            left++;
        }else{
            right--;
        }
    }
    cout << "No";
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int target;
    cin >> target;
    twosumnext(arr,n,target);
}