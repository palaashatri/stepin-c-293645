#include "fun.h"
/**
 * @brief 
 * 
 * @param data 
 * @param key 
 * @return char* 
 */
char* decryptFile(char* data, int key)
{
    int i;
    for(i=0;i<strlen(data);i++)
    {
        data[i] = data[i]-key;
    }

    return data;
} 