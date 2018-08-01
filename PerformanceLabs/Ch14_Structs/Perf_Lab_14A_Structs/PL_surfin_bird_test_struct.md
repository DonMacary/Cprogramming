# PERFORMANCE LAB: SURFIN BIRD TEST STRUCT

Struct

“Surfin’ Bird Test Struct”

**Define a struct to test find_the_word() from Performance Lab I.5.a-4**

```c
char * find_the_word(char * sentence_ptr, char * searchWord_ptr, int * errorCode_ptr);
```

* **Your struct should include:**
    * Input string (sentence_ptr)
    * Input search word (searchWord_ptr)
    * Expected return value (char *)
    * Expected error code (*(errorCode_ptr))
* Only Address Arithmetic is permitted
* Print the human-readable results

* **Test input should include, at a minimum, the following situations:**
    * Normal input
    * sentence_ptr is NULL
    * searchWord_ptr is NULL
    * errorCode_ptr is NULL
    * Two occurrences of searchWord
    * No occurrences of searchWord