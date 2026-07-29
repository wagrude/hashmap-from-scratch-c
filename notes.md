# Hash Table in C - Notes

# Phase 1 - Basic Structure

## ht_item

ht_item ek chota box hai.

Iske andar 2 cheeze hoti hain:
- key
- value

Ye actual string store nahi karta.
Sirf uska address (pointer) store karta hai.

Example:

key   -> "apple"
value -> "100"

------------------------------------

## ht_hash_table

Ye ek badi almirah hai.

Iske andar bahut saare ht_item wale boxes hote hain.

Isme 3 cheeze hain:

- size -> Total kitne boxes (buckets) hain.
- count -> Abhi kitne boxes use ho rahe hain.
- items -> Sab boxes ka collection.

------------------------------------

## Maine Kya Seekha

- struct = apna khud ka box banana.
- typedef = struct ko easy naam dena.
- ht_item = ek key-value pair.
- ht_hash_table = bahut saare ht_item ko manage karta hai.
- char* = address store karta hai, string nahi.

------------------------------------

## Doubts

- char* hi kyu use kiya?
- ht_item** kyu hai?