


/*
Count number of occurrences (or frequency) in a sorted array

Given a sorted array arr[] and an integer target, the task is to find the number of
 occurrences of target in given array.

Examples:

Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 2
Output: 4
Explanation: 2 occurs 4 times in the given array.

Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 4
Output: 0
Explanation: 4 is not present in the given array.
*/







int firstOccurrences(vector<int>& arr, int n, int x){
	int s = 0;
	int e= n-1;
	int ans = -1;
	int mid = s + (e-s)/2;
	while(s<=e){
		if(arr[mid]==x){
			ans = mid;
			e = mid-1;
		}
		else if(arr[mid]<x){
			s = mid+1;
		}
		else{
			e = mid-1;
		}
		mid = s+(e-s)/2;
	}
	return ans;
}

int lastOccurrences(vector<int>& arr, int n, int x){
	int s = 0;
	int e= n-1;
	int ans = -1;
	int mid = s + (e-s)/2;
	while(s<=e){
		if(arr[mid]==x){
			ans = mid;
			s = mid+1;
		}
		else if(arr[mid]<x){
			s = mid+1;
		}
		else{
			e = mid-1;
		}
		mid = s+(e-s)/2;
	}
	return ans;
}
int count(vector<int>& arr, int n, int x) {
	int first = firstOccurrences(arr,n,x);
	int last = lastOccurrences(arr,n,x);

	if(first!=-1 && last!=-1){
		return last-first+1;
	}
	else
		return 0;
}
