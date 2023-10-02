class Solution {
    public boolean winnerOfGame(String colors) {
        int aChances =0,bChances=0;
        for(int i=1 ; i<colors.length()-1 ; ++i){
            if(colors.charAt(i)== 'A' && colors.charAt(i+1) == 'A' && colors.charAt(i-1) == 'A')
                aChances++;
            else if(colors.charAt(i) == 'B' && colors.charAt(i+1) == 'B' && colors.charAt(i-1) == 'B')
                bChances++;
        }
        return aChances > bChances;
    }
}