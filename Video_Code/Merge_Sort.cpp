#include<iostream>
using namespace std;
void merge(int *arr,int start,int mid,int end){
  int p1=start,p2=mid+1,i=0;
  int * temp=new int [end-start+1];
  while(p1<=mid&&p2<=end)
  {
    temp[i++]=arr[p1]<=arr[p2]?arr[p1++]:arr[p2++];
  }
  while(p1<=mid)
  {
    temp[i++]=arr[p1++];
  }
  while(p2<=end)
  {
    temp[i++]=arr[p2++];
  }
  for(i=0;i<end-start+1;i++)
  {
    arr[start+i]=temp[i];
  }
  delete [] temp;
}
void merge_sort(int * arr,int start,int end){
      if(start==end)
         return;
      int mid=start+((end-start)>>1);
      merge_sort(arr,start,mid);
      merge_sort(arr,mid+1,end);
      merge(arr,start,mid,end);
}
int main(){
     int len;
     cin>>len;
     int* arr=new int [len];
     for(int i=0;i<len;i++)
     {
        cin>>arr[i];
     }
     merge_sort(arr,0,len-1);
    for(int i=0;i<len;i++)
    {
        cout<<arr[i]<<' ';
    }
    delete [] arr;
    return 0;


}