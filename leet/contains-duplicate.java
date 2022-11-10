package leet;

import java.util.HashSet;
import java.util.Set;

class Solution {
    public boolean containsDuplicate(int[] nums) {
		if (nums == null || nums.length == 0)
			return false;

		Set<Integer> passed = new HashSet<Integer>();
		for  (int i : nums) {
			if(!passed.add(i)) return true;
		}
		return false;
    }
}
