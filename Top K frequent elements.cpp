class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // min heap

        // for(int i=0;i<nums.size();i++){
        //     if(mp.find(nums[i])==mp.end()){
        //         mp[nums[i]]=1;
        //     }

        //     else{
        //         mp[nums[i]]++;
        //     }
        // }

        for(auto i: nums) {
            mp[i]++;
        }

      
      for(auto it : mp){
        pq.push({it.second,it.first}); // the frequency added first so priority queue such that minimum frequency element at top of queue

        if(pq.size()>k){
            pq.pop(); // remove top min element
        }
      }
          
          while(!pq.empty()){
              ans.push_back(pq.top().second); // ans can be in any order and pq.top().second gives the actual element as pq.top().first is the frequency
              pq.pop();
          }
          
          return ans;

    }
};


// another approach and a similar approach
class Solution {
/************Approach-1********************************/
    // using bucket sort
    // time: O(n^2+nlogn), space: O(n^2)
    vector<int> topKFrequent_bucketSort(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int i: nums) {
            freq[i]++;
        }

        vector<vector<int>> bucket(nums.size()+1); // size+1, since size is 1-based and accessing freq in this will be 0-based

        for(auto i: freq) {
            bucket[i.second].push_back(i.first);
        }

        vector<int> topK;
        for(int i=bucket.size()-1; i>=0 && topK.size() < k; i--) {
            for(int ele : bucket[i]) {
                topK.push_back(ele);
                if(topK.size() == k)
                   break;
            }
        }
        return topK;
    }
    
/************Approach-2********************************/
    // using heap sort
    // time: O(nlogn)
    vector<int> topKFrequent_heapSort(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //min heap
        
        unordered_map<int, int> freq;

        for(auto i: nums) {
            freq[i]++;
        }

        for(auto i: freq) {
            pq.push({i.second, i.first});
            // if pq size > k, removing top min elemet by pop
            if(pq.size() > k)
               pq.pop();
        }

        vector<int> topK;
        while(pq.size()) {
            topK.push_back(pq.top().second);
            pq.pop();
        }
        return topK;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        return topKFrequent_heapSort(nums, k);
    }
};
