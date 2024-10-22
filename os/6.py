# Memory Management using First Fit, Best Fit, and Worst Fit algorithms

# Function to perform First Fit allocation
def first_fit(blocks, processes):
    allocation = [-1] * len(processes)
    
    # Iterate over each process
    for i in range(len(processes)):
        # Iterate over blocks to find the first block that fits the process
        for j in range(len(blocks)):
            if blocks[j] >= processes[i]:
                allocation[i] = j  # Allocate block j to process i
                blocks[j] -= processes[i]  # Reduce available memory in the block
                break

    return allocation

# Function to perform Best Fit allocation
def best_fit(blocks, processes):
    allocation = [-1] * len(processes)

    # Iterate over each process
    for i in range(len(processes)):
        best_index = -1
        # Find the block that fits the process with the smallest leftover space
        for j in range(len(blocks)):
            if blocks[j] >= processes[i]:
                if best_index == -1 or blocks[j] < blocks[best_index]:
                    best_index = j

        if best_index != -1:
            allocation[i] = best_index  # Allocate best block to process
            blocks[best_index] -= processes[i]  # Reduce available memory

    return allocation

# Function to perform Worst Fit allocation
def worst_fit(blocks, processes):
    allocation = [-1] * len(processes)

    # Iterate over each process
    for i in range(len(processes)):
        worst_index = -1
        # Find the block that fits the process with the most leftover space
        for j in range(len(blocks)):
            if blocks[j] >= processes[i]:
                if worst_index == -1 or blocks[j] > blocks[worst_index]:
                    worst_index = j

        if worst_index != -1:
            allocation[i] = worst_index  # Allocate worst block to process
            blocks[worst_index] -= processes[i]  # Reduce available memory

    return allocation

# Helper function to display allocation result
def display_allocation(allocation, processes, algo_name):
    print(f"\n{algo_name} Allocation:")
    print("Process No.\tProcess Size\tBlock No.")
    for i in range(len(processes)):
        block_no = allocation[i] + 1 if allocation[i] != -1 else "Not Allocated"
        print(f"{i+1}\t\t{processes[i]}\t\t{block_no}")


# Main function to test the algorithms
def main():
    # Example memory blocks and processes
    blocks = [100, 500, 200, 300, 600]
    processes = [212, 417, 112, 426]

    # Make a copy of blocks for each algorithm to preserve original block sizes
    blocks_ff = blocks.copy()
    blocks_bf = blocks.copy()
    blocks_wf = blocks.copy()

    # First Fit
    allocation_ff = first_fit(blocks_ff, processes)
    display_allocation(allocation_ff, processes, "First Fit")

    # Best Fit
    allocation_bf = best_fit(blocks_bf, processes)
    display_allocation(allocation_bf, processes, "Best Fit")

    # Worst Fit
    allocation_wf = worst_fit(blocks_wf, processes)
    display_allocation(allocation_wf, processes, "Worst Fit")


# Run the main function
if __name__ == "__main__":
    main()
