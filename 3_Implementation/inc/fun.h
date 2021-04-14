/**
 * @file fun.h
 * @author Palaash Atri
 * @brief Header file for encryption and decryption functions
 * @version 0.1
 * @date 2021-04-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __FUN_H__
#define __FUN_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 * @brief 
 * 
 * @param data 
 * @param key 
 * @return char* 
 */
char* encryptFile(char* data, int key);

/**
 * @brief 
 * 
 * @param data 
 * @param key 
 * @return char* 
 */
char* decryptFile(char* data, int key);


#endif