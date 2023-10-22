#include <iostream>
#include <vector>

using namespace std;

int findFloor(const vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int floor = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return nums[mid];  // Exact match, so floor is the target itself.
        }
        else if (nums[mid] < target) {
            floor = nums[mid];
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return floor;
}

int findCeil(const vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int ceil = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return nums[mid];  // Exact match, so ceil is the target itself.
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            ceil = nums[mid];
            right = mid - 1;
        }
    }

    return ceil;
}

int findPeak(const vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[mid + 1]) {
            return nums[mid];
        }
        else if (nums[mid] < nums[mid + 1]) {
            left = mid + 1;
        }
    }

    return nums[left];  // The last element if there is no clear peak.
}

int findMinimum(const vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[right]) {
            left = mid + 1;
        }
        else if (nums[mid] < nums[right]) {
            right = mid;
        }
    }

    return nums[left];
}

int main() {
    vector<int> rotatedArray = {4, 5, 6, 7, 0, 1, 2};
    int target = 3;

    int floor = findFloor(rotatedArray, target);
    int ceil = findCeil(rotatedArray, target);
    int peak = findPeak(rotatedArray);
    int minimum = findMinimum(rotatedArray);

    cout << "Floor: " << floor << endl;
    cout << "Ceil: " << ceil << endl;
    cout << "Peak: " << peak << endl;
    cout << "Minimum: " << minimum << endl;

    return 0;
}
