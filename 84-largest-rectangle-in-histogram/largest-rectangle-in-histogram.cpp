class Solution
{
    public:
        int largestRectangleArea(vector<int> &A)
        {
            stack<int> st;
            int n = A.size(), maxans = 0;
            for (int i = 0; i <= n; i++)
            {
                while (!st.empty() && (i == n || A[st.top()] >= A[i]))
                {
                    int height = A[st.top()];
                    st.pop();
                    int width;
                    if (st.empty())
                    {
                        width = i;
                    }
                    else
                    {
                        width = i - st.top() - 1;
                    }
                    maxans = max(maxans, height * width);
                }
                st.push(i);
            }
            return maxans;
        }
};