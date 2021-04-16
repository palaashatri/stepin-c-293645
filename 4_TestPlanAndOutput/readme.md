# Test Plan and Output

* Test functions defined in `3_Implementation/test/test.c`

| Test Function | Function Used | Expected Output | Test Output |
|---|---|---|---|
|`test_encrypt()`|`encryptFile("abcd",2)`|`cdef`|`cdef`|
|`test_decrypt()`|`decryptFile("cdef",2)`|`abcd`|`abcd`|