#include <iostream>
#include <vector>
using namespace std;


bool isPossible(vector<int> arr, int n, int m, int mid){
    
    int stdCount = 1;
    int pageSuum = 0;

    for (int i = 0; i < n; i++)
    {
        if(pageSuum + arr[i] <= mid){
            pageSuum += arr[i];
        }
        else{
            stdCount++;
            if(stdCount > m || arr[i] > mid){
                return false;
            }
            pageSuum = arr[i];
        }
    }
    return true;
}

int allocateBooks(vector<int> arr, int n, int m)
{

    int s = 0;
    int sum = 0;

    for (int i = 0; i < n; i++){
        sum += arr[i];
    }

    int e = sum;
    int ans = -1;
    int mid = s + (e-s)/2;

    while(s<=e){
        if(isPossible(arr, n, m, mid)){
           ans = mid;
           e= mid - 1;
        }
        else{
            s = mid + 1;
        }
            int mid = s + (e-s)/2;

    }
    return ans;
}

int main()
{
    cout << "Hello World" << endl;
    vector<int> arr = {10,20,30,40};
    int n = 2;
    int m = 2;

    cout << allocateBooks(arr, n, m) << endl;
    return 0;
}