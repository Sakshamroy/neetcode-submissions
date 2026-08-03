class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); // sort nums 
        //define two poniters
        int left = 0;
        int right = n-1;
        // base condition 
        while( left < right){
            int sum = nums[left] + nums[right];
            if(sum == target){
                return {left, right};
            }
            else if (sum < target){
                left++;
            }
            else{
                right --;
            }
        }
        
        
        

    return {-1,-1};  
    }
};
