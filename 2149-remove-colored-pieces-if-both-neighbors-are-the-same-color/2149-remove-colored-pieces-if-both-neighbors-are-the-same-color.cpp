class Solution {
public:
    bool winnerOfGame(string colors) {
        int aChances =0,bChances=0;
        for(int i=1 ; i<colors.size()-1 ; ++i){
            if(colors[i] == colors[i+1] && colors[i] == colors[i-1]){
                if(colors[i] == 'A') aChances++;
                else bChances++;
            }
        }
        return aChances > bChances;
    }
};