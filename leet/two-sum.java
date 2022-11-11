package leet;

import java.util.HashMap;
import java.util.Map;

class Solution {
    public int[] twoSum(int[] nums, int target) {
		int n = nums.length;
		int[] answer = new int[2];
		Map<Integer, Integer> map = new HashMap<>();
        for (int i =0; i<n; i++) {
			if (map.containsKey(target - nums[i])) {
				answer[0] = map.get(target - nums[i]);
				answer[1] = i;
				break;
			}
			map.put(nums[i], i);
		}
		return answer;
    }
}
