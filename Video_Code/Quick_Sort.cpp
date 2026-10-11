#include<iostream>
#include<cstdio>
#include<ctime>
using namespace std;
void swap(int *arr,int i,int j)
{
      int temp=arr[i];
      arr[i]=arr[j];
      arr[j]=temp;
}
void partition(int *arr,int start,int end,int &b1,int &b2)
{
     int p1=start-1,p2=end;
      while(start<p2)
      {
         if(arr[start]<arr[end])
        swap(arr,++p1,start++);
        else if(arr[start]>arr[end])
         swap(arr,--p2,start);
         else 
         start++;
      }
     swap(arr,p2,end);
     b1=p1;
     b2=p2+1;
}
void quickSort(int* arr,int L,int R){
   if(L>=R ){
    return;
}
       swap(arr,rand()%(R-L+1)+L,R);
       int p1,p2;
       partition(arr,L,R,p1,p2);
       quickSort(arr,L,p1);
       quickSort(arr,p2,R);
}
int main(){
    srand((unsigned)time(NULL));
   int end,start=0;
   cin>>end;
    int* arr=new int[end];
   for(int i=0;i<end;i++)
      cin>>arr[i];
    quickSort(arr,start,end-1);
    for(int i=0;i<end;i++)
    cout<<arr[i]<<' ';
    delete[] arr;
    return 0;
}