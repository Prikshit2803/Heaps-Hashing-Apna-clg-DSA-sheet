// My soln : TLE problem
class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        priority_queue<pair<int,int>> dq;
        vector<pair<int,int>> ap;
        vector<int> ans;
        
        
        for(int i=0;i<n;i++){
            dq.push({abs(arr[i]-x),arr[i]});
            
            //if(dq.size()>k && abs(arr[i]-x)<dq.top().first )
            //dq.pop();
        }
        
        while(!dq.empty()){
            if(dq.top().first!=0)
            ap.push_back({dq.top().first,dq.top().second});
            dq.pop();
        }
        
        reverse(ap.begin(),ap.end());
        
        for(int i=1;i<n;i++){ // this is done because  if difference with x is equal smaller number is first due to reversing and now we swap it to make it come later as soln prefers larger no. first
          
            if(ap[i].first==ap[i-1].first)
            swap(ap[i],ap[i-1]);
        }
        
        for(int i=0;i<k;i++){
        
             ans.push_back(ap[i].second);
        }
       
        
        return ans;
    }
};


/// Improved soln
class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        priority_queue<pair<int,int>> dq;
        vector<pair<int,int>> ap;
        vector<int> ans;
        
        
        for(int i=0;i<n;i++){
            
            
            int diff=abs(arr[i]-x);
            if(diff==0) continue;
            
            dq.push({abs(arr[i]-x),-arr[i]}); //-ve taken because if diff is same larger element is first but we reverse at so larger element will come later hencee we make element -ve so that everything is sorted after reversing
            
        
            
            
            if(dq.size()>k )
            dq.pop();
        }
        
      
        
        while(!dq.empty()){
            //if(dq.top().first!=0)
            ans.push_back(-dq.top().second);
            dq.pop();
        }
        reverse(ans.begin(),ans.end());
        
       
       
        
        return ans;
    }
};


// Different approach without queueint 
int r = lower_bound(arr.begin(),arr.end(),x)-arr.begin(); // lower_found gives position of x or where it shld have been .. valid only for sorted array
l = r-1;
if(arr[r] == x) r++;
vector <int> ans;
while(k && l >= 0 && r < n){
    if(x-arr[l] < arr[r]-x)
        ans.push_back(arr[l--]);
    else ans.push_back(arr[r++]);
    k--;
}
while(k && l >= 0){
    ans.push_back(arr[l--]);
    k--;
}
while(k-- && r < n) ans.push_back(arr[r++]);
return ans;
