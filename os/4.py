# Function to find the waiting time for all processes
def findWaitingTime(processes, n, bt, wt, quantum):
    # Copy burst times into remaining burst times array
    rem_bt = [0] * n
    for i in range(n):
        rem_bt[i] = bt[i]

    t = 0  # Current time

    # Looping until all processes are done
    while True:
        done = True

        # Traverse all processes
        for i in range(n):
            # If burst time of a process is greater than 0, process is still pending
            if rem_bt[i] > 0:
                done = False  # There is a pending process

                # If remaining burst time is greater than quantum, process can execute for quantum time
                if rem_bt[i] > quantum:
                    t += quantum  # Increase current time by quantum
                    rem_bt[i] -= quantum  # Decrease remaining burst time by quantum

                # If remaining burst time is less than or equal to quantum, process will finish
                else:
                    t += rem_bt[i]  # Increase current time by remaining burst time
                    wt[i] = t - bt[i]  # Waiting time = current time - burst time
                    rem_bt[i] = 0  # Process is finished

        # If all processes are done
        if done:
            break

# Function to calculate turn around time
def findTurnAroundTime(processes, n, bt, wt, tat):
    # Turnaround time is sum of burst time and waiting time
    for i in range(n):
        tat[i] = bt[i] + wt[i]

# Function to calculate average time
def findAverageTime(processes, n, bt, quantum):
    wt = [0] * n  # Waiting times
    tat = [0] * n  # Turnaround times

    # Find waiting time of all processes
    findWaitingTime(processes, n, bt, wt, quantum)

    # Find turn around time for all processes
    findTurnAroundTime(processes, n, bt, wt, tat)

    # Display processes along with all details
    print("Processes    Burst Time     Waiting Time    Turn-Around Time")

    total_wt = 0
    total_tat = 0
    for i in range(n):
        total_wt += wt[i]
        total_tat += tat[i]
        print(f"   {i+1}\t\t{bt[i]}\t\t{wt[i]}\t\t{tat[i]}")

    print(f"\nAverage waiting time = {total_wt / n:.2f}")
    print(f"Average turn around time = {total_tat / n:.2f}")

# Driver code
if __name__ == "__main__":
    # Process IDs
    processes = [1, 2, 3, 4]
    n = len(processes)

    # Burst time of all processes
    burst_time = [10, 5, 8, 6]

    # Time quantum
    quantum = 2

    # Function to calculate average waiting and turn around time
    findAverageTime(processes, n, burst_time, quantum)
