class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // brute force
            //target - first element and search for remaining one 
        //optimization
            // use map to store elements, index values
        unordered_map<int, int> mp;//storing all elements asn there indexing values 

        
        int find = 0;
        for(int i =0; i < nums.size(); i++){
            find = target - nums[i];

            if(mp.count(find)){
                return{mp[find], i};
            }
            mp[nums[i]]= i;
        
        }
        return {};
        
    }
};