/*
在要排序的一组数中，选出最小（或者最大）的一个数与第1个位置的数交换；
然后在剩下的数当中再找最小（或者最大）的与第2个位置的数交换；
依次类推，直到第n-1个元素（倒数第二个数）和第n个元素（最后一个数）比较为止。

第一趟，从n个记录中找出关键码最小的记录与第一个记录交换；
第二趟，从第二个记录开始的n-1个记录中再选出关键码最小的记录与第二个记录交换；
以此类推.....
第i趟，则从第i个记录开始的n-i+1个记录中选出关键码最小的记录与第i个记录交换，
直到整个序列按关键码有序。

时间复杂度：O(N^2)，与冒泡排序相比减少了数组交换的次数
*/

#include <stdio.h>
void myswap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void PrintArr(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//初级版
void SelectionSort(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {if (arr[i] > arr[j])
            {
                myswap(&arr[i], &arr[j]);
            }
        }
    }
}

//进阶版--遍历时先不交换，用下标记录最值，一次遍历后再判断下标，决定要不要交换
void SelectionSortPro(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int min = i;//默认最小值的下标是i
        for (int j = i + 1; j < len; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        } //内层循环结束后，看min有没有被重新赋值，没有改变就不用交换
        if (min != i)
        {
            myswap(&arr[i], &arr[min]);
        }
    }
}

int main()
{
    int arr[] = {22, 1, 2, -1, 10, 28, 3};
    int len = sizeof(arr) / sizeof(int);
    PrintArr(arr, len);
    //SelectionSort(arr, len);
    SelectionSortPro(arr, len);
    PrintArr(arr, len);
    return 0;
}

/*
简单选择排序的改进——二元选择排序
简单选择排序，每趟循环只能确定一个元素排序后的定位。
我们可以考虑改进为每趟循环确定两个元素（当前趟最大和最小记录）的位置,从而减少排序所需的循环次数。
改进后对n个数据进行排序，最多只需进行[n/2]趟循环即可。
*/
