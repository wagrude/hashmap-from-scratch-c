# hashmap-from-scratch-c

A hash table implementation written entirely in C from scratch, designed to provide a clear understanding of hashing, collision handling, memory management, and hash table internals.

## Overview

This project implements a hash table without relying on external hash table libraries.

The implementation focuses on understanding how key-value storage works internally, including:

- Hashing
- Key-value storage
- Collision resolution
- Dynamic memory management
- Table resizing
- Modular C design

## Features

- Insert key-value pairs
- Search values by key
- Update existing keys
- Delete keys
- Custom hash function
- Collision handling using separate chaining
- Dynamic resizing
- Manual memory management
- Modular `.c` and `.h` structure

## Data Structure

The hash table uses an array of buckets.

Each bucket can contain a linked list of entries to handle collisions.

```text
Hash Table
    |
    v
Array of Buckets
    |
    +---- Bucket 0
    |       |
    |       v
    |    Linked List
    |
    +---- Bucket 1
    |
    +---- Bucket 2
    |       |
    |       v
    |    Linked List
    |
    +---- ...
````

This approach is known as **Separate Chaining**.

## Hashing

Keys are passed through a custom hash function to determine the bucket in which an entry should be stored.

```text
Key
 |
 v
Hash Function
 |
 v
Hash Value
 |
 v
Bucket Index
 |
 v
Key-Value Entry
```

## Collision Handling

Two or more keys can produce the same bucket index.

Instead of overwriting an existing entry, the implementation stores colliding entries in the same bucket using a linked list.

```text
Bucket
  |
  v
[Key A | Value A]
       |
       v
[Key B | Value B]
       |
       v
[Key C | Value C]
```

## Dynamic Resizing

The hash table can increase its capacity when the table becomes too full.

During resizing:

1. A larger table is allocated.
2. Existing entries are rehashed.
3. Entries are placed into their new bucket positions.
4. The old table is released.

This helps maintain efficient average-case performance.

## Time Complexity

| Operation | Average | Worst Case |
| --------- | ------- | ---------- |
| Insert    | O(1)    | O(n)       |
| Search    | O(1)    | O(n)       |
| Delete    | O(1)    | O(n)       |
| Resize    | O(n)    | O(n)       |

Average-case performance depends on a good hash function and maintaining a reasonable load factor.

## Project Structure

```text
hashmap-from-scratch-c/
├── src/
│   ├── hash_table.c
│   ├── hash_table.h
│   ├── prime.c
│   └── prime.h
├── main.c
├── goals.md
├── requirements.md
├── structure.md
├── architecture.md
├── notes.md
├── README.md
├── .gitignore
└── LICENSE
```

## Build

Compile the project using GCC:

```bash
gcc main.c src/hash_table.c src/prime.c -o hashmap -lm
```

Run:

```bash
./hashmap
```

## Learning Objectives

This project is intended to strengthen understanding of:

* Hash tables
* Hash functions
* Collision resolution
* Pointers
* Dynamic memory allocation
* Structs
* Linked lists
* Time complexity
* Memory management
* Modular C programming

## Current Status

The project is being developed incrementally, with the implementation built and tested one component at a time.
