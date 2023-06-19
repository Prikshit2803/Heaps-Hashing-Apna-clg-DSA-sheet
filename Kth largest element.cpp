// Two approaches mixed : Both TLE

class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        priority_queue<int> pq;
        vector<int> ans,ap;
        
        for(int i=0;i<n;i++){
           //pq.clear();
           ap.clear();
            if(i<k-1)
            ans.push_back(-1);
            
            else{
                for(int j=0;j<=i;j++)  ap.push_back(arr[j]);
                //pq.push(arr[j]);
                
                // while(!pq.empty()){
                // ap.push_back(pq.top());
                // pq.pop();
                // }
                
                sort(ap.begin(),ap.end());
                
                ans.push_back(ap[i-k+1]);
                
              //  ans.push_back(ap[k-1]);
            }
        }
        
        return ans;
    }
};

// Optimised soln : Also TLE
class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        priority_queue<int,vector<int>,greater<int>> pq; //min heap i.e. min element at pq top
        vector<int> ans;
        
        for(int i=0;i<n;i++){
           pq.push(arr[i]);
           
           if(pq.size()<k)
           ans.push_back(-1);
           
           else if(pq.size() ==k)
           ans.push_back(pq.top()); // as if 4th largest element then pq of size 4 the top element is minm and 4th largest
            
           else if(pq.size() >k){
               pq.pop(); // this keeps pq of size k and element next is always kth largest and pq size never exceeds k+1 as popping keeps happen hence after each pop we get kth largest element
               ans.push_back(pq.top());
           }
           
            
        }
        
        return ans;
    }
};

//Working soln
  priority_queue<int, vector<int>, greater<int>> pq;//min heap
        vector<int> ans(n,0);
       
       for(int i=0;i<k;i++){
           pq.push(arr[i]);
           ans[i]=-1;
       }
       
       ans[k-1]=pq.top();
       
       for(int i=k;i<n;i++){
           if(pq.top()<arr[i])      // it means after k elements if larger element encountered then kth largest element must shift
       {                            // if smaller than pq.top() encountered in arr[i] then kth largest remains intact elsepq.top() becomes (k+1) largest hence we pop
             pq.pop();
           pq.push(arr[i]);
           
       }
           ans[i]=pq.top();
       }
       return ans;
    }
