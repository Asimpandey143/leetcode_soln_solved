class Solution {
    public int countCommas(int n) {
        int total = 0;
        long thr = 1000;

        while(n>=thr){
            total += (n- thr +1);
            thr *= 1000;
            
        }

        return total;
        
    }
}