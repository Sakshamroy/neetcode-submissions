class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string word : strs) {
            // Frequency array for 26 lowercase letters
            vector<int> freq(26, 0);

            // Count frequency of each character
            for (char ch : word) {
                freq[ch - 'a']++;
            }

            // Convert frequency array into a unique string key
            string key = "";
            for (int count : freq) {
                key += to_string(count) + "#";
            }

            // Store the word in the corresponding group
            mp[key].push_back(word);
        }

        // Collect all groups
        vector<vector<string>> ans;
        for (auto &it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};