# Requirements

## Functional Requirements

- Create a hash table with an initial capacity.
- Store key-value pairs.
- Support insertion of key-value pairs.
- Support searching for values using keys.
- Support updating existing keys.
- Support deleting key-value pairs.
- Convert keys into valid table indices using a hash function.
- Handle hash collisions correctly.
- Resize the hash table when the load factor becomes too high.
- Properly allocate and free dynamic memory.
- Handle memory allocation failures safely.
- Handle missing keys safely.

## Performance Requirements

- Average-case insertion should be approximately O(1).
- Average-case search should be approximately O(1).
- Average-case deletion should be approximately O(1).
- Resizing may require O(n) work.
- Maintain a reasonable load factor.

## Technical Requirements

- Language: C
- Use dynamic memory management.
- Use separate `.c` and `.h` files.
- Implement the HashMap from scratch.
- Do not use external HashMap implementations.
- Compile with GCC.
- Keep the implementation modular and reusable.

## Testing Requirements

Test the implementation with:

- Empty hash table
- Single insertion
- Multiple insertions
- Searching existing keys
- Searching missing keys
- Updating existing keys
- Deleting keys
- Hash collisions
- Table resizing
- Large numbers of entries
- Memory management