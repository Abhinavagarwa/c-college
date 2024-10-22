import threading
import time
import random

# Semaphores for reader-writer synchronization
mutex = threading.Semaphore(1)      # To protect reader_count
wrt = threading.Semaphore(1)        # To allow one writer at a time

reader_count = 0  # Count of active readers

# Reader function
def reader(reader_id):
    global reader_count
    while True:
        time.sleep(random.randint(1, 3))  # Simulating delay

        # Entry section for reader
        mutex.acquire()
        reader_count += 1
        if reader_count == 1:
            wrt.acquire()  # If it's the first reader, lock the writer
        mutex.release()

        # Critical section (reading)
        print(f"Reader {reader_id} is reading")
        time.sleep(random.randint(1, 2))  # Simulating reading time
        print(f"Reader {reader_id} finished reading")

        # Exit section for reader
        mutex.acquire()
        reader_count -= 1
        if reader_count == 0:
            wrt.release()  # If it's the last reader, unlock the writer
        mutex.release()

# Writer function
def writer(writer_id):
    while True:
        time.sleep(random.randint(2, 5))  # Simulating delay

        # Entry section for writer
        wrt.acquire()

        # Critical section (writing)
        print(f"Writer {writer_id} is writing")
        time.sleep(random.randint(1, 3))  # Simulating writing time
        print(f"Writer {writer_id} finished writing")

        # Exit section for writer
        wrt.release()

# Main function to create reader and writer threads
def main():
    num_readers = 5
    num_writers = 2

    # Create reader threads
    readers = []
    for i in range(1, num_readers + 1):
        reader_thread = threading.Thread(target=reader, args=(i,))
        readers.append(reader_thread)
        reader_thread.start()

    # Create writer threads
    writers = []
    for i in range(1, num_writers + 1):
        writer_thread = threading.Thread(target=writer, args=(i,))
        writers.append(writer_thread)
        writer_thread.start()

    # Join threads
    for reader_thread in readers:
        reader_thread.join()

    for writer_thread in writers:
        writer_thread.join()

# Run the program
if __name__ == "__main__":
    main()
