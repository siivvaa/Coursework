#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
using namespace std;
  
int main()
{
    // ftok to generate unique key
    key_t key = ftok("shmfile",65);
  
    // shmget returns an identifier in shmid
    int shmid = shmget(key,1024,0666|IPC_CREAT);
  
    // shmat to attach to shared memory
    int arr[10];
    int *ap = arr;
    ap = (int *) shmat(shmid,(void*)0,0);
  
    cout<<"Enter array elements: ";
    for(int i=0;i<10;i++)
    {
        cin>>*(ap);
        ap++;
    } 
    
    cout<<"Data written!";
    //detach from shared memory 
    shmdt(ap);
  
    return 0;
}