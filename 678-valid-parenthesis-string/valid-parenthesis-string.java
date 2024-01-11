class Solution {
    public boolean checkValidString(String s) {
        int n = s.length();
        int maxopen = 0, minopen = 0;
        for(int i=0;i < n; i++) {
            if(s.charAt(i) == ')') {
                maxopen--;
                minopen = Math.max(0, minopen-1);
            }
            if(s.charAt(i) == '(') {
                maxopen++;
                minopen++;
            }
            if(s.charAt(i) == '*') {
                maxopen++;
                minopen = Math.max(0, minopen-1);
            }
            if(maxopen < 0) {
                return false;
            }
        }
        return minopen == 0;
    }
}