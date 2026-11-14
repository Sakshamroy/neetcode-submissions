class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans; // to store triplet
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i   = 0; i < n; i++){
          //skipping dulpicate values
          if(i > 0 && nums[i] == nums[i-1]) continue;
          //declare pointers
          int j = i +1;
          int k = n-1;

          while( j < k){
            int sum = nums[i] + nums[j] + nums[k];

            if(sum > 0){
                k--;
            }
            else if(sum < 0){
                j++;
            }
            else{
                vector<int> temp = {nums[i] , nums[j] , nums[k]};
                ans.push_back(temp);

                //skipping duplicate values
                j++;
                k--;

                while(j < k && nums[j] == nums[j-1]) j++;
                while(j < k && nums[k] == nums[k+1] ) k--;


            }
          }
        }
        return ans;
        
    }
};