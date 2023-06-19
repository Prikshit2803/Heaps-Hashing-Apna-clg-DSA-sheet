// My soln
class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int> dq;
	  
	    vector<int> ans;
	    
	   // if(k==0||n==0)
	   // return 0;
	    
	    
	    for(int i=l;i<=r;i++){
	        dq.push(arr[i]);
	        
	       // if(dq.size()>k)
	       // dq.pop();
	    }
	    
	   //while(!dq.empty()){
	   //     ans.push_back(dq.top());
	   //     dq.pop();
	   // } // it gave TLE
	   
	   for(int i=0;i<=r-k+1;i++){
	       ans.push_back(dq.top());
	        dq.pop();
	   }
	    return ans[ans.size()-1];
	}
    
};

//Improved approach
//Intuition : if we want 3rd smallest element and then have 3 elements in priority queue such that only smaller elements are pushed 
//then queue top is our answer 

int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        priority_queue<int>pq;
        
        for(int i = l;i<= r;i++)
        {
            if(pq.size() < k)
            {
                pq.push(arr[i]);
            }
            else
            {
                if(pq.top() > arr[i])
                {
                    pq.pop();
                    pq.push(arr[i]);
                }
            }
        }
        
        return pq.top();
  
  
}

// Smart-asses coming up with solns
int kthSmallest(int arr[], int l, int r, int k) {
        
        sort(arr, arr+r+1);
        return arr[k-1];
        
    }
