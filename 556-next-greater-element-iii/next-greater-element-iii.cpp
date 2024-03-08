class Solution {
public:

    bool fun(long long int num) {
        if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min()) {
            return false;
        } else {
            return true;
        }
    }

    int nextGreaterElement(int n) {
        long long int num = n;
        if(!fun(num)) {
            return -1;
        }
        std::string v = std::to_string(num);
        int i, k = v.length();
        for(i = k-1; i >= 0; i--) {
            if(v[i] < v[i+1]) {
                break;
            }
        }
        if(i < 0) {
            return -1;
        }
        for(int j = k-1; j > i; j--) {
            if(v[j] > v[i]) {
                std::swap(v[j], v[i]);
                break;
            }
        }
        std::reverse(v.begin()+i+1, v.end());
        num = std::stoll(v);
        if(!fun(num)) {
            return -1;
        }
        return static_cast<int>(num);
    }
};