#include <iostream>
using namespace std;


// void swap (int n , int m){
//     int temp;

//     int temp = n;
//     n = m;
//     m = temp;
// }

void printArray(int arr[] , int size){
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    
}




void swapAltr(int arr[] , int size){

    for (int i = 0; i < size; i = i + 2)
    {
        if(i + 1 < size){
            swap(arr[i] , arr[i+1]); // we have an unbuilt swap
        }

    }
    

}

int main()
{
    int even[8] = {2,5,2,6,7,8,1,0};
    int odd[7] = {3,2,6,3,7,8,9};

    swapAltr(even, 8);

    printArray(even , 8);


    return 0;
}