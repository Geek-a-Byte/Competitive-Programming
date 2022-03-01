#include <iostream>
#include <math.h>
using namespace std;

int getLength(long long value)
{
    int counter = 0;
    while (value != 0)
    {
        counter++;
        value /= 10;
    }
    return counter;
}

long long karatsuba_multiply(int x, int y)
{
    int xLength = getLength(x);
    int yLength = getLength(y);

    // the bigger of the two lengths
    int N = fmax(xLength, yLength);

    // if the max length is small it's faster to just flat out multiply the two nums
    if (N < 10)
        return x * y;

    //max length divided and rounded up
    N = (N / 2) + (N % 2);

    long long multiplier = pow(10, N);

    int a = x / multiplier;
    int b = x - (b * multiplier);
    int c = y / multiplier;
    int d = y - (d * multiplier);

    long long z0 = karatsuba_multiply(a, c);
    long long z1 = karatsuba_multiply(b, d);
    long long z2 = karatsuba_multiply(a + b, c + d);

    return z1 + ((z2 - z0 - z1) * multiplier) + (z0 * (long long)(pow(10, 2 * N)));
}

// C++ example (uses cout...)
// (this code works in straight C too though if you use a different main function)
int main()
{
    // two numbers
    int a = 1234;
    int b = 5678;
    cout << karatsuba_multiply(a, b) << endl;
    return 0;
}