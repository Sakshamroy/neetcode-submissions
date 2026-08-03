class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        // need to sort with saving original indices also
        vector<pair<int, int>> arr;
        //          element, original indexs :- (0,1) element, indices
        // while calling them numsWithIndex[left/right].second (second -> indices)
        for(int i = 0; i < n; i++){
            arr.push_back({nums[i], i});
        }

        //now sort the value
        sort(arr.begin(), arr.end());
        //define two poniters
        int left = 0;
        int right = n-1;
        // base condition 
        while( left < right){
            int sum = arr[left].first + arr[right].first;
            if(sum == target){
                int idx1 = arr[left].second;
                int idx2 = arr[right].second;
                return {min(idx1, idx2), max(idx1, idx2)};
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
