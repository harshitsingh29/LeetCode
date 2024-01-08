class Solution {

    public boolean isNStraightHand(int[] hand, int g) {
        if (hand.length % g != 0) {
            return false;
        }
        if(g == 1) {
            return true;
        }
        Arrays.sort(hand);
        HashMap<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < hand.length; i++) {
            mp.merge(hand[i], 1, Integer::sum);
        }
        for (int num : hand) {
            if (mp.get(num) > 0) {
                for (int i = 0; i < g; i++) {
                    if (mp.getOrDefault(num + i, 0) > 0) {
                        mp.put(num + i, mp.get(num + i) - 1);
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
}
