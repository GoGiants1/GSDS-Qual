def main():
    numbers = [1, 2, 3, 4, 5]

    # Print the elements of the list
    for num in numbers:
        print(num, end=" ")
    print()

    # Access and modify an element
    numbers[2] = 10
    print("Modified element at index 2:", numbers[2])

    # Get the length of the list
    length = len(numbers)
    print("Length of the list:", length)

    # List slicing
    sub_list = numbers[1:4] # Get a slice from index 1 to 3 (inclusive)
    print("Sublist:", sub_list)

    # Adding and removing elements
    my_list = [1, 2, 3]
    my_list.append(4)
    my_list.insert(1, 5) # Insert an element at index 1
    my_list.remove(2) # Remove the first occurrence of 2
    popped_element = my_list.pop() # Remove and return the last element
    print("Modified list:", my_list)
    print("Popped element:", popped_element)

if __name__ == "__main__":
    main()
