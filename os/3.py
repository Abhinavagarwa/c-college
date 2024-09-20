# Function to find the waiting time for all processes
def findWaitingTime(processes, n, bt, wt, pr):
    # Sorting processes by priority
    for i in range(n):
        for j in range(i + 1, n):
            if pr[i] > pr[j]:
                # Swapping burst time
                bt[i], bt[j] = bt[j], bt[i]
                # Swapping process numbers
                processes[i], processes[j] = processes[j], processes[i]
                # Swapping priorities
                pr[i], pr[j] = pr[j], pr[i]

    # Waiting time for first process is 0
    wt[0] = 0

    # Calculating waiting time for each process
    for i in range(1, n):
        wt[i] = bt[i - 1] + wt[i - 1]

# Function to calculate turn around time
def findTurnAroundTime(processes, n, bt, wt, tat):
    # Calculating turn around time by adding
    # burst time and waiting time
    for i in range(n):
        tat[i] = bt[i] + wt[i]

# Function to calculate average time
def findAverageTime(processes, n, bt, pr):
    wt = [0] * n
    tat = [0] * n
    total_wt = 0
    total_tat = 0

    # Find waiting time of all processes
    findWaitingTime(processes, n, bt, wt, pr)

    # Find turn around time for all processes
    findTurnAroundTime(processes, n, bt, wt, tat)

    # Display processes along with all details
    print("Processes    Burst Time     Priority     Waiting Time    Turn-Around Time")

    # Calculate total waiting time and total turn around time
    for i in range(n):
        total_wt = total_wt + wt[i]
        total_tat = total_tat + tat[i]
        print("   ", processes[i], "\t\t", bt[i], "\t\t", pr[i], "\t\t", wt[i], "\t\t", tat[i])

    print(f"\nAverage waiting time = {total_wt / n:.2f}")
    print(f"Average turn around time = {total_tat / n:.2f}")

# Driver code
if __name__ == "__main__":
    # Process IDs
    processes = [1, 2, 3, 4]
    n = len(processes)

    # Burst time of all processes
    burst_time = [10, 5, 8, 6]

    # Priority of each process (lower value indicates higher priority)
    priority = [2, 1, 3, 4]

    # Function to calculate average waiting and turn around time
    findAverageTime(processes, n, burst_time, priority)
