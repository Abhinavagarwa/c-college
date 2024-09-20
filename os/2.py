# Function to find the waiting time for all processes
def findWaitingTime(processes, n, bt, wt):
    # Sorting processes by burst time
    for i in range(n):
        for j in range(i + 1, n):
            if bt[i] > bt[j]:
                # Swapping burst time
                bt[i], bt[j] = bt[j], bt[i]
                # Swapping process numbers
                processes[i], processes[j] = processes[j], processes[i]

    # Waiting time for first process is 0
    wt[0] = 0

    # Calculating waiting time for the rest
    for i in range(1, n):
        wt[i] = bt[i - 1] + wt[i - 1]

# Function to calculate turn around time
def findTurnAroundTime(processes, n, bt, wt, tat):
    # Calculating turn around time by adding
    # burst time and waiting time
    for i in range(n):
        tat[i] = bt[i] + wt[i]

# Function to calculate average time
def findAverageTime(processes, n, bt):
    wt = [0] * n
    tat = [0] * n
    total_wt = 0
    total_tat = 0

    # Function to find waiting time of all processes
    findWaitingTime(processes, n, bt, wt)

    # Function to find turn around time for all processes
    findTurnAroundTime(processes, n, bt, wt, tat)

    # Display processes along with all details
    print("Processes    Burst Time     Waiting Time    Turn-Around Time")

    # Calculate total waiting time and total turn around time
    for i in range(n):
        total_wt = total_wt + wt[i]
        total_tat = total_tat + tat[i]
        print("   ", processes[i], "\t\t", bt[i], "\t\t", wt[i], "\t\t", tat[i])

    print(f"\nAverage waiting time = {total_wt / n:.2f}")
    print(f"Average turn around time = {total_tat / n:.2f}")

# Driver code
if __name__ == "__main__":
    # Process IDs
    processes = [1, 2, 3, 4]
    n = len(processes)

    # Burst time of all processes
    burst_time = [5, 9, 6, 3]

    # Calculate average time
    findAverageTime(processes, n, burst_time)
