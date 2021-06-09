int maxResult(vector<int>& nums, int k) {
        int size = nums.size();
        
        int dp[size];
        dp[size-1] = nums.back();
        
        dp[0] = nums[0];
        
        deque<int> q;
        
        q.push_back(0);
        
        for(int i = 1; i < size; i++){
            dp[i] = nums[i] + dp[q.front()];
            
            while(!q.empty() && dp[i] >= dp[q.back()]){
                q.pop_back();
            }
            
            while(!q.empty() && (i - q.front()) >= k){
                q.pop_front();
            }
            q.push_back(i);
        }
        
        return dp[size-1];
    }