#include <bits/stdc++.h>

int main()
{
    std::vector<int> v{10, 20, 30, 30, 50};

    // Print vector
    std::cout << "Vector contains :";
    for (unsigned int i = 0; i < v.size(); i++)
        std::cout << " " << v[i];
    std::cout << "\n";

    std::vector<int>::iterator low, upp;

    std::cout << "******* lower_bound *********" << std::endl;
    low = std::lower_bound(v.begin(), v.end(), 20);
    std::cout << "\nlower_bound for element 20 at position : " << (low - v.begin());
    low = std::lower_bound(v.begin(), v.end(), 25);
    std::cout << "\nlower_bound for element 25 at position : " << (low - v.begin()) << std::endl;

    std::cout << "****** upper_bound ************" << std::endl;
    upp = std::upper_bound(v.begin(), v.end(), 30);
    std::cout << "\nupper_bound for element 30 at position : " << (upp - v.begin());
    upp = std::upper_bound(v.begin(), v.end(), 25);
    std::cout << "\nupper_bound for element 25 at position : " << (upp - v.begin());

    return 0;
}
