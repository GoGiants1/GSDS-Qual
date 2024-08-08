from collections import deque

def main():
    dq = deque()

    # Append elements to the right end
    dq.append(10)
    dq.append(20)

    # Append elements to the left end
    dq.appendleft(5)
    dq.appendleft(15)
    
    # Access
    right_element = dq[-1]  # Access the rightmost element
    left_element = dq[0]  # Access the leftmost element

    # Remove and print elements from both ends
    while dq:
        right_element = dq.pop()
        left_element = dq.popleft()
        print("Right Element:", right_element)
        print("Left Element:", left_element)

    # Check if the deque is empty
    is_empty = not bool(dq)
    print("Is the deque empty?", is_empty)

if __name__ == "__main__":
    main()
