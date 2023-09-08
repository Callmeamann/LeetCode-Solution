class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> result = new ArrayList<>();

        for(int i=0 ; i<numRows ; i++){
            List<Integer> v = new ArrayList<>();
            for(int j=0 ; j<=i ; j++){
                if(j==0 || j==i){
                    v.add(1);
                }
                else{
                    v.add(result.get(i-1).get(j-1)+ result.get(i-1).get(j));
                }
            }
            result.add(v);
        }

        return  result;
    }
}