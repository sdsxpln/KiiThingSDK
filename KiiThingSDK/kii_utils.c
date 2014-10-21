//
//  kii_utils.c
//  KiiThingSDK
//
//  Copyright (c) 2014 Kii. All rights reserved.
//

#include "kii_utils.h"

#include "kii_libc.h"

#include <assert.h>
#include <stdarg.h>

static size_t url_encoded_len(const char* element);
static char* url_encoded_copy(char* s1, const char* s2);

char *build_url(const char* first, ...)
{
    if (first == NULL) {
        return NULL;
    } else {
        size_t size = 0;
        char* retval = NULL;

        // calculate size.
        {
            va_list list;
            va_start(list, first);
            for (const char* element = first; element != NULL;
                    element = va_arg(list, char*)) {
                size = size + url_encoded_len(element) + 1;
            }
            va_end(list);
        }

        // alloc size.
        retval = kii_malloc(size);
        kii_memset(retval, 0, size);

        // copy elements;.
        {
            va_list list;
            va_start(list, first);

            // copy first element.
            url_encoded_copy(retval, first);

            for (const char* element = va_arg(list, char*); element != NULL;
                    element = va_arg(list, char*)) {
                size_t len = kii_strlen(retval);
                retval[len] = '/';
                retval[len + 1] = '\0';
                url_encoded_copy(&retval[len + 1], element);
            }
            va_end(list);
        }

        return retval;
    }
}

static size_t url_encoded_len(const char* element)
{
    assert(element != NULL);

    // TODO: calculate url encoded length.
    return kii_strlen(element);
}

static char* url_encoded_copy(char* s1, const char* s2)
{
    assert(s1 != NULL);
    assert(s2 != NULL);

    // TODO: copy url encoded s2 string to s1.
    return kii_strcpy(s1, s2);
}
