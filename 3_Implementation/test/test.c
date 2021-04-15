/**
 * @file test.c
 * @author Palaash Atri
 * @brief test file to test the encryption and decryption functions using Unity framework
 * @version 0.1
 * @date 2021-04-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "unity.h"
#include "fun.h"

// Defining project name from makefile
#define PROJECT_NAME    "edr"

// Prototype functions
void test_encrypt(void);
void test_decrypt(void);

// Required by the unity test framework
void setUp(){}
// Required by the unity test framework
void tearDown(){}

// Start of the application test
int main()
{
    // Initiate the unity test framework
    UNITY_BEGIN();

    // Run test functions
    RUN_TEST(test_encrypt);
    RUN_TEST(test_decrypt);

    // Close the unity test framework
    return UNITY_END();
}

// Test functions

void test_encrypt(void)
{
    TEST_ASSERT_EQUAL("cdef",encryptFile("abcd",2));
}

void test_decrypt(void)
{
    TEST_ASSERT_EQUAL("abcd",decryptFile("cdef",2));
}

