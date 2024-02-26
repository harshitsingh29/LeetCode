class Solution
{
    public:

        vector<vector<string>> res;

        bool palin(string s, int start, int end)
        {
            while (start <= end)
            {
                if (s[start++] != s[end--])
                {
                    return false;
                }
            }
            return true;
        }

    void fun(int ind, int n, vector<string> &part, string s)
    {
        if (ind == n)
        {
            res.push_back(part);
        }
        for (int i = ind; i < n; i++)
        {
            if (palin(s, ind, i))
            {
                part.push_back(s.substr(ind, i - ind + 1));
                fun(i + 1, n, part, s);
                part.pop_back();
            }
        }
    }

    vector<vector < string>> partition(string s)
    {
        int n = s.length();
        vector<string> part;
        fun(0, n, part, s);
        return res;
    }
};