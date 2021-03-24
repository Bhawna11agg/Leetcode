#include<string.h>
class Solution {
public:
    bool find(int** arr,string s,string p,int i,int j){
         if(arr[i][j]!=-1){
            return  arr[i][j];
        }
        if(s[0]=='\0'){
            if(p[0]=='\0'){
                arr[i][j]=1;
                return 1;
            }
            else{
                for(int l=0;l<p.length();l++){
                    if(p[l]=='?'||(p[l]>=97 && p[l]<=122)){
                        arr[i][j]=0;
                        return 0;
                    }
                }
                arr[i][j]=1;
                 return 1;;
            }
        }
        if(p[0]=='\0'){
             arr[i][j]= 0;
            return  arr[i][j];
        }
         if(s[0]==p[0] || p[0]=='?'){
              arr[i][j]= find(arr,s.substr(1),p.substr(1),i+1,j+1);
             return  arr[i][j];
         }
        bool b=0;
        int l1;
        if(p[0]=='*'){
             for(l1=1;l1<p.length();l1++){
                 if(p[l1]!='*'){
                     break;
                 }
             }
             if(l1==p.length()){
                 arr[i][j]=1;
                 return 1;
             }
             for(int l=0;l<=s.length();l++){
                 if(p[l1]==s[l]||p[l1]=='?'){
                     b=find(arr,s.substr(l),p.substr(l1),i+l,j+l1);
                     if(b){
                         arr[i][j]=1;
                         return 1;
                     }
                 }
             }
         }
         arr[i][j]=0;
         return 0;
    }
    bool isMatch(string s, string p) {
       int** arr=new int*[s.length()+1];
        for(int i=0;i<=s.length();i++){
            arr[i]=new int[p.length()+1];
            for(int j=0;j<=p.length();j++){
                arr[i][j]=-1;
            }
        }
        int count=0;
        for(int i=0;i<p.length();i++){
            if(p[i]!='*'){
                count++;
            }
        }
        if(count>s.length()){
            return 0;
        }
        return find(arr,s,p,0,0);
    }
 };
