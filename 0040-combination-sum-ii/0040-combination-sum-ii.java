class Solution {
    private void func(int i, int target, int[] candidates, List<Integer> temp, Set<List<Integer>> ans) {
        if (target == 0) {
            ans.add(new ArrayList<>(temp));
            return;
        }
        if (i == candidates.length || target < 0)   return;
        temp.add(candidates[i]);
        func(i + 1, target - candidates[i], candidates, temp, ans);
        temp.remove(temp.size() - 1);
        while (i + 1 < candidates.length && candidates[i] == candidates[i + 1]) {
            i++;
        }
        func(i + 1, target, candidates, temp, ans);
    }

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        Set<List<Integer>> ans = new HashSet<>();
        func(0, target, candidates, new ArrayList<>(), ans);
        return new ArrayList<>(ans);
    }
}