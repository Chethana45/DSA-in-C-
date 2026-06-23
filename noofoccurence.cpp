class Solution {
public:

    int firstOcc(vector<int>& arr, int target){
        int low = 0, high = arr.size()-1;
        int first = -1;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(arr[mid] == target){
                first = mid;
                high = mid - 1;
            }
            else if(arr[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return first;
    }

    int lastOcc(vector<int>& arr, int target){
        int low = 0, high = arr.size()-1;
        int last = -1;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(arr[mid] == target){
                last = mid;
                low = mid + 1;
            }
            else if(arr[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return last;
    }

    int countOccurrences(vector<int>& arr, int target) {

        int first = firstOcc(arr, target);

        if(first == -1)
            return 0;

        int last = lastOcc(arr, target);

        return last - first + 1;
    }
};
