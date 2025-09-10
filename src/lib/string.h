#ifndef OBBY_DIFF_LIB_STRING_H
#define OBBY_DIFF_LIB_STRING_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OBBY_DIFF_LIB_STRING_DEFAULT_CAPACITY 32
#define OBBY_DIFF_LIB_STRING_RESIZE_FACTOR    2

typedef struct String {
    char *buf;
    size_t count;
    size_t capacity;
} String;

/**
 * Initializes a String.
 *
 * @param string The String to initialize
 * @returns True if initialized correctly, false otherwise
 */
bool String_init(String *string);

/**
 * Resets a String, but keeps the allocated memory.
 *
 * @param string The String to reset
 */
void String_reset(String *string);

/**
 * Frees a String.
 *
 * @param string The String to free
 */
void String_free(String *string);

/**
 * Resizes a string, allocating more memory.
 *
 * @param string The String to resize
 * @returns True if successful, false otherwise
 */
bool String_resize(String *string);

/**
 * Appends a character to a String.
 *
 * @param string The String to append to
 * @returns True if successful, false otherwise
 */
bool String_append_char(String *string, char c);

/**
 * Appends a C string to a String.
 *
 * @param string The String to append to
 * @param cstr The C string to append
 * @returns True if successful, false otherwise
 */
bool String_append_cstr(String *string, char *cstr);

/**
 * Appends a String to another String.
 *
 * @param string The String to append to
 * @param other The String to append
 * @returns True if successful, false otherwise
 */
bool String_append(String *string, String other);

/**
 * Displays a String for debugging.
 *
 * @param string The String to display
 */
void String_show(String string);

#endif // OBBY_DIFF_LIB_STRING_H
