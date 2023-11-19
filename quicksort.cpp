#include <bits/stdc++.h>
using namespace std;

int partition(int low,int high,vector<int>&arr){
    
   int left=low+1;
    int right=high;
    int pivot=arr[low];
    
    while(left<=right){        
        while(left<=right && arr[left]<pivot){
            left++;
        }
        while(left<=right && arr[right]>=pivot){
            right--;
        }
        if(left<=right){
            swap(arr[left],arr[right]);
        }       
    }  
    swap(arr[right],arr[low]);
    return right;
    
}

void quicksort(int low,int high, vector<int>& arr){ 
    if(low<high){
        
        int pivot=partition(low,high,arr);
        quicksort(low,pivot,arr);
        quicksort(pivot+1,high,arr);
              
    }
}

int rquicksort(int low,int high, vector<int>& arr){
      
        srand(0);
        int rand1=low+rand()%(high-low);
        swap(arr[low],arr[rand1]);
        return partition(low,high,arr); 
}

void randomsort(int low,int high,vector<int>&arr){
    
    if(low<high){       
        int pivot=rquicksort(low,high,arr);
        randomsort(low,pivot,arr);
        randomsort(pivot+1,high,arr);
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n),arr1(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        arr1[i]=arr[i];
    }
    auto start1=clock();
    quicksort(0,n-1,arr);
    auto end1=clock();
    
    auto start2=clock();
    randomsort(0,n-1,arr1);
    auto end2=clock();
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    cout<<"Normal Quick Sort "<<setprecision(10)<<(float)(end1-start1)/CLOCKS_PER_SEC<<endl;
     cout<<"Random Quick Sort "<<setprecision(10)<<(float)(end2-start2)/CLOCKS_PER_SEC<<endl;
    return 0;
}