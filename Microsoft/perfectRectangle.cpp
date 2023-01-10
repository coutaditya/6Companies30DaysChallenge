// INTUITION: 
// If it is a valid rectangle, all interior points should have count 0, bootom left most and top right most point should have value 1, and top left and bottom right should have count -1. If it is different than this, it is not a perfect rectangle.

// COMPLEXITY:
// Time complexity: O(n)
// Space complexity: O(n)

// CODE:
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int, int>, int> m;

        for(auto i:rectangles){
            m[{i[0],i[1]}]++;
            m[{i[2],i[3]}]++;
            m[{i[0],i[3]}]--;
            m[{i[2],i[1]}]--;
        }
        int c = 0;
        for(auto i:m){
            if(i.second!=0){
                if(i.second!=-1 && i.second!=1) return false;

                c++;
            }
        }

        return c==4;
    }
};