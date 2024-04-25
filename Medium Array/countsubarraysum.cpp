#include<bits/stdc++.h>
using namespace std;
// basic idea of this problem we have an arr[] = [1, 2, 3, -3, 1, 1, 1, 4, 2, -3]
// the output should be 8 becuse we have sub array with sum K is [1,2], [1,2,3,-3], [3], [-3,1,1,1],....so on
// Need to chek Bruteforce approach after we direct jump on Optimal ok 😉
void countsubarrays(int arr[], int n, int k){
    int cnt = 0;
    for(int i=0; i<n; i++){
        long long sum=0;
        for(int j=i; j<n; j++){
            sum += arr[j];
            if(sum == k) cnt++;
        }
    }
    cout << cnt;
} 
// Taddaaa now 🎉 Optimal 🎉
void countsubarrayso(int arr[], int n, int k){
    map<int,int> mpp;
    mpp[0] = 1;
    int presum = 0, cnt=0;
    for(int i=0; i<n; i++){
        presum +=arr[i];
        int remove = presum - k;
        cnt +=mpp[remove];
        mpp[presum] +=1;
    }
    cout << cnt << endl;
}
// Dry run of optimal 
// arr[0] = 1 , p(1)=0+1, r(-2)=1-3; 0
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int k;
    cin >> k;
    countsubarrayso(arr, n, k);
}