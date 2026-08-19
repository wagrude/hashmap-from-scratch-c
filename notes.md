````md
# Notes

## Current Implementation

The project currently contains the basic HashMap foundation:

- `ht_item` stores a key-value pair.
- `ht_hash_table` stores the table size, item count, and array of item pointers.
- `ht_new()` creates the hash table.
- `ht_del_hash_table()` releases the hash table and its allocated memory.
- `ht_new_item()` creates a new key-value item.
- `ht_del_item()` frees an individual item.
- `ht_hash()` converts a string key into a hash value.

## Data Structure

Each item contains:

```text
ht_item
├── key
└── value
````

The hash table contains:

```text
ht_hash_table
├── size
├── count
└── items[]
```

`items` is an array of pointers to `ht_item`.

## Memory Management

The current implementation uses dynamic memory allocation:

* `malloc()` for structures
* `calloc()` for the item pointer array
* `strdup()` for keys and values
* `free()` for cleanup

Allocation failures are checked before using allocated memory.

## Hashing

The current hash function uses a polynomial-style calculation with:

* A base value `a`
* The string characters
* The table size `m`

The final hash value is reduced using the table size so that it can later be used as a table index.

## Current Limitations

The HashMap does not yet implement:

* Insertion
* Search
* Update
* Delete operation
* Collision resolution
* Dynamic resizing
* Load-factor management
* Complete error handling
* Benchmarking

These will be implemented incrementally.

## Important C Concepts

### Header and Source Separation

`hash_table.h` contains the public interface while `hash_table.c` contains the implementation.

Functions used by `main.c` must have their declarations available through the header.

### Static Functions

Functions such as:

```c
static ht_item *ht_new_item(...)
```

are private to `hash_table.c`.

They are not exposed through the header because they are implementation details.

### Pointer Array

The following:

```c
ht_item **items;
```

represents an array of pointers to `ht_item` objects.

Conceptually:

```text
items
  |
  v
+------+------+------+------+
|  *   | NULL |  *   | NULL |
+------+------+------+------+
   |             |
   v             v
 item          item
```

## Build Command

The current project can be compiled with:

```bash
gcc main.c src/hash_table.c -o hashmap -lm
```

Run:

```bash
./hashmap
```

Current output:

```text
HashMap created successfully
```

## Development Notes

The implementation is being built incrementally.

The current priority is to understand each component before adding the next one rather than implementing the entire HashMap at once.

```
```
