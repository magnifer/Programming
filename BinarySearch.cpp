#include <bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int> &nums, int left, int right, int target)
{
	if (right >= left)
	{
		int mid = left + (right - left) / 2;

		if (nums[mid] == target)
			return mid;
		else if (nums[mid] > target)
			return BinarySearch(nums, left, mid - 1, target);
		else if (nums[mid] < target)
			return BinarySearch(nums, mid + 1, right, target);
	}
	return -1;
}

int main()
{
	vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
	int target = 5;
	int index = BinarySearch(nums, 0, nums.size() - 1, target);

	(index == -1) ? cout << "Element not Present!"
				  : cout << "Element found at Index " << index;

	return 0;
}