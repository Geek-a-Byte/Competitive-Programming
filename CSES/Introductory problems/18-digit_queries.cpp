#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

signed main()
{
    int q;
    cin >> q;
    vector<int> power_of_tens(18, 1);
    for (int i = 1; i < 19; i++)
    {
        power_of_tens[i] = power_of_tens[i - 1] * 10;
    }
    while (q--)
    {
        int ind;
        cin >> ind;
        int digits_so_far = 0;
        int digits_before_actual_block = 0;
        int number_of_digits;
        for (int i = 1; i <= 18; i++)
        {
            digits_so_far += (power_of_tens[i] - power_of_tens[i - 1]) * i; // (100-10)*2=90*2=180
            if (digits_so_far >= ind)                                       // 180>=107
            {
                number_of_digits = i;
                break;
            }
            digits_before_actual_block += (power_of_tens[i] - power_of_tens[i - 1]) * i; //(10-1)*1=9
        }
        // cout<<number_of_digits<<endl;
        // cout<<digits_so_far<<endl;
        // cout<<digits_before_actual_block<<endl;
        int smallest_value_of_actual_block = power_of_tens[number_of_digits - 1]; // 10
        int largest_value_of_actual_block = power_of_tens[number_of_digits] - 1;  // 99
        int best = 0;
        int starting_position_of_best = 0;
        while (smallest_value_of_actual_block <= largest_value_of_actual_block)
        {
            int mid = (smallest_value_of_actual_block + largest_value_of_actual_block) / 2;
            int starting_position_of_mid = (digits_before_actual_block + 1) + (mid - power_of_tens[number_of_digits - 1]) * number_of_digits;
            if (starting_position_of_mid <= ind) // 50<107
            {
                best = mid;
                starting_position_of_best = starting_position_of_mid;
                smallest_value_of_actual_block = mid + 1;
            }
            else
            {
                largest_value_of_actual_block = mid - 1;
            }
        }
        string number = to_string(best);
        cout << number[ind - starting_position_of_best] << endl; // 107-106
    }
}