class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /*
        1. sort array
        2. for loop i 0 to n, that move after all triplte form from that i
        3. two pointers j = i+1, k = n(starts from last)
        4. i should always start from starting 
        5. (j < k) j should never cross k 
        6. store triplet in temp and store everythin in ans vector
        */
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if( i > 0 && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k =  nums.size() - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0){
                    j++;
                }
                else if(sum > 0){
                    k--;
                }
                else{
                    vector<int> temp;
                    temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    // after finding a triplet and stroing them move to next new element
                    while(j < k && nums[j] == nums[j-1]) j++;
                    while(j < k && nums[k] == nums[k+1]) k--;
                }
            }


        } 
        return ans;       
    }
};