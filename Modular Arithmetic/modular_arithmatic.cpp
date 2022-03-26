#include <iostream>

using namespace std;

int bigMod(unsigned int base, unsigned int pow, int mod)
{
    unsigned int result = 1;

    //(base^pow)%mod == ((base%mod)^pow)%mod

    base = base % mod; // it will small the base 'base' if it is more than mod
    while (pow > 0)
    {

        //odd
        if (pow & 1)                        //if pow is odd in decimal then in the corresponding binary value the last bit will be 1 always, then if we do bitwise and operation with 1 then the result will be 1 as last digit of pow is 1,otherwise 0
        {                                   // pow%2==1
            result = (result * base) % mod; //at last, always pow becomes 1
        }
        //even
        base = (base * base) % mod; //(b*b)%m

        pow /= 2;
    }
    return result;
}

int main()
{
    unsigned int base, power;
    int mod;
    cin >> base >> power >> mod;

    cout << "Result of (" << base << "^" << power << ")%" << mod
         << "=" << bigMod(base, power, mod) << endl;

    return 0;
}