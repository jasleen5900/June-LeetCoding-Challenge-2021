class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
      if(matchsticks.size() == 0) 
          return false;
      
      int perimeter = 0;
      for(int i = 0; i < matchsticks.size(); i++){
         perimeter += matchsticks[i];
      }
        
      if(perimeter % 4 !=0) 
          return false;
        
      sort(matchsticks.rbegin(), matchsticks.rend());
        
      int side=perimeter/4;
      vector <int> sides(4,side);
        
      return makesquareHelper(0, sides, matchsticks);
   }
    
    bool makesquareHelper(int idx, vector<int>& sides, vector<int>& matchsticks)
    {
        if(idx >= matchsticks.size())
         return sides[0] == sides[1] && sides[1] == sides[2] && sides[3] == 0;
    
      for(int i = 0; i < 4; i++){
          
         if(matchsticks[idx] > sides[i])
             continue;
          
         sides[i] -= matchsticks[idx];
          
         if(makesquareHelper(idx + 1, sides, matchsticks)) 
             return true;
          
         sides[i] += matchsticks[idx];
      }
        
      return false;
    }
};