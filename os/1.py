def findWaitingTime(processes, n, bt, wt):
    wt[0] = 0
    for i in range(1, n):
        wt[i] = bt[i - 1] + wt[i - 1]
def findTurnAroundTime(processes, n, bt, wt, tat):
    for i in range(n):
        tat[i] = bt[i] + wt[i]
def findAverageTime(processes, n, bt):
    wt = [0] * n
    tat = [0] * n
    total_wt = 0
    total_tat = 0
    findWaitingTime(processes, n, bt, wt)
    findTurnAroundTime(processes, n, bt, wt, tat)
    print("Processes    Burst Time     Waiting Time    Turn-Around Time")
    for i in range(n):
        total_wt = total_wt + wt[i]
        total_tat = total_tat + tat[i]
        print("   ", i + 1, "\t\t", bt[i], "\t\t", wt[i], "\t\t", tat[i])
    print(f"\nAverage waiting time = {total_wt / n:.2f}")
    print(f"Average turnaround time = {total_tat / n:.2f}")
if __name__ == "__main__":
    processes = [1, 2, 3, 4]
    n = len(processes)
    burst_time = [5, 9, 6, 3]
    findAverageTime(processes, n, burst_time)
