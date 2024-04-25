#include<bits/stdc++.h>
using namespace std;
// basic idea of the proble we have an arry = [4 2 2 6 4] and value of k=6
// we calculate the sub array like 4^2=6 cont = 1, 2^2=0 not valid, 2^2^6 = 6 cont=2, so on.....
// optimal hashmap method where we sotore not conted values 
void numberofsubxork(int arr[], int n, int k){
    int xr = 0;
    map<int,int> mpp;
    mpp[xr]++;
    int cont = 0;
    for(int i=0; i<n; i++){
        xr = xr ^ arr[i];
        int x = xr ^ k ;
        cont = cont + mpp[x];
        mpp[xr]++;
    }
    cout << cont ;
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n; i++){
        cin >> arr[i];
    }
    int k;
    cin >> k;
    numberofsubxork(arr,n,k);
}