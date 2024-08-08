#include <stdio.h>
#include <string.h>

// Define a structure to represent key-value pairs
struct KeyValuePair {
    char key[50];
    int value;
};

// Define a structure to represent a basic map
struct Map {
    struct KeyValuePair data[100]; // Assuming a fixed size for simplicity
    int size;
};

// Function to initialize a map
void initializeMap(struct Map *map) {
    map->size = 0;
}

// Function to add a key-value pair to the map
void addToMap(struct Map *map, const char *key, int value) {
    if (map->size < 100) { // Assuming a fixed size for simplicity
        strcpy(map->data[map->size].key, key);
        map->data[map->size].value = value;
        map->size++;
    } else {
        printf("Map is full. Cannot add more elements.\n");
    }
}

// Function to retrieve a value based on a key
int getValue(struct Map *map, const char *key) {
    for (int i = 0; i < map->size; i++) {
        if (strcmp(map->data[i].key, key) == 0) {
            return map->data[i].value;
        }
    }
    return -1; // Key not found
}

int main() {
    struct Map myMap;
    initializeMap(&myMap);

    addToMap(&myMap, "apple", 5);
    addToMap(&myMap, "banana", 7);
    addToMap(&myMap, "cherry", 10);

    int value = getValue(&myMap, "banana");
    if (value != -1) {
        printf("The value associated with 'banana' is: %d\n", value);
    } else {
        printf("Key 'banana' not found in the map.\n");
    }

    return 0;
}
