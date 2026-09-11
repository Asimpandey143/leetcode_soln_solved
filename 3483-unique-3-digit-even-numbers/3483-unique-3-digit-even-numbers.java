class Solution {
    public int totalNumbers(int[] digits) {
        // Count frequencies of each digit in the input array
        int[] count = new int[10];
        for (int d : digits) {
            count[d]++;
        }

        int validCount = 0;

        // Iterate through all 3-digit even numbers
        for (int i = 100; i < 1000; i += 2) {
            int d1 = i / 100;       // Hundreds digit
            int d2 = (i / 10) % 10; // Tens digit
            int d3 = i % 10;        // Units digit

            // Count frequency of digits needed for current number 'i'
            int[] currentCount = new int[10];
            currentCount[d1]++;
            currentCount[d2]++;
            currentCount[d3]++;

            // Check if input array has enough of each digit
            boolean possible = true;
            for (int d = 0; d < 10; d++) {
                if (currentCount[d] > count[d]) {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                validCount++;
            }
        }

        return validCount;
    }
}