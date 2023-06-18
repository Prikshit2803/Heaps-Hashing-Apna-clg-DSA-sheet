class Solution{
  public:
    int minDiff(int arr[], int N, int K)
    {
        int ans=INT_MAX;
       sort(arr,arr+N);
       for(int i=0;i<N-K+1;i++){
           ans=min(ans,(arr[K-1+i]-arr[i]));
       }
       return ans;
    }
};
