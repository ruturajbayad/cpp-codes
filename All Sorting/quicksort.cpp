#include<bits/stdc++.h>
using namespace std;
int pfunction(vector<int>& arr,int low,int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while(arr[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j) {
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}
void qs(vector<int>& arr, int low, int high){
    if(low<high){
        int partition = pfunction(arr,low,high);
        qs(arr,low,partition-1);
        qs(arr,partition+1,high);
    }
}
int main(){
    int n; 
    cin >> n;
    vector<int> arr;
    for(int i=0; i<n; i++){
        int val;
        cin >> val;
        arr.push_back(val);
    }
    qs(arr,0,n-1);
    for(auto it : arr){
        cout << it << " ";
    }
}