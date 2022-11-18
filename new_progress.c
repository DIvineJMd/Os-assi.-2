#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>
#include<sys/time.h>
#include<pthread.h>
#include<sched.h>
#include<unistd.h>
#include<math.h>
void *countA(void *p);
void *countB(void *p);
void *countC(void *p);
void Thread_A(){
    int s;
    struct sched_param prio;
    pthread_t thr;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    if(pthread_attr_setschedpolicy(&attr,SCHED_OTHER)!=0){fprintf(stderr,"Error in schedulling.");}
    if(pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED)!=0){fprintf(stderr,"Error in inherating");}
    if(pthread_attr_setschedparam(&attr,&prio)!=0){fprintf(stderr,"Error in setting priority.");}
    pthread_create(&thr,&attr,countA,NULL);
    pthread_join(thr,NULL);
    
}

//......................................................................
int main(int argc , char* argv[]){
    
    Thread_A();
    
}
//......................................................................
void *countA(void *p){
    long double c=0;
    printf("\nExecuting A\n");
    for(long double i=0;i<pow(2,32);i++){
        c+=1;
    }
    
}
void *countB(void *p){
    long double c=0;
    printf("\nExecuting B\n");
    for(long double i=0;i<pow(2,32);i++){
        c+=1;
    }
    
}
void *countC(void *p){
    long double c=0;
    printf("\nExecuting C\n");
    for(long double i=0;i<pow(2,32);i++){
        c+=1;
    }
    
}
