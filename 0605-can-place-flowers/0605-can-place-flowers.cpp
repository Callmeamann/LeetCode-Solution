class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {

        // int sz = flowerbed.size();
        // int count = 0;
        if(f.size() == 1 and n == 1 ){
            if(f[0] == 0)
                return true;
            else 
                return false;
        }
            
        // for(int i=0 ; i<sz ; i++){
        //     if(flowerbed[i] == 0){
        //         if(i==0 and flowerbed[i+1] == 0){  
        //             count++;
        //             flowerbed[i] = 1;
        //         }
        //         else if(i==sz-1 and flowerbed[i-1] == 0){
        //             count++;
        //             flowerbed[i] = 1;
        //         }

        //         else if (flowerbed[i-1] == 0 and flowerbed[i+1] == 0){
        //             count++;
        //             flowerbed[i] = 1;
        //         }
        //     }
            
        // }
        // return count >= n;

     for(int i=0;i<f.size();i++){
         if(f[i]==0){
             if(i==0)
             { if(i+1<f.size() and f[i+1]==0){f[i]=1; n--;}
             }
             else if(i==f.size()-1 ){
                 if(i-1>=0 and f[i-1]==0){f[i]=1; n--;}
             }
             else if(f[i-1]==0 and f[i+1]==0 ){f[i]=1; n--;}
         }  
     }
     return n<=0;
    }
};