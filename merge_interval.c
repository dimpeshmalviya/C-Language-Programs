#include <stdio.h>
#include <stdlib.h>

typedef struct {int s, e;} Interval;
int cmp(const void *a, const void *b){return ((Interval*)a)->s - ((Interval*)b)->s;}

int main(){
    Interval arr[]={{1,3},{2,6},{8,10},{15,18}};
    int n=sizeof(arr)/sizeof(arr[0]);
    qsort(arr,n,sizeof(Interval),cmp);
    Interval res[n]; int j=0; res[0]=arr[0];
    for(int i=1;i<n;i++)
        if(arr[i].s<=res[j].e) res[j].e=arr[i].e>res[j].e?arr[i].e:res[j].e;
        else res[++j]=arr[i];
    for(int i=0;i<=j;i++) printf("[%d,%d] ",res[i].s,res[i].e);
}