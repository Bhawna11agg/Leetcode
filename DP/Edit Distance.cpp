class Solution {
public:
    int mindistance(string word1,string word2,int** arr,int i,int j){
        if(arr[i][j]!=-1){
            return arr[i][j];
        }
        if(word1.length()==0){
            arr[i][j]=word2.length();
            return word2.length();
        }
        if(word2.length()==0){
             arr[i][j]=word1.length();
             return arr[i][j];
        }
        if(word1[0]==word2[0]){
            arr[i][j]= mindistance(word1.substr(1),word2.substr(1),arr,i+1,j+1);
            return arr[i][j];
        }
        int a= mindistance(word1,word2.substr(1),arr,i,j+1)+1;
        int b= mindistance(word1.substr(1),word2.substr(1),arr,i+1,j+1)+1;
        int c= mindistance(word1.substr(1),word2,arr,i+1,j)+1;
        arr[i][j]=min(a,min(b,c));
        return min(a,min(b,c));
    }
    int minDistance(string word1, string word2) {
        int** arr=new int*[word1.length()+1];
        for(int i=0;i<=word1.length();i++){
            arr[i]=new int[word2.length()+1];
            for(int j=0;j<=word2.length();j++){
                arr[i][j]=-1;
            }
        }
        return mindistance(word1,word2,arr,0,0);
    }
};
