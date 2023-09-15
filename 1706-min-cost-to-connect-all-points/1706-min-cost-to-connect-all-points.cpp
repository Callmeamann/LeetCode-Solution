class Solution {
private:
    int manhattanDistance(int x1,int y1,int x2,int y2){
        return abs(x1-x2) + abs(y1-y2);
    }

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        if(points.size() < 1 ) return 0;

        unsigned sz = points.size();
        vector<int> minDists(sz,0);
        int result = 0;
        minDists[0] = INT_MAX;
         
        for(int i=1 ; i<sz ; ++i){
            minDists[i] = manhattanDistance(points[0][0],points[0][1],points[i][0],points[i][1]);
        }

        for(auto i = 1 ; i<sz ; ++i){
            auto itr = min_element(minDists.begin(),minDists.end());
            result += *itr;
            int idx = itr - minDists.begin();
            *itr = INT_MAX;
            for(auto j = 0 ; j<sz ; ++j){
                if(minDists[j] != INT_MAX)
                    minDists[j] = min(minDists[j], manhattanDistance(points[j][0],points[j][1],points[idx][0],points[idx][1]));
            }
        }
        return result;
    }
};