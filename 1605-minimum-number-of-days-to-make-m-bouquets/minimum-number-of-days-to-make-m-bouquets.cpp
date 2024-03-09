class Solution {
public:
    long long int start = 0 , end = 0 , mid = start + ( end - start ) / 2 ;

    bool isValid( vector<int>& nums , int m , int k ) {
        int bouquet = 0 , flower = 0 ;

        for ( int i = 0 ; i < nums.size() ; i++ ) {
            if ( nums[i] <= mid ) {
                flower++ ;
                if ( flower == k ) {
                    flower = 0 ;
                    bouquet++ ;
                }
            }
            else {
                flower = 0 ;
            }
        }
        if (bouquet >= m ) return true ;
        return false ;
    }


    int minDays(vector<int>& nums, int m, int k) {

        if ( (long long) m * k  > nums.size() ) return -1 ;

        end = *max_element(nums.begin(), nums.end());


        while ( start <= end ){
            mid = start + ( end - start ) / 2 ;

            if( isValid(nums , m , k)){
                end = mid - 1 ;
            }
            else start = mid + 1 ;

            
        }
        return start ;
    }
};