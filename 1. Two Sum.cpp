class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int pos1 = 0 , pos2 = 0 ;
        for( int i = 0 ; i < nums.size()-1 ; i++ )
        {
            int x = target -nums[i] ;
            for(int j = i+1; j < nums.size() ; j++ )
            {
                if( x == nums[j])
                {
                    pos1 = i ;
                    pos2 = j;
                }
            }
        }
        return {pos1,pos2} ;

    }
};
