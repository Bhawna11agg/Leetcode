class Solution {
public:
    int distinct(string s,string t,int index1,int index2,int** dp){
        if(index2==t.length()){
            dp[index1][index2]=1;
            return 1;
        }
        if(index1>=s.length()){
            dp[index1][index2]=0;
            return 0;
        }
        if( dp[index1][index2]!=-1){
            return dp[index1][index2];
        }
        int p=0,o=0;
        if(s[index1]==t[index2]){
            p=distinct(s,t,index1+1,index2+1,dp);
            o=distinct(s,t,index1+1,index2,dp);
        }
        else{
            p=distinct(s,t,index1+1,index2,dp);
        }
        dp[index1][index2]=p+o;
        return p+o;
    }
    
    int distinctDp(string s,string t,int index1,int index2,int** dp){
        for(int j=t.length();j>=0;j--){
            for(int i=s.length();i>=0;i--){
                 if(j==t.length()){
                     dp[i][j]=1;
                     continue;
                 }
                if(i==s.length()){
                    dp[i][j]=0;
                    continue;
                }
                long p=0,o=0;
                if(s[i]==t[j]){
                    p=dp[i+1][j+1];
                    o=dp[i+1][j];
                }
                else{
                    p=dp[i+1][j];
                }
                dp[i][j]=p+o;
            }
        }
        return dp[index1][index2];
    }
    
    int numDistinct(string s, string t) {
        int** dp=new int*[s.length()+1];
        for(int i=0;i<s.length()+1;i++){
            dp[i]=new int[t.length()+1];
            for(int j=0;j<t.length()+1;j++){
                dp[i][j]=-1;
            }
        }
        return distinctDp(s,t,0,0,dp);
    }
};
