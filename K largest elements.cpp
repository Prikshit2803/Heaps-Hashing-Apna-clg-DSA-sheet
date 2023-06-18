class Solution{
public:	

	vector<int> kLargest(int arr[], int n, int k) {
	    priority_queue<int> dq;
	  
	    vector<int> ans;
	    
	    if(k==0||n==0)
	    return ans;
	    
	    
	    for(int i=0;i<n;i++){
	        dq.push(arr[i]);
	        
	       // if(dq.size()>k)
	       // dq.pop();
	    }
	    
	   for(int i=0;i<k;i++){
	        ans.push_back(dq.top());
	        dq.pop();
	    }
	    return ans;
	}

};
