class Solution {
    public int solution(int[] array) {
        int[] count = new int[1000];
        for(int i: array) {
            count[i]++;
        }
        int answer = 0;
        int max = -1;
        for(int i=0; i<count.length; i++) {
            if(count[i] > max) {
                max = count[i];
                answer = i;
            }
            else if(count[i] == max){
                answer = -1;
            }
        }
        
        return answer;
    }
}