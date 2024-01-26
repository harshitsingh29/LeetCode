class Solution {


    public void findSub(int i, int n, int[] nums, List<Integer> arr, List<List<Integer>> ans) {
        ans.add(new ArrayList<>(arr));
        for(int j = i; j < n; j++) {
            if(j != i && nums[j] == nums[j-1]) continue;
            arr.add(nums[j]);
            findSub(j+1, n, nums, arr, ans);
            arr.remove(arr.size()-1);
        }
    }

    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        int n = nums.length;
        List<Integer> arr = new ArrayList<>();
        Arrays.sort(nums);
        findSub(0, n, nums, arr, ans);
        return ans;
    }
}