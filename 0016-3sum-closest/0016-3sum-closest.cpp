class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //|sum - target|
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int closestsum = nums[0] + nums[1] + nums[2];

        for(int i = 0; i < n; i++){
            int j = i +1;
            int k = n-1;
            
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                
                int diff = abs(sum - target);

                if(diff < abs(closestsum - target)){
                    closestsum = sum;
                }

                if(sum > target){
                    k--;
                }
                else if(sum < target){
                    j++;
                }
                else{
                    return target;
                }
            }

        }
        return closestsum;

        
    }
};