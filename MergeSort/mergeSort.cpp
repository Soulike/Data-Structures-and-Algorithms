#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>

template <class T>
T *merge(T *leftArray, int leftArrayLength, T *rightArray, int rightArrayLength)
{
    T *mergedArray = (T *)malloc((leftArrayLength + rightArrayLength) * sizeof(T));
    int currentIndex = 0;
    int leftIndex = 0;
    int rightIndex = 0;

    while (leftIndex < leftArrayLength && rightIndex < rightArrayLength)
    {
        mergedArray[currentIndex++] = leftArray[leftIndex] > rightArray[rightIndex] ? rightArray[rightIndex++] : leftArray[leftIndex++];
    }

    if (leftIndex == leftArrayLength)
    {
        memcpy(mergedArray + currentIndex, rightArray + rightIndex, (rightArrayLength - rightIndex) * sizeof(T));
    }
    else if (rightIndex == rightArrayLength)
    {
        memcpy(mergedArray + currentIndex, leftArray + leftIndex, (leftArrayLength - leftIndex) * sizeof(T));
    }

    return mergedArray;
}

template <class T>
void mergeSort(T *array, int length)
{
    if (length > 1)
    {
        int mid = length / 2;
        mergeSort(array, mid);
        mergeSort(array + mid, length - mid);
        T *merged = merge(array, mid, array + mid, length - mid);
        memcpy(array, merged, length * sizeof(T));
        free(merged);
    }
}

int main()
{
    int arrayLength = 100000;
    int arr[arrayLength];
    srand(time(NULL));
    for (int i = 0; i < arrayLength; i++)
    {
        arr[i] = random();
    }

    mergeSort(arr, arrayLength);
}