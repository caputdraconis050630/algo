package leet;

class Solution {
    public int maxSubArray(int[] nums) {
        int maxSum = nums[0];
		int currSum = nums[0];
		int n = nums.length;
		for (int i=1; i<n; i++) {
			currSum = Math.max(currSum + nums[i], nums[i]);
			maxSum = Math.max(maxSum, currSum);
		}
		return maxSum;
    }
}