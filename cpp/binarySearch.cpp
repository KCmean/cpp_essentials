#include <iostream>
using namespace std;


int binarySearch(int arr[] , int size , int key){

    int start = 0;
    int end = size-1;


    int mid = start + (end-start)/2; 


    while(start <= end){

        if(arr[mid] == key){
            return mid;
        }

        if(key > arr[mid] ){
            start = mid+1;
        }

        else{
            end = mid-1;
        }

        mid = start + (end-start)/2;

    }

    return -1;
}

int main()
{


    int even[8] ={2,6,7,12,33,36,77,81};
    int odd[9] ={5,6,8,12,33,36,66,88,89};


    int key = 33;

    cout<<binarySearch(even,8,33)<<endl;


    return 0;
}