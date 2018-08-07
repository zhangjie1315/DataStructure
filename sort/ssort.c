#include <stdio.h>

//快速排序
//时间复杂度 最坏O(n^2):序列完全逆序 平均O(N*logN)
//空间复杂度 O(logN)
//
//交换法

int partion(int arr[],int beg,int end)
{
  //1.先定义好区间的边界
  int left = beg;
  int right = end;
  //2.取最后一个元素为基准值
  int key = arr[right];
  while(left<right)
  {
      //从左到右找到第一个大于基准值的值
      while(left<right&&arr[left]<=key)
      {
          ++left;
      }
      //从右到左找到第一个小于基准值的值
      whlie(left<right&&arr[right]>=key)
      {
          --right;
      }
      //进行交换
      if(left<right)
      {
          swap(&arr[left],&arr[right]);
      }
  }

    //此时将left指向的值和最后一个元素(基准值)进行交换
    //最终left指向的值一定大于基准值
    
    swap(&arr[left],&arr[end-1]);
    return left;
}




//选择排序  打擂台思想，一个擂主，多个挑战者挑战，不符合要求的进行交换
//[0,bound)表示有序元素
//[bound,size)表示待排区间
//
//
//void selectsort(int arr[],size_t size)
//{
//    if(arr==NULL||size<=0)
//    {
//        return;
//    }
//    size bound = 0;
//    for(bound=0;bound<size;bound++)
//    {
//        size_t cur = bound+1;
//        for(;cur<size;cur++)
//        {
//            if(arr[bound]>arr[cur])//bound是擂主
//            {
//                swap(&arr[bound],&arr[cur]);
//            }
//        }
//    }
//}



//插入排序思路不再是交换值，而是搬运
//1.定义好边界，仍然用[0,bound)表示已排区间，[bound,size)表示未排区间
//2.保存bound所指向的值，一方搬运时被覆盖
//3.从后向前遍历，将bound指向的值，插入到已经排好的线性表中
//采用一边找，一般搬运的方法更加节省时间
//
void Insertsort(int arr[],size_t size)
{
    if(arr==NULL||size=0)
    {
        return;


}
