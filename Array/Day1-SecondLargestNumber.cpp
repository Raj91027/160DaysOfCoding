/*
Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.

Note: The second largest element should not be equal to the largest element.

Examples:
Input: arr[] = [12, 35, 1, 10, 34, 1]
Output: 34
Explanation: The largest element of the array is 35 and the second largest element is 34.
*/


//Approach-1
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        int n = arr.size();
        
        sort(arr.begin(), arr.end());

        for(int i=n; i>0; i++){
            if(arr[i]!=arr[i-1])
                return arr[i-1];
        }
        return -1;
        
    }
};




//Approach-2
class Solution {

int getSecondLargest(vector<int> &arr) {
        int n = arr.size();
        
        int largest = -1;
        
        for(int i=0; i<n ; i++){
            if(arr[i]>largest){
                largest = arr[i];
            }
        }
        //cout<<largest<<endl;
        
        int secondLargest=-1;
        
        for(int i=0; i<n; i++){
            if(arr[i]>secondLargest && arr[i]<largest){
                secondLargest = arr[i];
                //cout<<secondLargest;
            }
        }
        return secondLargest;
        
    }
}


//Approach-3
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        int n = arr.size();
        
        int largest = -1;
        int secLargest = -1;
        
        if(n<2)
            return -1;
            
        for(int i=0; i<n; i++){
            if(arr[i] > largest){
                secLargest = largest;
                largest = arr[i];
            }
            else if(secLargest<arr[i] && arr[i]!=largest){
                secLargest = arr[i];
            }
        }
        return secLargest;
        
    }
};