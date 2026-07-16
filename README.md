# hashmap-from-scratch-c
A hash table implementation in C from scratch using separate chaining with linked lists.
A hash table implementation written entirely in C from scratch without using any external libraries.

## Features

- Insert key-value pairs
- Search by key
- Delete keys
- Collision handling (Separate Chaining)
- Dynamic resizing (optional)
- Custom hash function
- Clean modular code

## Data Structure

Hash Table
    ↓
Array of Buckets
    ↓
Linked Lists (Separate Chaining)

## Time Complexity

| Operation | Average |
|-----------|---------|
| Insert | O(1) |
| Search | O(1) |
| Delete | O(1) |

Worst Case: O(n)
