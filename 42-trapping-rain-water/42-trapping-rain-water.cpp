class Solution {
public:
    int trap(vector<int>& a) {
        int res = 0, l = 0, r = a.size() - 1, left_max = 0, right_max = 0;
        while(l <= r)
        {
            if(a[l] <= a[r])
            {
                if(a[l] >= left_max)
                {
                    left_max = a[l++];
                }
                else
                {
                    res += left_max - a[l++];
                }
            }
            else
            {
                if(a[r] >= right_max)
                {
                    right_max = a[r--];
                }
                else
                {
                    res += right_max - a[r--];
                }
            }
        }
        return res;
    }
};