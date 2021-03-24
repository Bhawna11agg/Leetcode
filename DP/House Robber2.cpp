class Solution {
public:
    int index1=1;
    int robery(int*** arr,int size,vector<int>nums,int index,int state){
        if(size==index){
            return 0;
        }
        if(arr[index][state][index1]!=-1){
            if(size!=index+1)
            return arr[index][state][index1];
                
        }
        if(state==0){
            int a=-1,b=-1;
            if(index1==1 && index==size-1 && size>1){

            }
            else
            a=robery(arr,size,nums,index+1,state+1)+nums[index];    
            if(index==0)
            index1=0;
            b=robery(arr,size,nums,index+1,state);
            arr[index][state][index1]=max(a,b);
            return arr[index][state][index1];
        }
        else{
            int a=robery(arr,size,nums,index+1,state-1); 
            arr[index][state][index1]=a; 
            return a;
        } 
    }
    int rob(vector<int>& nums) {
        int*** arr=new int**[nums.size()];
        for(int i=0;i<nums.size();i++){
           arr[i]=new int*[2];
            for(int j=0;j<2;j++){
                arr[i][j]=new int[2];
                for(int k=0;k<2;k++){
                     arr[i][j][k]=-1;
                }
            }
        }
        return robery(arr,nums.size(),nums,0,0);
    }
};
