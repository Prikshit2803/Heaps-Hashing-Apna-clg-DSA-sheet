// My soln : TLE

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        vector<int> ans;
        map<int,int> mp;
        int cnt,s;
        
        
        for(int i=k-1;i<n;i++){
            mp.clear();
             cnt=0;
             s=k;
            for(int s=k;s>0;s--){
                if(mp.find(A[i-s+1])!=mp.end()){
                    continue;
                    
                }
                
                
                else{
                   cnt++;
                   mp[A[i-s+1]]=1;
                   //s--;
                   
                }
                
                
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};

// Working soln TC and SC : O(N)
class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        vector<int> ans;
       map<int,int> mp; 
        
        
        for(int i=0;i<k;i++){
        // if(mp.find(A[i])!=mp.end())
        //     mp[A[i]]++;
        //     else
        //   mp[A[i]]=1;  this is not necessary
        
        mp[A[i]]++;
        
                }
        ans.push_back(mp.size());
        
        int l=0;
         for(int r=k;r<n;r++){
             
             mp[A[l]]--;
             
             if(mp[A[l]]==0) 
             mp.erase(A[l]);
             
             l++;
             
        //   //if(mp.find(A[r])!=mp.end())
        //     mp[A[r]]++;
        //     //else
        //  // mp[A[r]]=1;
        
        mp[A[i]]++;
             
             ans.push_back(mp.size());
             
         } 
    
    
          
        return ans;
    
 
    
    }
};
