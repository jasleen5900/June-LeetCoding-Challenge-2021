class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](auto& a, auto& b) { return b[1] < a[1];});
        int maxUnitOfBoxes=0;
        for(auto& box:boxTypes)
        {
            int noOfBox=box[0];
            int noOfUnits=box[1];
            if(truckSize>=box[0])
            {
                maxUnitOfBoxes+=noOfBox*noOfUnits;
                truckSize-=noOfBox;
            }
            else
            {
                maxUnitOfBoxes+=truckSize*noOfUnits;
                return maxUnitOfBoxes;
            }
        }
        return maxUnitOfBoxes;
    }
};