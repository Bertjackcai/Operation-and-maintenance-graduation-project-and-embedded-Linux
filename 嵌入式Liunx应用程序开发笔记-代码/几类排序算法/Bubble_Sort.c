/*
ð������
 
�Ƚ����ڵ�Ԫ�ء������һ���ȵڶ����󣬾ͽ�������������

��ÿһ������Ԫ����ͬ���Ĺ������ӿ�ʼ��һ�Ե���β�����һ�ԡ��ⲽ���������Ԫ�ػ�����������

������е�Ԫ���ظ����ϵĲ��裬�������һ����

����ÿ�ζ�Խ��Խ�ٵ�Ԫ���ظ�����Ĳ��裬ֱ��û���κ�һ��������Ҫ�Ƚϡ�
*/
#include <stdio.h>
void bubble_sort(int arr[], int len)
{
        int i, j, temp;
        for (i = 0; i < len - 1; i++)
                for (j = 0; j < len - 1 - i; j++)
                        if (arr[j] > arr[j + 1])
                        {
                                temp = arr[j];
                                arr[j] = arr[j + 1];
                                arr[j + 1] = temp;
                        }
}

void bubble_sort_t(int arr[], int len)
{
        int i, j, temp, isSorted;
        for (i = 0; i < len - 1; i++)
        {
                isSorted = 1; //����ʣ�µ�Ԫ���Ѿ��������
                for (j = 0; j < len - 1 - i; j++)
                {

                        if (arr[j] > arr[j + 1])
                        {
                                temp = arr[j];
                                arr[j] = arr[j + 1];
                                arr[j + 1] = temp;
                                isSorted = 0; //һ����Ҫ��������Ԫ�أ���˵��ʣ�µ�Ԫ��û�������
                        }
                        if (!isSorted)
                                break;
                }
        }
}
int main()
{
        int arr[] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
        int len = (int)sizeof(arr) / sizeof(*arr);
        bubble_sort_t(arr, len);
        int i;
        for (i = 0; i < len; i++)
                printf("%d ", arr[i]);
        return 0;
}
