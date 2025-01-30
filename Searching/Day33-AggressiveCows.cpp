/*
Aggressive Cows

Given an array stalls[] which denotes the position of a stall and an integer k which denotes the number of aggressive cows. 
The task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.

Examples: 

Input: stalls[] = [1, 2, 4, 8, 9], k = 3
Output: 3
Explanation: We can place cow 1 at position 1, cow 2 at position 4 and cow 3 at position 9. 
So, the maximum possible minimum distance between two cows is 3.
*/

/*
[Expected Approach] Using Binary Search
The minimum distance between the cows has a monotonic property.

If we can place all the cows with a minimum distance d, then we can also place them 
with any smaller distance than d. The reason is by reducing the minimum gap, 
we can place more number of cows as lower gaps allow us to place cows even more closer.
If we can't place all the cows with a minimum distance d, then we can't place them 
with any larger distance than d. The reason is if the gap is already too large to place the cows, 
then larger gap will also not work.
Therefore, we can use binary search to find the maximum possible minimum distance, and to check the for any distance, 
we place the first cow in the first stall and the next ones only if the gap from the last placed cow is at least that distance. 
If all cows can be placed for a certain distance, then it is a feasible distance.
*/

static bool isPossible(vector<int> &stalls, int k, int mid){
        
        
        int cowCount=1;
        int lastPos = stalls[0];
        
        for(int i=1; i<stalls.size(); i++){
            if(stalls[i] - lastPos >= mid){
                
                cowCount++;
                if(cowCount==k)
                    return true;
                lastPos = stalls[i];
            }
        }
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) {

        sort(stalls.begin(), stalls.end());
        
        int mini = 0;
        int maxi = stalls[stalls.size()-1];
        
        int mid = mini +(maxi-mini)/2;
        int ans = -1;
        
        while(mini <= maxi){
            
            if(isPossible(stalls, k, mid)){
                ans = mid;
                mini = mid+1;
            }
            else{
                maxi = mid-1;
            }
            
            mid = mini +(maxi-mini)/2;
        }
        
        return ans;
    }

    int main() {
    vector<int> stalls = {1, 2, 4, 8, 9}; 
    int k = 3;
    int ans = aggressiveCows(stalls, k);
    cout << ans;
    return 0;
}