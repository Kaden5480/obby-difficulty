#include "string.h"

bool String_init(String *string) {
    string->count = 0;
    string->capacity = OBBY_DIFF_LIB_STRING_DEFAULT_CAPACITY;
    string->buf = (char *) calloc(string->capacity, sizeof(char));

    if (string->buf != NULL) {
        return true;
    }

    return false;
}

void String_reset(String *string) {
    memset(string->buf, 0, string->count);
    string->count = 0;
}

void String_free(String *string) {
    free(string->buf);
    string->capacity = 0;
    string->count = 0;
    string->buf = NULL;
}

bool String_resize(String *string) {
    size_t new_cap = OBBY_DIFF_LIB_STRING_RESIZE_FACTOR
        * string->capacity;

    char *new_buf = (char *) realloc(
        string->buf, new_cap * sizeof(char)
    );

    if (new_buf == NULL) {
        return false;
    }

    memset(
        new_buf + string->capacity,
        0,
        new_cap - string->capacity
    );

    string->buf = new_buf;
    string->capacity = new_cap;

    return true;
}

bool String_append_char(String *string, char c) {
    if (string->count + 1 >= string->capacity) {
        if (String_resize(string) == false) {
            return false;
        }
    }

    string->buf[string->count] = c;
    string->count++;

    return true;
}

bool String_append_cstr(String *string, char *cstr) {
    for (size_t i = 0; i < strlen(cstr); i++) {
        if (String_append_char(string, cstr[i]) == false) {
            return false;
        }
    }

    return true;
}

bool String_append(String *string, String other) {
    return String_append_cstr(string, other.buf);
}

void String_show(String string) {
    if (string.buf == NULL) {
        printf(
            "String 0x0\n"
            "count:    %zu\n"
            "capacity: %zu\n",
            string.count,
            string.capacity
        );
        return;
    }

    printf(
        "String %p\n"
        "buf:      %s\n"
        "count:    %zu\n"
        "capacity: %zu\n",
        (void *) (string.buf),
        string.buf,
        string.count,
        string.capacity
    );
}
