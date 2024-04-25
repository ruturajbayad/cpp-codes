#include<bits/stdc++.h>
using namespace std;
void selection(int arr[], int n){
    for(int i=0; i<=n-2; i++){ 
        int min = i;
        for(int j=i; j<=n-1; j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i]=temp;
    }
}
void bubble(int arr[], int n){
    for(int i=n-1; i>=1; i--)
    {
            for(int j=0;j<=i-1;j++){
                if(arr[j]>arr[j+1]){
                    int temp = arr[j+1];
                    arr[j+1]=arr[j];
                    arr[j]=temp;
                }
            }
    }
}
void insertion(int arr[], int n){
    for(int i=0; i<=n-1; i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
                int temp = arr[j];
                arr[j]= arr[j-1];
                arr[j-1]=temp;
                j--;
        }
    }
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) 
    {
        cin >> arr[i];
    }
    selection(arr, n);
    // bubble(arr,n);
    // insertion(arr,n);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}