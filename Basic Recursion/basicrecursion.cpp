#include<bits/stdc++.h>
using namespace std;
int cou=0;
void count(){
    if(cou==3) return;
   
    cout << cou << endl;
    cou++;
    count();
}
void printname(int i,int n)
{
    if(i>n) return;
    cout << " hello Rutu! \n";
    printname(i+1,n);
}
void oneton(int i,int n){
    if(i>n) return;
    cout << i << endl;
    oneton(i+1,n);
}
void ntoone(int i, int n)
{
    if(i<1) return;
    cout << i << endl;
    ntoone(i-1,n); 
}
void sumofn(int i,int sum){
    if(i<1) {
        cout << sum; 
        return;
    }
    sumofn(i-1,sum+i);
}
int factorial(int n)
{
    if(n==0) return 1;
     return n * factorial(n-1);
}
int reverse(int start,int end, int arr[])
{
    if(start<end){
        swap(arr[start],arr[end]);
        reverse(start+1,end-1,arr);
    }
}
bool palindrom(int i, string &s){
        if(i==s.length()/2) return true;

        if(s[i]!=s[s.length()-i-1]) return false;
        return palindrom(i+1,s);
}
int febo(int n){
    if(n<=1) return n;
    return febo(n-1) + febo(n-2);
}


int main(){
    int n;

    cin >> n;
      int arr[n];
      for(int i=0; i<n; i++) cin >> arr[i]; 

    // count();
    // printname(0,5);
    // oneton(1,5);
    // ntoone(5,5);
    // sumofn(5,0);
    // cout << factorial(5);

    reverse(0,n-1,arr);
    for(int j=0;j<n;j++) cout << arr[j] << " ";

    /*string s = "MADAM";
    cout << palindrom(0,s);*/

    cout << febo(5);
}