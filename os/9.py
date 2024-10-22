# Function to check if the system is in a safe state
def is_safe(processes, avail, maxm, allot):
    n = len(processes)  # Number of processes
    m = len(avail)  # Number of resources

    # Calculate the need matrix
    need = [[0] * m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            need[i][j] = maxm[i][j] - allot[i][j]

    # Mark all processes as not finished
    finish = [False] * n

    # To store the safe sequence
    safe_seq = [0] * n

    # Copy of available resources
    work = avail.copy()

    count = 0  # Count of processes in safe sequence
    while count < n:
        found = False
        for p in range(n):
            if not finish[p]:
                # Check if the current process can be allocated safely
                if all(need[p][j] <= work[j] for j in range(m)):
                    # If process p can be allocated, simulate resource allocation
                    for j in range(m):
                        work[j] += allot[p][j]

                    # Add this process to the safe sequence
                    safe_seq[count] = p
                    count += 1

                    # Mark process p as finished
                    finish[p] = True
                    found = True
                    print(f"Process {p} has been allocated safely.")

        if not found:
            print("The system is in an unsafe state! Deadlock may occur.")
            return False, []

    print("The system is in a safe state!")
    print(f"Safe sequence is: {' -> '.join(map(str, safe_seq))}")
    return True, safe_seq


# Main function to test the Banker's Algorithm
def main():
    # Number of processes and resources
    processes = [0, 1, 2, 3, 4]
    avail = [3, 3, 2]  # Available instances of resources

    # Maximum demand of each process
    maxm = [
        [7, 5, 3],  # P0
        [3, 2, 2],  # P1
        [9, 0, 2],  # P2
        [2, 2, 2],  # P3
        [4, 3, 3]   # P4
    ]

    # Resources currently allocated to each process
    allot = [
        [0, 1, 0],  # P0
        [2, 0, 0],  # P1
        [3, 0, 2],  # P2
        [2, 1, 1],  # P3
        [0, 0, 2]   # P4
    ]

    # Check if the system is in a safe state
    is_safe(processes, avail, maxm, allot)


# Run the program
if __name__ == "__main__":
    main()
