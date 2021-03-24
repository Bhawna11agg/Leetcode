class Solution {
public:
    int Profit(vector<int>& prices,int k,int state,int i,int*** arr){
            if(arr[i][state][k]!=-2){
            return arr[i][state][k];
        }
          if(k==0){
            arr[i][state][k]=0;
            return 0;
        }
         if(i==prices.size()){
            return 0;
         }
        if(state==0){
            
            int pr=Profit(prices,k,1,i+1,arr)-prices[i];
            int pr1=Profit(prices,k,0,i+1,arr); 
          
            arr[i][0][k]=max(pr,pr1);
            return max(pr,pr1);
        }
        else{
            int pr=Profit(prices,k-1,0,i+1,arr)+prices[i];
            int pr1=Profit(prices,k,1,i+1,arr);
           
            arr[i][1][k]=max(pr,pr1);
            return max(pr,pr1);
        }
        return 0;
    }
    int maxProfit(vector<int>& prices) {
        int*** arr=new int**[prices.size()+1];
        for(int i=0;i<=prices.size();i++){
            arr[i]=new int*[2];
            for(int j=0;j<2;j++){
                arr[i][j]=new int[3];
                for(int m=0;m<3;m++){
                    arr[i][j][m]=-2;
                }
            }
        }
        return Profit(prices,2,0,0,arr);
    }
};
