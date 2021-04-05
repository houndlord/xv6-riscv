#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main()
{
    int p_1[2];
    int p_2[2];
    char buf[8];
    //int cur_pid;


    pipe(p_1);
    pipe(p_2);

    write(p_1[2], "1", 8);

    int pid = fork();
    if (pid == 0) {
        char buf[8];
        int cur_pid = getpid();
        read(p_1[1], buf, sizeof buf);
        printf(pid ":received ping");
        write(p_2[2], buf, sizeof buf);
        exit(0);
    }

    int par_cur_pid = getpid();

    read(p_2[1], buf, sizeof buf);
    printf(pid ":received pong");
    exit(0);
}