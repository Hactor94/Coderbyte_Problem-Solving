#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target);

int main() {
	vector<int> nums = {2,7,11,15};
	int target = 9;

	vector<int> indices = twoSum(nums, target);
	for (auto it : indices) {
		cout << it << " ";
	}
}
vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> indices;
	unordered_map<int, int> map;
	for (int i = 0; i < nums.size(); i++) {
		auto it = map.find(nums.at(i));
		if (map.find(target - nums[i]) != map.end() && map[target - nums[i]] != i) {
			indices.push_back(map[target - nums[i]]);
			indices.push_back(i);
			break;
		}
		map[nums[i]] = i;
	}
	return indices;
}