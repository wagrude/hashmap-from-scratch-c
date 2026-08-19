````md
# Architecture

## Overview

The HashMap is designed as a modular C data structure with a clear separation between the public interface, implementation, and supporting utilities.

```text
                    HashMap Application
                           |
                           v
                        main.c
                           |
                           v
                    hash_table.h
                           |
                           v
                    hash_table.c
                     /          \
                    /            \
                   v              v
              Hash Function    Hash Table
                   |              |
                   |              +── Items
                   |              +── Keys
                   |              +── Values
                   |              +── Capacity
                   |              +── Count
                   |
                   v
                prime.c
````

## Core Components

### Hash Table

The `ht_hash_table` structure stores:

* Current table size
* Number of stored items
* Array of item pointers

```text
ht_hash_table
├── size
├── count
└── items[]
```

The `items` array contains pointers to `ht_item` objects.

### Hash Item

Each key-value pair is represented by an `ht_item`.

```text
ht_item
├── key
└── value
```

Both the key and value are currently represented as dynamically allocated strings.

## Hashing

A string key is passed through the hash function.

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
Table Index
```

The resulting index determines where the item should be stored in the hash table.

## Collision Handling

Different keys can produce the same table index.

```text
Key A ──┐
        ├──> Same Index
Key B ──┘
```

The implementation must handle these collisions without losing existing entries.

## Memory Management

The HashMap uses dynamic memory for:

* Hash table
* Item structures
* Keys
* Values

The ownership flow is:

```text
Create
  |
  v
Allocate Memory
  |
  v
Store Data
  |
  v
Use HashMap
  |
  v
Delete Items
  |
  v
Free Table
```

Every allocation must have a corresponding cleanup path.

## Resizing

When the table becomes too full, the HashMap can increase its capacity and redistribute existing items.

```text
Old Table
   |
   v
Increase Capacity
   |
   v
Create New Table
   |
   v
Recalculate Indices
   |
   v
Reinsert Items
   |
   v
Free Old Table
```

## Module Responsibilities

```text
main.c
  |
  +── Testing / Demonstration
  |
  v
hash_table.h
  |
  +── Public Structures
  +── Public API
  |
  v
hash_table.c
  |
  +── Hashing
  +── Item Management
  +── Table Management
  +── Collision Handling
  +── Resizing
  +── Memory Cleanup
  |
  v
prime.c / prime.h
  |
  +── Prime Number Utilities
```

## Design Goals

The architecture aims to keep the implementation:

* Modular
* Reusable
* Memory-safe
* Easy to test
* Easy to extend
* Independent from the test program

The HashMap implementation should remain separated from `main.c` so that the data structure can be used by other C programs without copying its implementation.

```
```
