#ifndef ARRAY_H
#define ARRAY_H

struct _Array;

typedef struct _Array Array;

Array *createArray(unsigned long long initialSize);
void destroyArray(Array *array);

void insertIntoArray(Array *array, unsigned long long index, int value);
void deleteFromArray(Array *array, unsigned long long index);
void changeValueInArray(Array *array, unsigned long long index, int newValue);
int getFromArray(Array *array, unsigned long long index);
unsigned long long getSizeOfArray(Array *array);
unsigned long long getLengthOfArray(Array *array);

#endif