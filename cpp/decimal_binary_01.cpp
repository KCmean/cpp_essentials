#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int ans = 0;
    int i = 0;
    if ( n >= 0 ) {
    while(n != 0 ){

        int bit = n & 1;

        ans = (bit * pow(10,i) + ans);

        n = n >> 1;

        i++;

    }
    } else {
        
    }

    cout << "answer : " << ans << endl;

    return 0;
}