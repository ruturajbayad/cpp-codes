#include<bits/stdc++.h>
using namespace std;
void findmandr(long long arr[],long long n){
    long long SN = (n*(n+1))/2;   // all 1+2+3+4+.....+N
    long long S2N = (n*(n+1)*(2*n+1))/6; // all 1^2 + 2^2 + 3^2 + ..... + N^2
    long long s=0,s2=0; 
    for(long long i=0; i<n; i++){
        s += arr[i];            //same with array ☝ but for array 
        s2 += (long long)arr[i] * (long long)arr[i];  // same with ☝
    }
    long long val1=s-SN;   // ans of x - y = val1
    long long val2=s2-S2N; // ans of x^2 - y^2 = val2 
    val2=val2/val1;        // ans val2 / val 1
    long long x = (val1 + val2)/2;  // ans of x
    long long y = x-val1;           // ans y
    cout << (int)x << " " << (int)y;
}
int main(){
    long long n;
    cin >> n;
    long long arr[n];
    for(long long i=0; i<n; i++){
        cin >> arr[i];
    }
    findmandr(arr,n);

}