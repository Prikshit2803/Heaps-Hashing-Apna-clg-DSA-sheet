// My soln
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
       priority_queue<long long,vector<long long>,greater<long long>> pq;
       long long a=0,cnt=0;
       for(int i=0;i<n;i++)
       pq.push(arr[i]);
       
      while(!pq.empty()){
          a=0;
          a+=pq.top();
          pq.pop();
            if(!pq.empty()){
               a+=pq.top();
            pq.pop();
          pq.push(a);
          cnt+=a;  
            }
          
      }
       return cnt;
    }
};

// similar approach
 long long minCost(long long arr[], long long n) {
        // Your code here
        
        // create a min heal
       priority_queue<long long ,vector<long long>,greater<long long>> pq;
       
       for(int i=0;i<n;i++){
           pq.push(arr[i]);
       }
       
       long long cost =0;
       
       while(pq.size()>1){
           long long a=pq.top();
           pq.pop();
           long long b = pq.top();
           pq.pop();
           
           long long sum = a+b;
            cost+=sum;
            pq.push(sum);
       }
       return cost;
    }

// different array based approach
long long minCost(long long arr[], long long n) {
        sort(arr,arr+n);
        int k=arr[0]+arr[1];
        vector<int>ans;
        int sum=0;
        ans.push_back(k);
        int s=k;
        for(int i=2;i<n;i++){
            ans.push_back(s+arr[i]);
            s=s+arr[i];
        }
        for(int i=0;i<ans.size();i++){
            sum=sum+ans[i];
        }
        return sum;
    }
