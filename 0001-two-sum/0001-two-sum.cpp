class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //target - first element and search for remaining one 
        int find = 0;
        for(int i =0; i < nums.size(); i++){
            find = target - nums[i];
            for(int j = i+1; j < nums.size(); j++){
                if(find == nums[j]){
                    return {i, j};
                }

            }
        }
        return {};
        
    }
};