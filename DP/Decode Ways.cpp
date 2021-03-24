class Solution {
public:
    int decode(string s,int* arr){
        if(s.length()==0){
            return 1;
        }
        if(arr[s.length()]!=-1){
            return arr[s.length()];
        }
        if(s[0]!='0'){
            int m=0,p=0;
            p=decode(s.substr(1),arr);
            if(s.length()>=2 && (((s[0]-48)*10)+s[1]-48)<=26){
                m=decode(s.substr(2),arr);
            }
            arr[s.length()]=p+m;
               return p+m;    
        }
        arr[s.length()]=0;
        return 0;
    }
    int numDecodings(string s) {
        int* arr=new int[s.length()+1];
        for(int i=0;i<=s.length();i++)
            arr[i]=-1;
       return decode(s,arr);
    }
};
