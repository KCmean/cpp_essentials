#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int ans = 0;
    int i = 0;

    // if (n >= 0)
    // {
    //     while (n != 0)
    //     {

    //         int bit = n & 1;

    //         ans = (bit * pow(10, i) + ans);

    //         n = n >> 1;

    //         i++;
    //     }
    // }
    // else
    // {
        // n = n * -1;

        // while (n != 0)
        // {
        //     int bit = n ^ 1;

        //     ans = (bit * pow(10, i) + ans);

        //     n = n >> 1;

        //     i++;
        // }

        // int newAns = int(ans);
        // newAns = ~newAns;
        // newAns = newAns + 1;
        // ans = float(newAns);

        // n = -n;  Make n positive for further processing

    //     while (n != 0) {
    //         int bit = n & 1;
    //         ans += (bit * pow(10, i));
    //         n = n >> 1;
    //         i++;
    //     }

    //     int newAns = int(ans);
    //     newAns = ~newAns;
    //     newAns = newAns | 1;
    //     ans = float(newAns);    
    

    // }
    // cout << "answer : " << ans << endl;
    

    while ( n!= 0) {
        int bit = n &1; // yaha bit nahi digit nikal na hai lappu 

        if(bit == 1){
            ans = ans + pow(2,i);
        }

        n = n >> 1;
        i++;
    }

    return 0;
}