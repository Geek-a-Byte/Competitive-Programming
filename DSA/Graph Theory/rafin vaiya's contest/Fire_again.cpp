
// ********Problem - 35C - Codeforces **************//
#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
    std::ifstream infile("theinputfile.txt");
    std::ofstream outfile("theoutputfile.txt");

    int a, b;
    while (infile >> a >> b)
    {
        outfile << a << " " << b << "\n";
        if (a == 0)
            break;
        outfile << a << " " << b << "\n\n";

        // process pair (a,b)
    }
}
