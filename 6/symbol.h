// https://benhoyt.com/writings/hash-table-in-c/
#pragma once

#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define PRIME 211
#define INITIAL_CAPACITY 128

#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL

// typedef struct {
//   char *name;
//   size_t scope;
// } Symbol;
//
// typedef struct {
//   Symbol *symbols;
//   size_t capacity;
//   size_t length;
// } HashTable;

// Hash table entry (slot may be filled or empty).
typedef struct {
  const char *name; // key is NULL if this slot is empty
  void *value;
} Entry;

// Hash table structure: create with ht_create, free with ht_destroy.
typedef struct {
  Entry *entries;  // hash slots
  size_t capacity; // size of _entries array
  size_t length;   // number of items in hash table
} HashTable;

HashTable *ht_create(void) {
  // Allocate space for hash table struct.
  HashTable *table = malloc(sizeof(HashTable));
  if (table == NULL) {
    return NULL;
  }
  table->length = 0;
  table->capacity = INITIAL_CAPACITY;

  // Allocate (zero'd) space for entry buckets.
  table->entries = calloc(table->capacity, sizeof(Entry));
  if (table->entries == NULL) {
    free(table); // error, free table before we return!
    return NULL;
  }
  return table;
}

void ht_destroy(HashTable *table) {
  // First free allocated keys.
  for (size_t i = 0; i < table->capacity; i++) {
    free((void *)table->entries[i].name);
  }

  // Then free entries array and table itself.
  free(table->entries);
  free(table);
}

#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL

// Return 64-bit FNV-1a hash for key (NUL-terminated). See description:
// https://en.wikipedia.org/wiki/Fowler–Noll–Vo_hash_function
static uint64_t hash_key(const char *key) {
  uint64_t hash = FNV_OFFSET;
  for (const char *p = key; *p; p++) {
    hash ^= (uint64_t)(unsigned char)(*p);
    hash *= FNV_PRIME;
  }
  return hash;
}

void *ht_get(HashTable *table, const char *key) {
  // AND hash with capacity-1 to ensure it's within entries array.
  uint64_t hash = hash_key(key);
  size_t index = (size_t)(hash & (uint64_t)(table->capacity - 1));

  // Loop till we find an empty entry.
  while (table->entries[index].name != NULL) {
    if (strcmp(key, table->entries[index].name) == 0) {
      // Found key, return value.
      return table->entries[index].value;
    }
    // Key wasn't in this slot, move to next (linear probing).
    index++;
    if (index >= table->capacity) {
      // At end of entries array, wrap around.
      index = 0;
    }
  }
  return NULL;
}

// Internal function to set an entry (without expanding table).
static const char *ht_set_entry(Entry *entries, size_t capacity,
                                const char *key, void *value, size_t *plength) {
  // AND hash with capacity-1 to ensure it's within entries array.
  uint64_t hash = hash_key(key);
  size_t index = (size_t)(hash & (uint64_t)(capacity - 1));

  // Loop till we find an empty entry.
  while (entries[index].name != NULL) {
    if (strcmp(key, entries[index].name) == 0) {
      // Found key (it already exists), update value.
      entries[index].value = value;
      return entries[index].name;
    }
    // Key wasn't in this slot, move to next (linear probing).
    index++;
    if (index >= capacity) {
      // At end of entries array, wrap around.
      index = 0;
    }
  }

  // Didn't find key, allocate+copy if needed, then insert it.
  if (plength != NULL) {
    key = strdup(key);
    if (key == NULL) {
      return NULL;
    }
    (*plength)++;
  }
  entries[index].name = (char *)key;
  entries[index].value = value;
  return key;
}

// Expand hash table to twice its current size. Return true on success,
// false if out of memory.
static int ht_expand(HashTable *table) {
  // Allocate new entries array.
  size_t new_capacity = table->capacity * 2;
  if (new_capacity < table->capacity) {
    return 0; // overflow (capacity would be too big)
  }
  Entry *new_entries = calloc(new_capacity, sizeof(Entry));
  if (new_entries == NULL) {
    return 0;
  }

  // Iterate entries, move all non-empty ones to new table's entries.
  for (size_t i = 0; i < table->capacity; i++) {
    Entry entry = table->entries[i];
    if (entry.name != NULL) {
      ht_set_entry(new_entries, new_capacity, entry.name, entry.value, NULL);
    }
  }

  // Free old entries array and update this table's details.
  free(table->entries);
  table->entries = new_entries;
  table->capacity = new_capacity;
  return 1;
}

const char *ht_set(HashTable *table, const char *key, void *value) {
  assert(value != NULL);
  if (value == NULL) {
    return NULL;
  }

  // If length will exceed half of current capacity, expand it.
  if (table->length >= table->capacity / 2) {
    if (!ht_expand(table)) {
      return NULL;
    }
  }

  // Set entry and update length.
  return ht_set_entry(table->entries, table->capacity, key, value,
                      &table->length);
}

size_t ht_length(HashTable *table) { return table->length; }
