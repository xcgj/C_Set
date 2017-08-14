/*
插入排序—直接插入排序(Straight Insertion Sort)
基本思想:
将一个记录插入到已排序好的有序表中，从而得到一个新，记录数增1的有序表。
即：先将序列的第1个记录看成是一个有序的子序列，然后从第2个记录逐个进行插入，直至整个序列有序为止。
要点：设立哨兵，作为临时存储和判断数组边界之用。

如果碰见一个和插入元素相等的，那么插入元素把想插入的元素放在相等元素的后面。
所以，相等元素的前后顺序没有改变，从原无序序列出去的顺序就是排好序后的顺序，
所以插入排序是稳定的。

时间复杂度：插入排序对随即顺序的序列的时间复杂度也为O(N^2)，
但是对于基本有序的序列进行排序时间复杂度为O(N)
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MAX 10
void printArray(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//插入排序
void InsertSort(int arr[],int len)
{
    for (int i = 1; i < len; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            int temp = arr[i];
            int j = i - 1;
            for (; j >= 0 && temp < arr[j]; j--)
            {
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = temp;
        }
    }
}

int main()
{
    int arr[MAX];
    srand((unsigned int)time(NULL));
    for (int i = 0; i < MAX; i++)
    {
        arr[i] = rand() % MAX;
    }
    //排序前
    printArray(arr, MAX);
    //排序
    InsertSort(arr, MAX);
    //排序后
    printArray(arr, MAX);
    return EXIT_SUCCESS;
}
