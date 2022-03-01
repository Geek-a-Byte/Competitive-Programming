#include <bits/stdc++.h>
using namespace std;

// The pattern here is :
// Shift 'n-1' disks from 'A' to 'B'.
// Shift last disk from 'A' to 'C'.
// Shift 'n-1' disks from 'B' to 'C'.
// Take an example for 2 disks :
// Let rod 1 = 'A', rod 2 = 'B', rod 3 = 'C'.

// Step 1 : Shift first disk from 'A' to 'B'.
// Step 2 : Shift second disk from 'A' to 'C'.
// Step 3 : Shift first disk from 'B' to 'C'.

void towerOfHanoi(int n, int from_rod, int to_rod, int aux_rod)
{
    if (n == 1)
    {
        cout << from_rod << " " << to_rod << endl;
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    cout << from_rod << " " << to_rod << endl;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main()
{
    int n;
    cin >> n;
    int total_num_of_moves = pow(2, n) - 1;
    cout << total_num_of_moves << endl;
    towerOfHanoi(n, 1, 3, 2); // A,C,B
    return 0;
}