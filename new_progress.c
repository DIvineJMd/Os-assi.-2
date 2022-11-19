#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>
#include<pthread.h>
#include<unistd.h>
#include<math.h>
#define BILLION 1000000000L
#define NUM_THREAD 3
void *countA(void *p);
void *countB(void *p);
void *countC(void *p);
pthread_t thr[NUM_THREAD];
struct timespec s1, e1,s2,e2,s3,e3;
double accum;
void Thread_A(){
    int s,rc;
    struct sched_param prio;
    int policy=SCHED_OTHER;
    rc = pthread_setschedparam(thr[0], policy, &prio);
    printf("A->%d\n",rc);
    if( clock_gettime( CLOCK_REALTIME, &s1) == -1 ) {
        fprintf(stderr, "clock gettime" );
        exit( EXIT_FAILURE );
    }
    pthread_create(&thr[0],NULL,countA,NULL);
    
    
}
void Thread_B(){
     int s,rc;
    struct sched_param prio;
    int policy=SCHED_FIFO;
    rc = pthread_setschedparam(thr[1], policy, &prio);
    printf("B->%d\n",rc);
    if( clock_gettime( CLOCK_REALTIME, &s2) == -1 ) {
        fprintf(stderr, "clock gettime" );
        exit( EXIT_FAILURE );
    }
    pthread_create(&thr[1],NULL,countB,NULL);
   
}
void Thread_C(){
      int s,rc;
    struct sched_param prio;
    int policy=SCHED_RR;
    
    rc = pthread_setschedparam(thr[2], policy, &prio);
    printf("C->%d\n",rc);
    if( clock_gettime( CLOCK_REALTIME, &s3) == -1 ) {
        fprintf(stderr, "clock gettime" );
        exit( EXIT_FAILURE );
    }
    pthread_create(&thr[2],NULL,countC,NULL);
  
}
//......................................................................
int main(int argc , char* argv[]){
    double t1,t2,t3;
    Thread_A();
    pthread_join(thr[0],NULL);
    if( clock_gettime( CLOCK_REALTIME, &e1) == -1 ) {
    fprintf(stderr,"clock gettime" );
    exit( EXIT_FAILURE );}
    Thread_B();
    
    pthread_join(thr[1],NULL);
    if( clock_gettime( CLOCK_REALTIME, &e2) == -1 ) {
    fprintf(stderr,"clock gettime" );
    exit( EXIT_FAILURE );}
    Thread_C();
    pthread_join(thr[2],NULL);
    if( clock_gettime( CLOCK_REALTIME, &e3) == -1 ) {
    fprintf(stderr,"clock gettime" );
    exit( EXIT_FAILURE );}
    
    
     t1 = ( e1.tv_sec - s1.tv_sec ) + ( e1.tv_nsec - s1.tv_nsec )/ BILLION;
     t2 = ( e2.tv_sec - s2.tv_sec ) + ( e2.tv_nsec - s2.tv_nsec )/ BILLION;
     t3 = ( e3.tv_sec - s3.tv_sec ) + ( e3.tv_nsec - s3.tv_nsec )/ BILLION;
     printf("\n");
     int i[3]={t1,t2,t3};
     for(int j=0;j<3;j++){
        printf("%d ",i[j]);
        for(int k=i[j];k>0;k--){
            printf("*");
        }
        printf("\n");
     }
}
//......................................................................
void *countA(void *p){
    long double c=0;
    printf("\nExecuting A\n");
    for(long double i=0;i<pow(2,32);i++){
        c+=1;
    }
    
    
     printf("\ndone A\n");
}
void *countB(void *p){
    long double c=0;
    printf("\nExecuting B\n");
    for(long double i=0;i<pow(2,32);i++){
        c+=1;
    }
    
     printf("\ndone B\n");
}
void *countC(void *p){
    long double c=0;
    printf("\nExecuting C\n");
    for(long double i=0;i<pow(2,32);i++){
        c+=1;
    }
    
     printf("\ndone c\n");
    
}


