def maxHeapify(arr, N, i):
    largest = i  # Initialize largest as root
    l = 2 * i + 1     # left = 2*i + 1
    r = 2 * i + 2     # right = 2*i + 2

    if l < N and arr[largest] < arr[l]:
        largest = l

    if r < N and arr[largest] < arr[r]:
        largest = r

    # Change root, if needed
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]  # swap

        # Heapify the root.
        maxHeapify(arr, N, largest)

def minHeapify(arr, N, i):
    smallest = i  # Initialize largest as root
    l = 2 * i + 1     # left = 2*i + 1
    r = 2 * i + 2     # right = 2*i + 2

    if l < N and arr[smallest] > arr[l]:
        smallest = l

    if r < N and arr[smallest] > arr[r]:
        smallest = r

    # Change root, if needed
    if smallest != i:
        arr[i], arr[smallest] = arr[smallest], arr[i]  # swap

        # Heapify the root.
        minHeapify(arr, N, smallest)

def heapSortAscending(arr):
    N = len(arr)

    # Build a maxheap.
    for i in range(N//2 - 1, -1, -1):
        maxHeapify(arr, N, i)

    # One by one extract elements
    for i in range(N-1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]  # swap
        maxHeapify(arr, i, 0)
        
def heapSortDescending(arr):
    N = len(arr)

    # Build a maxheap.
    for i in range(N//2 - 1, -1, -1):
        minHeapify(arr, N, i)

    # One by one extract elements
    for i in range(N-1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]  # swap
        minHeapify(arr, i, 0)


# Driver's code
if __name__ == '__main__':
    arr = [12, 11, 13, 5, 6, 7]

    heapSortAscending(arr)
    N = len(arr)

    print("Sorted array Ascending is")
    for i in range(N):
        print("%d" % arr[i], end=" ")

    print("")

    heapSortDescending(arr)

    print("Sorted array Descending is")
    for i in range(N):
        print("%d" % arr[i], end=" ")