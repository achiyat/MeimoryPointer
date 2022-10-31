#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

int bit(int num, int moves)
{
    int a;
    a = num << moves;
    printf("%d\n", a);

    return a;
}

unsigned char bit3(unsigned char num)
{
    unsigned char mask = 0b10000000;
    for (int i = 1; i <= 8; i++)
    {
        char bit1 = num & mask;
        mask = mask >> 1;
        if (bit1 != 0)
        {
            printf("1");
        }
        else {
            printf("0");
        }

    }
    printf("\n");
    return 0;
}

unsigned char bit4(unsigned char num)
{
    char sum = 1;
    for (int i = 1; i < num; i++)
    {
        sum = sum * 2;
    }

    if (sum <= 2)
    {
        bit3(sum);
    }
    else if (sum >= 3)
    {
        bit3(sum);
    }
    return 0;
}

int bit5(int num)
{
    int sum = 1;
    if (num >= 3)
    {
        for (int i = 1; i < num; i++)
        {
            sum = sum * 2;
        }
    }
    else
    {
        for (int i = 1; i <= num - 1; i++)
        {
            sum = sum + 1;
        }
    }

    printf("%d\n", sum);

    return bit3(sum);
}

unsigned char bit6(unsigned char num, int inx) // N = 5
{
    unsigned char num2;
    unsigned char num3;
    unsigned char mask = 0b00000001;
    if (inx == 0)
    {
        num2 = mask << num - 1; // 00010000 <4< 00000001

        mask = 0b10000000;
        for (int i = 1; i <= 8; i++)  // print num2
        {
            char bit1 = num2 & mask;
            // N = 00010000
            // M = 10000000
            mask = mask >> 1;
            if (bit1 != 0)
            {
                printf("1");    // print num "1" only in 5 ===> 0001...0
            }
            else {
                printf("0");
            }
        }
        printf("\n");
    }
    else  // inx && N = 3
    {
        mask = 0b00000001;
        num = mask << num - 1;   // 00000100 <2< 00000001
        num2 ^= num; // if (1=0,0=1) => 1 , all (1=1,0=0)=> 0
        // N2 = 00010000        When num "5" in the second time = 00010100
        // N  = 00000100        When num "5" in the second time = 00010000
        // N2(new) = 00010100   When num "5" in the second time = 00000100
        mask = 0b10000000;
        for (int i = 1; i <= 8; i++)  // print num2
        {
            char bit1 = num2 & mask;
            mask = mask >> 1;
            if (bit1 != 0)
            {
                printf("1");     // print num "1" in (5) && print(3) ==> 00010100
            }
            else {
                printf("0");     // When num "5" in the second time = 0001...0 ==> 0000...0
            }
        }
        printf("\n");
    }


    return 0;
}

int main()
{
    // תרגיל 1
    printf("bit1\n");
    bit(2, 1);

    // תרגיל 3
    printf("\nbit3\n");
    bit3(64);

    //תרגיל 4
    printf("\nbit4\n");
    bit4(4);

    //תרגיל 5
    printf("\nbit5\n");
    int a = 0;
    int num;

    printf("(+5) ");
    //scanf("%d", &num);
    bit6(5, 0); printf("(+3) ");
    //scanf("%d", &num);
    bit6(3, 1); printf("(-5) ");
    //scanf("%d", &num);
    bit6(5, 1);

    printf("\n"); printf("(+4) ");
    bit6(4, 1); printf("(+7) ");
    bit6(7, 1); printf("(-3) ");
    bit6(3, 1); printf("(-4) ");
    bit6(4, 1);

    return 0;
}