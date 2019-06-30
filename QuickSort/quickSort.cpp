#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>

template <class T>
void swap(T *a, T *b)
{
    if (a != b)
    {
        T temp = *a;
        *a = *b;
        *b = temp;
    }
}

template <class T>
void quickSortRecursive(T *array, int leftIndex, int rightIndex)
{
    if (rightIndex > leftIndex)
    {
        T pivot = array[leftIndex];
        int left = leftIndex + 1;
        int right = rightIndex;
        while (true)
        {
            while (array[left] < pivot)
            {
                left++;
            }

            while (array[right] > pivot)
            {
                right--;
            }

            if (left >= right)
            {
                break;
            }

            swap(&array[left], &array[right]);
        }

        swap(&array[right], &array[leftIndex]);

        quickSortRecursive(array, leftIndex, right - 1);
        quickSortRecursive(array, right + 1, rightIndex);
    }
}

template <class T>
void quickSort(T *array, int length)
{
    quickSortRecursive(array, 0, length - 1);
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

    quickSort(arr, arrayLength);
}