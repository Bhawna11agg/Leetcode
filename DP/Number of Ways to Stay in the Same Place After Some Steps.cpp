class Solution {
public:
    
   int WaysMemo(int steps,int arrLen,int index,int** arr){
       int mod= pow(10,9)+7;
        if(steps==0){
            if(index==0){
                arr[steps][index]=1;
                return 1;
            }
            arr[steps][index]=0;
            return 0;
        }
       int p=0,m=0,k=0;
       if(arr[steps][index]!=-1){
           return arr[steps][index];
       }
       if(steps<index){
            arr[steps][index]=0;
            return arr[steps][index];
       }
        if(index>0){
            p=WaysMemo(steps-1,arrLen,index-1,arr)% mod;
        }
        if(index+1<arrLen){
            m=WaysMemo(steps-1,arrLen,index+1,arr)% mod;
        }
        k=WaysMemo(steps-1,arrLen,index,arr)% mod;
        arr[steps][index]=((p+m)%mod+k)%mod;
        return arr[steps][index];
    }
    
    int numWays(int steps, int arrLen) {
        int** arr=new int*[steps+1];
        for(int i=0;i<steps+1;i++){
            arr[i]=new int[501];
            for(int j=0;j<501;j++){
                arr[i][j]=-1;
            }
        }
        // return 0;
        return WaysMemo(steps,arrLen,0,arr);
    }
    
    
};
