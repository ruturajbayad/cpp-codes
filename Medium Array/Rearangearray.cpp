#include<bits/stdc++.h>
using namespace std;
// basic idea about this problem is we have an array arr[] = [3, -1, -2, 5, 6]
// and the output should be = [3, -1, 5, -2, 6] this way
// bruteforce work when value are equally in array 🙌
void rearangearray(int arr[], int n){
    vector<int> pos, neg;
    for(int i=0; i<n; i++){
        if(arr[i] > 0){
            pos.push_back(arr[i]);
        }else{
            neg.push_back(arr[i]);
        }
    }
    for(int i=0; i<n/2; i++){
        arr[2*i] = pos[i];
        arr[2*i+1] = neg[i];
    }
}
// optimal varinant1 ✌
void rearangearrayov(int arr[],int n){
    int positive =0;
    int nagetive =1;
    int arra[n];
    for(int i=0; i<n; i++){
        if(arr[i]<0){
            arra[nagetive] = arr[i];
            nagetive+=2;
        }else{
            arra[positive] = arr[i];
            positive+=2;
        }
    }
    for(auto it : arra){
        cout << it << " ";
    }
}
// optimal variant 2 it is for more positive and more negetive ex arr[] = [-1, 2, 3, 4, -3, 1]  👍
void rearangearrayov2(int arr[], int n){
    vector<int> pos, neg;
    for(int i=0; i<n; i++){
        if(arr[i]>0){
            pos.push_back(arr[i]);
        }else{
            neg.push_back(arr[i]);
        }
    }
    if(pos.size() > neg.size()){
        for(int i=0; i<neg.size(); i++){
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }
        int index = neg.size()*2;
        for(int i=neg.size(); i<pos.size(); i++){
            arr[index] = pos[i];
            index++;
        }
    }else{
        for(int i=0; i<pos.size(); i++){
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }
        int index = pos.size()*2;
        for(int i=pos.size(); i<neg.size(); i++){
            arr[index] = neg[i];
            index++;
        }
    }
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    rearangearrayov2(arr,n);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}