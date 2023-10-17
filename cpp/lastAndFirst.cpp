#include <iostream>
using namespace std;


int firstSearch(int arr[] , int size , int key){

    int start = 0;
    int end = size-1;

    int ans = -1;

    // int mid = (start+end)/2; 

    int mid = start + (end-start)/2; // for out of bound int values

    while(start <= end){


        if(arr[mid] == key) {
            ans  = mid;
            end = mid-1;

        }

        else if ( arr[mid] > key){
            end = mid-1;
            
        }
        else if ( arr[mid] <  key){

            start = mid+1;

        }

            int mid = start + (end-start)/2;

    }
    return ans;
    
}

int lastOccur (int arr[] , int size , int key){

    int start = 0;
    int end = size-1;

    int ans = -1;

    // int mid = (start+end)/2; 

    int mid = start + (end-start)/2; // for out of bound int values

    while(start <= end){

        if(arr[mid] == key) {
            ans  = mid;
            start = mid+1;

        }

        else if ( arr[mid] > key){
            end = mid-1;
            
        }
        else if ( arr[mid] <  key){

            start = mid+1;

        }

            int mid = start + (end-start)/2;

    }
    return ans;
}

int main()
{


    int even[8] ={1,2,3,3,5};
    // int odd[9] ={5,6,8,12,33,36,66,88,89};


    int key = 33;

    cout<<firstSearch(even,8,33)<<endl;


    return 0;
}