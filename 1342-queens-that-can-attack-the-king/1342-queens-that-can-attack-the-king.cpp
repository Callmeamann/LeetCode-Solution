class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> valid;
        vector<vector<bool>> b(8,vector<bool>(8,false));

        for(auto& q : queens)
            b[q[0]][q[1]] = true;

        int kx = king[0] , ky = king[1];

        for(int i = -1 ; i<=1 ; ++i){
            for(int j=-1 ; j<=1 ; ++j){
                if(i!=0 || j!=0){
                    int x = kx+i , y = ky +j;
                    while(min(x,y) >= 0 && max(x,y) <8){
                        if(b[x][y]){
                            valid.push_back({x,y});
                            break;
                        }
                        x+=i;
                        y+=j; 
                    }
                }
            }
        }
        return valid;
    }
};