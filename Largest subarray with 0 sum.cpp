// TC and SC : O(N)
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
         // we use hasing and take sum from 0 to i if sum repeats hence zero subarray exists 
         //and at that value i we calculate i it is the longest subarray or not
         
         map<int,int> mp;
         int maxcnt=0,sum=0;
         
         mp[0]=-1; // it iscrucial 4  -1 1 -1 1 as correct output shld be 4 and without this step we get 2
         
         for(int i=0;i<n;i++){
             sum+=A[i];
             
             if(mp.find(sum)!=mp.end()){
                 maxcnt=max(maxcnt,i-mp[sum]);
                 
             }
             
             else
             mp[sum]=i;
         }
         
         
        return maxcnt;
    
       
        
        
        
    }
};

//Brute force TC: O(N^2)  AND SC : o(1)
int maxLen(vector<int>&A, int n)
    {   
        //brute force O(n^2) O(1)
        
        int longest_cnt = 0;
        for(int i=0; i<n-1; i++){
            int sum = A[i];
            for(int j=i+1; j<n; j++){
                sum+=A[j];
                if(sum == 0)
                    longest_cnt = max(longest_cnt,j-i+1);
            }
        }
        return longest_cnt;
        
        }
