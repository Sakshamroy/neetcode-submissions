class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        
        vector<int> arr2(2 * nums.size());
        for(int i = 0; i < nums.size(); i++){
            arr2[i] = nums[i];
            arr2[i+nums.size()] = nums[i];
        }
        return arr2;
        

        
    }
    
};