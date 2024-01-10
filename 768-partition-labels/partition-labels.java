class Solution {
    public List<Integer> partitionLabels(String s) {
        List<Integer> ans = new ArrayList<>();
        int[] arr = new int[26];
        for(int i=0;i<s.length();i++){
            arr[s.charAt(i) - 'a'] = i;
        }
        int max = 0;
        int j = -1;
        for(int i=0;i<s.length();i++) {
            if((max = Math.max(arr[s.charAt(i)-'a'],max)) == i) {
                ans.add(i-j);
                j=i;
            }
        }
        return ans;
    }
}