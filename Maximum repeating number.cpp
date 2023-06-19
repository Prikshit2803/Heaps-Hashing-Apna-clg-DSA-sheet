//My soln
class Solution{
public:	
	// Returns maximum repeating element in arr[0..n-1].
	// The array elements are in range from 0 to k-1
	int maxRepeating(int *arr, int n, int k) {
	    map<int,int> mp;
	    
	    int ans;
	    int maxcnt=0;
	    
	   // for(auto i : arr)
	   // mp[arr]++;
	   
	   for(int i=0;i<n;i++){
	       mp[arr[i]]++;
	   }
	    
	    for(auto it : mp){
	        if(it.second>maxcnt){
	            maxcnt=it.second;
	            ans=it.first;
	        }
	    }
	    
	    return ans;
	}

};


//Another approach
