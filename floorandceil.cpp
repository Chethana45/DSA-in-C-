class Solution {
public:
    vector<int> getFloorAndCeil(vector<int>& arr, int x) {

        int low = 0;
        int high = arr.size() - 1;

        int floor = -1;
        int ceil = -1;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(arr[mid] == x) {
                return {x, x};
            }
            else if(arr[mid] < x) {
                floor = arr[mid];
                low = mid + 1;
            }
            else {
                ceil = arr[mid];
                high = mid - 1;
            }
        }

        return {floor, ceil};
    }
};
