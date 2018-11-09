#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
static void sighandler(int signo){
    FILE* f;
    switch(signo){
        case(SIGINT):
            f = fopen("sigs.log","a");
            time_t timetime = time(NULL);
            fprintf(f,"NO %d! You SIGINTed yourself at %s",getpid(), ctime(&timetime));
            fclose(f);
            kill(getpid(),SIGKILL);
            break;
        case(SIGUSR1):
            printf("Your pparent's PPIDLING PPID is only %d, they should probably go back to school!\n",getppid());
            break;
    }
}   
int main(){
    signal(SIGINT,sighandler);
    signal(SIGUSR1,sighandler);
    while(1){
        printf("Your PIDdling little PID is only %d, please stay in school\n",getpid());
        sleep(1);
    }
    return 0;
}
