// Our key-value pairs (items) will each be stored in a struct:
typedef struct {
    char* key;
    char* value;
} ht_item;
// Our hash table stores an array of pointers to items, and some details about its size and how full it is:
// hash_table.h
typedef struct {
    int size;
    int count;
    ht_item** items;
} ht_hash_table;

