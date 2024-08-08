import queue

def main():
    q = queue.Queue()

    # Enqueue elements
    q.put(10)
    q.put(20)
    q.put(30)

    # Dequeue and print elements
    while not q.empty():
        element = q.get() # Dequeue an element (pop)
        print("Dequeued:", element)

    # Check if the queue is empty
    is_empty = q.empty()
    print("Is the queue empty?", is_empty)

    # Get the size of the queue
    size = q.qsize()
    print("Queue size:", size)

if __name__ == "__main__":
    main()
