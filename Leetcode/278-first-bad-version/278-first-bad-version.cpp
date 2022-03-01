// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int mid, ans = -1;
        int l=1;
        int r=n;
        while (l <= r)
        {
            mid = l+(r-l) / 2;
            //base case
            if (isBadVersion(mid))
            {
                //cout << "steps: " << step << endl;
                ans = mid;
                //to get first occurence we have to go to left
                r = mid - 1;
            }
            else
                l = mid + 1;
            // cout<<mid<<endl;
        }
        return ans;

    }
};