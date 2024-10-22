import threading
import time
import random
from collections import deque

# Buffer size
BUFFER_SIZE = 5

# Shared buffer (FIFO queue)
buffer = deque()

# Semaphores for synchronization
mutex = threading.Semaphore(1)     # To protect access to the buffer (mutual exclusion)
empty = threading.Semaphore(BUFFER_SIZE)  # Tracks empty slots in the buffer
full = threading.Semaphore(0)      # Tracks filled slots in the buffer

# Producer function
def producer(producer_id):
    global buffer
    while True:
        time.sleep(random.randint(1, 3))  # Simulate time to produce an item
        item = random.randint(1, 100)  # Produce a random item

        # Wait if there are no empty slots in the buffer
        empty.acquire()

        # Enter critical section
        mutex.acquire()
        buffer.append(item)  # Add the item to the buffer
        print(f"Producer {producer_id} produced {item}")
        mutex.release()

        # Signal that there is one more item in the buffer
        full.release()

# Consumer function
def consumer(consumer_id):
    global buffer
    while True:
        time.sleep(random.randint(2, 4))  # Simulate time to consume an item

        # Wait if there are no items to consume in the buffer
        full.acquire()

        # Enter critical section
        mutex.acquire()
        item = buffer.popleft()  # Remove the item from the buffer
        print(f"Consumer {consumer_id} consumed {item}")
        mutex.release()

        # Signal that there is one more empty slot in the buffer
        empty.release()

# Main function to create producer and consumer threads
def main():
    num_producers = 2
    num_consumers = 2

    # Create producer threads
    producers = []
    for i in range(1, num_producers + 1):
        producer_thread = threading.Thread(target=producer, args=(i,))
        producers.append(producer_thread)
        producer_thread.start()

    # Create consumer threads
    consumers = []
    for i in range(1, num_consumers + 1):
        consumer_thread = threading.Thread(target=consumer, args=(i,))
        consumers.append(consumer_thread)
        consumer_thread.start()

    # Join threads (optional, to keep the main thread running)
    for producer_thread in producers:
        producer_thread.join()

    for consumer_thread in consumers:
        consumer_thread.join()

# Run the program
if __name__ == "__main__":
    main()
