//Soln in my language : from Love babbar

// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
      int largest = i;
      int left= 2*i+1;
      int right=2*i +2;
      
      if(left<n && arr[largest]<arr[left]){
          largest=left;
      }
      
      if(right<n && arr[largest]<arr[right]){
          largest=right;
      }
      
      if(largest!=i) {//i.e. a larger child element to that of parent node is found
      swap(arr[largest],arr[i]);
      heapify(arr,n,largest); // we place the (displaced and smaller) parent node at it's correct position now
          
      }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)   // this function builds a heap
    { 
      for(int i=n/2;i>=0;i--){ // n/2 as all nodes from n/2+1 index to nth index are leaf nodes and already a heap 
      
          heapify(arr,n,i); // i represents the node we shall try to place in it's position in the heap
      }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        buildHeap(arr,n);
        
        for(int i=n-1;i>=0;i--){
            swap(arr[0],arr[i]); // arr[0] of heap has largest element
            
            heapify(arr,i,0); // we convert the new array to a heap with less size as last element is sorted
        }
        
    }
};


// similar soln from someone else
public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
        // Your Code Here 0 BASED INDEXING
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;
        
        if(left<n && arr[largest]<arr[left])
        {
          largest=left;
        }
        
        if(right<n && arr[largest]<arr[right])
        {
          largest=right;
        }
        
        if(largest!=i)
        {
          swap(arr[largest], arr[i]);
          heapify(arr, n, largest);
        }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
        // Your Code Here
        for(int i=n/2;i>=0;i--)
        {
            heapify(arr, n, i);
        }
    }
    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        //code here
        buildHeap(arr, n);
        
        for(int i=n-1;i>=0;i--)
        {
            // step-1: swap last and root node
            swap(arr[0], arr[i]);
            
            // step-2: sahi positionpe lao using heapify
            heapify(arr, i, 0);
        }
    }


//Priority queue based soln
    void heapSort(int arr[], int n){
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i=0; i<n; i++){
        pq.push(arr[i]);
       }
        int i = 0;
        while(!pq.empty()){
            arr[i] = pq.top();
            pq.pop();
            i++;
        }
