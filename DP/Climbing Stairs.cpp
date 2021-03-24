class Solution {
public:
    int climb(int n,int* dp){
        
        if(n==0){
            dp[0]=1;
            return 1;
        }
        int a=0,b=0;
        if(dp[n]!=-1){
            return dp[n];
        }
        if(n-1>=0)
        a= climb(n-1,dp);
        if(n-2>=0)
        b= climb(n-2,dp);
        dp[n]=a+b;
        return a+b;
    }
    
    int climb_dp(int n,int* dp){
        for(int i=0;i<=n;i++){
        if(i==0){
            dp[0]=1;
            continue;
        }
        int a=0,b=0;
            
        if(i-1>=0)
        a= dp[i-1];
        if(i-2>=0)
        b= dp[i-2];
        dp[i]=a+b;
        }
        
        return dp[n];
    }
    
    int climbStairs(int n) {
        
        int* dp=new int[n+1];
        for(int i=0;i<n+1;i++){
            dp[i]=-1;
        }
        return climb_dp(n,dp);
    }
};
