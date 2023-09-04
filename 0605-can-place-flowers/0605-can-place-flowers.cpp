class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        int sz = flowerbed.size();
        int count = 0;
        // if(sz == 1 and n == 1 ){
        //     if(flowerbed[0] == 0)
        //         return true;
        //     else 
        //         return false;
        // }
            
        for(int i=0 ; i<sz ; i++){
            if(flowerbed[i] == 0){
                if(i==0 ){ 
                    if(i==sz-1) // this condition is for flowerbed of size 1
                        count++;
                    if( i+1 < sz and flowerbed[i+1] == 0) {
                        count++;
                        flowerbed[i] = 1;
                    }    
                }
                else if(i==sz-1 ){
                    if(i-1 >= 0 and flowerbed[i-1] == 0){
                        count++;
                        flowerbed[i] = 1;
                    }   
                }
                else if (flowerbed[i-1] == 0 and flowerbed[i+1] == 0){
                    count++;
                    flowerbed[i] = 1;
                }
            }
            if(count >= n)
                return true;
            
        }
        return false;
    }
};