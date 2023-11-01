#include <iostream>
#include <string>
using namespace std;

string data, gen_poly, check_value;
int data_length, i, j;
#define N gen_poly.length()

void XOR()
{
    for (j = 1; j < N; j++)
        check_value[j] = ((check_value[j] == gen_poly[j]) ? '0' : '1');
}

void crc()
{
    for (i = 0; i < N; i++)
        check_value[i] = data[i];
    do
    {
        if (check_value[0] == '1')
            XOR();
        for (j = 0; j < N - 1; j++)
            check_value[j] = check_value[j + 1];
        check_value[j] = data[i++];
    } while (i <= data_length + N - 1);
}

void receiver()
{
    cout << "Enter the received data: ";
    cin >> data;
    cout << "Data received: " << data;
    cout << "\n-----------------------------\n";
    crc();
    for (i = 0; (i < N - 1) && (check_value[i] != '1'); i++)
        ;
    if (i < N - 1)
        cout << "\nError detected\n\n";
    else
        cout << "\nNo error detected\n\n";
}

int main()
{
    cout << "\nEnter data to be transmitted: ";
    cin >> data;
    cout << "\nEnter the Generating polynomial: ";
    cin >> gen_poly;
    data_length = data.length();

    for (i = data_length; i < data_length + N - 1; i++)
        data[i] = '0';
    cout << "\n Data padded with n-1 zeros : " << data;
    crc();
    cout << "\nCRC or Check value is : " << check_value;
    for (i = data_length; i < data_length + N - 1; i++)
        data[i] = check_value[i - data_length];
    cout << "\n Final data to be sent : " << data;
    cout << "\n----------------------------------------\n";
    receiver();
    return 0;
}
