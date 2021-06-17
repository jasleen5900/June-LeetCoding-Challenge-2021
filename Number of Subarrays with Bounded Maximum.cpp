class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int result = 0, start = 0, end = 0, windowCount = 0;
        
        while(end<nums.size()){
            
            // element within the range recalculate the window
            if(nums[end]>=left && nums[end]<=right) windowCount = end-start+1;
            
            // element outside the right range, update start  + reset window
            else if(nums[end]>right){
                windowCount = 0;
                start = end +1;
            } 
            
            // element less than range use previous window            
            else  if(nums[end] < left)   windowCount = windowCount;
            
            result +=  windowCount;
            end++;
        }
        return result;
    }
};