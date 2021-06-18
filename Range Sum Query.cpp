// // Binary Index Tree
// class NumArray {
// private:
//     int n;
//     vector<int> tree;
//     vector<int> numbers;
   
// public:
//     NumArray(vector<int>& nums) {
//         n = nums.size();
//         numbers.resize(n, 0);
//         tree.resize(n+1, 0);
       
//         for (int i = 0; i < n; i++) {
//             update(i, nums[i]);
//         }
//     }
   
//     void update(int index, int val) {
//         int newInd = index+1, addVal = val - numbers[index];
//         numbers[index] = val;
       
//         while (newInd <= n) {
//             tree[newInd] += addVal;
//             newInd += newInd & -newInd;
//         }
//     }
   
//     int sumRange(int left, int right) {
//         return getSum(right) - getSum(left-1);
//     }
   
//     int getSum(int index) {
//         int curSum = 0, newInd = index+1;
//         while (newInd >= 1) {
//             curSum += tree[newInd];
//             newInd -= newInd & -newInd;
//         }
//         return curSum;
//     }
// };

// Segment Tree
class NumArray {
private:
    int n;
    vector<int> tree;
    vector<int> numbers;
   
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        numbers = nums;
        tree.resize(100000, 0);
        buildTree(0, 0, n-1);
    }
   
    void update(int index, int val) {
        upd(0, 0, n-1, index, val);
    }
   
    int sumRange(int left, int right) {
        return query(0, 0, n-1, left, right);
    }
   
    void buildTree(int node, int start, int end) {
        if (start == end) {
            tree[node] = numbers[start];
            return;
        }
        int mid = start + (end - start)/2;
        int leftNode = 2 * node + 1, rightNode = 2 * node + 2;
        buildTree(leftNode, start, mid);
        buildTree(rightNode, mid+1, end);
        tree[node] = tree[leftNode] + tree[rightNode];
    }
   
    void upd(int node, int start, int end, int index, int val) {
        if (start == end) {
            numbers[index] = val;
            tree[node] = val;
            return;
        }
        int mid = start + (end - start)/2;
        int leftNode = 2 * node + 1, rightNode = 2 * node + 2;
        if (index >= start && index <= mid) {
            upd(leftNode, start, mid, index, val);
        }
        else {
            upd(rightNode, mid+1, end, index, val);
        }
        tree[node] = tree[leftNode] + tree[rightNode];
    }
   
    int query(int node, int start, int end, int left, int right) {
        if (right < start || left > end) {
            return 0;
        }
        else if ((left <= start && end <= right) || start == end) {
            return tree[node];
        }
        int mid = start + (end - start)/2;
        int leftNode = 2 * node + 1, rightNode = 2 * node + 2;
        int leftSum = query(leftNode, start, mid, left, right);
        int rightSum = query(rightNode, mid+1, end, left, right);
       
        return leftSum + rightSum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */