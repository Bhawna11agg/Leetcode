class Solution {
public:
    int rob1(vector<int>& nums,int i,int* arr){
        if(i>=nums.size()){
            return 0;
        }
        if(arr[i]!=-1){
            return arr[i];
        }
        int x=rob1(nums,i+1,arr);
        int y=rob1(nums,i+2,arr)+nums[i];
        arr[i]=max(x,y);
        return max(x,y);
    }
    int rob(vector<int>& nums) {
        int* arr=new int[nums.size()];
        for(int i=0;i<nums.size();i++){
            arr[i]=-1;
        }
        return rob1(nums,0,arr);
    }
};
