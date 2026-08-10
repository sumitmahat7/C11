
   class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        return solve(nums, nums.length);
    }

    private List<List<Integer>> solve(int[] nums, int n) {
        if (n == 0) {
            List<List<Integer>> base = new ArrayList<>();
            base.add(new ArrayList<>());
            return base;
        }

        List<List<Integer>> previous = solve(nums, n - 1);
        List<List<Integer>> res = new ArrayList<>();

        for (List<Integer> subset : previous) {
            res.add(new ArrayList<>(subset));
        }

        for (List<Integer> subset : previous) {
            List<Integer> newSubset = new ArrayList<>(subset);
            newSubset.add(nums[n - 1]);
            res.add(newSubset);
        }

        return res;
    }
}