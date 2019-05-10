#include <stdlib.h>
#include <string.h>
#include "Array.h"

struct _Array
{
    int *array;
    unsigned long long length; // 有多少个元素
    unsigned long long size;   // 能容纳多少个元素
};

// 传入一个 Array，然后把其容量增大两倍
static void expand(Array *array)
{
    int *oldInnerArray = array->array;
    unsigned long long nowSize = array->size ? array->size : 1;
    unsigned long long nowLength = array->length;
    int *newInnerArray = (int *)malloc(2 * nowSize * sizeof(int));
    memcpy(newInnerArray, oldInnerArray, nowLength * sizeof(int));
    array->array = newInnerArray;
    array->size = 2 * nowSize;
    free(oldInnerArray);
}

Array *createArray(unsigned long long initialSize)
{
    Array *newArray = (Array *)malloc(sizeof(Array));
    newArray->array = (int *)malloc(initialSize * sizeof(int));
    newArray->length = 0;
    newArray->size = initialSize;
    return newArray;
}

void destroyArray(Array *array)
{
    free(array->array);
    free(array);
}

void insertIntoArray(Array *array, unsigned long long index, int value)
{
    unsigned long long nowLength = array->length;
    unsigned long long nowSize = array->size;
    if (nowSize == nowLength)
    {
        expand(array);
    }
    int *innerArray = array->array;
    memmove(innerArray + index + 1, innerArray + index, (nowLength - index) * sizeof(int));
    innerArray[index] = value;
    array->length++;
}

void deleteFromArray(Array *array, unsigned long long index)
{
    unsigned long long nowLength = array->length;
    int *innerArray = array->array;
    memmove(innerArray + index, innerArray + index + 1, (nowLength - index - 1 * sizeof(int)));
    array->length--;
}

void changeValueInArray(Array *array, unsigned long long index, int newValue)
{
    int *innerArray = array->array;
    innerArray[index] = newValue;
}

int getFromArray(Array *array, unsigned long long index)
{
    int *innerArray = array->array;
    return innerArray[index];
}

unsigned long long getSizeOfArray(Array *array)
{
    return array->size;
}

unsigned long long getLengthOfArray(Array *array)
{
    return array->length;
}