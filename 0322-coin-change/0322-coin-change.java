 class Solution { 
    public int coinChange(int[] coins, int amount) { 
        int max=amount+1; 
        int[] coin=new int[amount+1]; 
        Arrays.fill(coin,max); 
        coin[0]=0; 
        for(int i=1;i<=amount;i++){ 
            for(int coi:coins){ 
                if(coi<=i) 
                coin[i]=Math.min(coin[i],coin[i-coi]+1); 
            } 
        } 
        return coin[amount]>amount?-1: coin[amount]; 
    } 
}