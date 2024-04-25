#include<bits/stdc++.h>
using namespace std;
// basic idea logest consicutive sequence we have an arr[] = [102, 4, 101, 1, 100, 2, 3, 4]
// output will be [4] becuse ☝ is [1,2,3,4] so...
// optimal 😉
void longestconsicutiveseq(int arr[], int n){
    int longest = 1;
    unordered_set<int> st;
    for(int i=0; i<n; i++){
        st.insert(arr[i]);
    }
    for(auto it : st){
        if(st.find(it-1)==st.end()){
            int cnt=1;
            int x=it;
            while (st.find(x+1)!=st.end())
            {
                x = x+1;
                cnt = cnt +1;
            }
            longest = max(longest,cnt);
        }
    }
    cout << longest ;

}
int main(){
    int n; 
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    longestconsicutiveseq(arr,n);
}