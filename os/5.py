# Function for Least Recently Used (LRU) page replacement
def lru(pages, capacity):
    memory = []
    page_faults = 0
    lru_stack = []

    for page in pages:
        if page not in memory:
            page_faults += 1
            if len(memory) < capacity:
                memory.append(page)
            else:
                # Replace the least recently used page
                lru_page = lru_stack.pop(0)
                memory.remove(lru_page)
                memory.append(page)
        # Remove the page from stack if it's already there (if recently used)
        if page in lru_stack:
            lru_stack.remove(page)
        lru_stack.append(page)  # Add page to the top of the stack

        print(f"Page {page} -> Memory: {memory}")
    
    return page_faults

# Function for First In First Out (FIFO) page replacement
def fifo(pages, capacity):
    memory = []
    page_faults = 0
    fifo_queue = []

    for page in pages:
        if page not in memory:
            page_faults += 1
            if len(memory) < capacity:
                memory.append(page)
                fifo_queue.append(page)
            else:
                # Replace the oldest page
                old_page = fifo_queue.pop(0)
                memory.remove(old_page)
                memory.append(page)
                fifo_queue.append(page)

        print(f"Page {page} -> Memory: {memory}")
    
    return page_faults

# Function for Optimal page replacement
def optimal(pages, capacity):
    memory = []
    page_faults = 0

    for i in range(len(pages)):
        if pages[i] not in memory:
            page_faults += 1
            if len(memory) < capacity:
                memory.append(pages[i])
            else:
                # Predict future pages usage
                future_use = []
                for j in range(len(memory)):
                    if memory[j] in pages[i+1:]:
                        future_use.append(pages[i+1:].index(memory[j]))
                    else:
                        future_use.append(float('inf'))

                # Find the page that won't be used for the longest time
                memory_index = future_use.index(max(future_use))
                memory[memory_index] = pages[i]

        print(f"Page {pages[i]} -> Memory: {memory}")
    
    return page_faults

# Driver code to test the algorithms
if __name__ == "__main__":
    # Test pages and capacity
    pages = [7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2]
    capacity = 3

    print("LRU Page Replacement")
    lru_faults = lru(pages, capacity)
    print(f"Total Page Faults (LRU): {lru_faults}\n")

    print("FIFO Page Replacement")
    fifo_faults = fifo(pages, capacity)
    print(f"Total Page Faults (FIFO): {fifo_faults}\n")

    print("Optimal Page Replacement")
    optimal_faults = optimal(pages, capacity)
    print(f"Total Page Faults (Optimal): {optimal_faults}\n")
