#include <bits/stdc++.h>
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
    int *ap = (int *) shmat(shmid,(void*)0,0);
  
    int sum = 0;

    for(int i=0;i<10;i++)
    {
        sum+= *(ap);
        ap++;
    }

    cout<<"Sum of all elements = "<<sum;
    //detach from shared memory 
    shmdt(ap);
    
    // destroy the shared memory
    shmctl(shmid,IPC_RMID,NULL);
     
    return 0;
}