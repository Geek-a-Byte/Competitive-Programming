class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        /*
        logic
        1. first e array er first to second last porjonto loop ghuraye prottektar jonno bakigular shathe slope ber korbo, last er tar jonno autoi shob gula agei calculate hoye jabe
        2. ekta map e same slope er against e koto gula point hocche tar count rakhbo
        3. shob gula slope er jonno max point er count ber korbo, etai ans
        4. ans er shathe 1 jog korbo as slope er count 2 mane ek line e 3 point er jonno count dise.
        */
        int n=points.size();
        if(n==1)
        {
            return 1; //ekta hoile 1 return korbe
        }
        else
        {
            int ans=0;
            for(int i=0;i<n-1;i++)
            {
                map<double,int>same_slope_count;
                for(int j=i+1;j<n;j++)
                {
                    if(points[i][0]==points[j][0])
                    {
                        same_slope_count[-90]++;
                    }
                    else
                    {
                        double x=(double)(points[j][1]-points[i][1])/(double)(points[j][0]-points[i][0]);
                        same_slope_count[x]++;
                    }
                }
                int max_slope=0;
                for(auto m:same_slope_count)
                {
                    if(m.second>max_slope)
                    {
                        max_slope=m.second;
                    }
                }
                ans=max(ans,max_slope);
            }
            return ans+1;
        }
        
    }
};


class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int ans=-1;
        int left_sum=0;
        int right_sum=0;
        for(int i=0;i<nums.size();i++)
        {
            right_sum+=nums[i];
        }
        right_sum-=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            cout<<left_sum<<" "<<right_sum<<endl;
            if(left_sum==right_sum)
            {
                ans=i;
                break;
            }
            left_sum+=nums[i];
            right_sum-=nums[i+1];
            // cout<<left_sum<<" "<<right_sum<<endl;
        }
        return ans;
        
    }
};