import java.util.*;

public class train {
    public static int calculateTotalWaitingTime(int[][] trains, int platforms) {
        Arrays.sort(trains, Comparator.comparingInt(a -> a[0]));
        PriorityQueue<Integer> platformQueue = new PriorityQueue<>();
        int totalWaitingTime = 0;
        for (int[] train : trains) {
            int arrivalTime = train[0];
            int departureTime = train[1];
            while (!platformQueue.isEmpty() && platformQueue.peek() <= arrivalTime) {
                platformQueue.poll();
            }

            if (platformQueue.size() < platforms) {
                platformQueue.offer(departureTime);
            } else {
                int nextFreeTime = platformQueue.poll();
                totalWaitingTime += nextFreeTime - arrivalTime;
                platformQueue.offer(Math.max(departureTime, nextFreeTime));
            }
        }

        return totalWaitingTime;
    }
    public static void main(String[] args) {
        int[][] trains = {
                {1, 5},
                {2, 6},
                {4, 7}  
        };
        int platforms = 1;
        int totalWaitingTime = calculateTotalWaitingTime(trains, platforms);
        System.out.println("Total waiting time: " + totalWaitingTime);
    }
}
