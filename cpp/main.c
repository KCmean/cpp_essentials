#include <stdio.h>
#include <string.h>

char data[28], gen_poly[12], check_value[28];
int data_length, i, j;
#define N strlen(gen_poly)

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
        // check if the first bit is 1 and calls XOR function
        if (check_value[0] == '1')
            XOR();
        // Move the bits by 1 position for the next computation
        for (j = 0; j < N - 1; j++)
            check_value[j] = check_value[j + 1];
        // appending a bit from data
        check_value[j] = data[i++];
    } while (i <= data_length + N - 1);
    // loop until the data ends
}

void receiver()
{

    printf("Enter the received data: ");
    scanf("%s", data);
    printf("Data received: %s", data);
    printf("\n-----------------------------\n");
    // Cyclic Redundancy Check
    crc();
    // Check if the remainder is zero to find the error
    for (i = 0; (i < N - 1) && (check_value[i] != '1'); i++)
        ;
    if (i < N - 1)
        printf("\nError detected\n\n");
    else
        printf("\nNo error detected\n\n");
}

int main()
{

    printf("\nEnter data to be transmitted: ");
    scanf("%s", data);
    printf("\nEnter the Generating polynomial: ");
    scanf("%s", gen_poly);
    data_length = strlen(data);

    // appending n-1 zeros to the data
    for (i = data_length; i < data_length + N - 1; i++)
        data[i] = '0';
    printf("\n Data padded with n-1 zeros : %s", data);
    crc();
    printf("\nCRC or Check value is : %s", check_value);
    // Append data with check_value(CRC)
    for (i = data_length; i < data_length + N - 1; i++)
        data[i] = check_value[i - data_length];
    // printing the final data to be sent
    printf("\n Final data to be sent : %s", data);
    printf("\n----------------------------------------\n");
    // Calling the receiver function to check errors
    receiver();
    return 0;
}
