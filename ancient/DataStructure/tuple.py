def main():
    # Creating a tuple
    my_tuple = (42, 3.14, "Hello")

    # Accessing elements
    first_element = my_tuple[0]
    second_element = my_tuple[1]
    third_element = my_tuple[2]

    print(f"Tuple Elements: {first_element} {second_element} {third_element}")

    # Modifying elements (Tuples are immutable, so you can't modify elements directly)
    # Instead, you can create a new tuple with the modified values
    modified_tuple = my_tuple[:2] + (2.718,) + my_tuple[2:]

    print(f"Modified Tuple Elements: {modified_tuple[0]} {modified_tuple[1]} {modified_tuple[2]}")

    # Tuple size
    tuple_size = len(my_tuple)
    print(f"Tuple Size: {tuple_size}")

    # Tuple concatenation
    tuple1 = (10, 'X')
    tuple2 = (7.5,)
    concatenated_tuple = tuple1 + tuple2
    print(f"Concatenated Tuple: {concatenated_tuple[0]} {concatenated_tuple[1]}")

if __name__ == "__main__":
    main()
