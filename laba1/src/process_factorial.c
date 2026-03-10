#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

long long factorial(int n) {
    long long result = 1;
    for(int i = 1; i <= n; i++)
        result *= i;
    return result;
}

int main() {
    int fd[2];
    pipe(fd);
    pid_t pid = fork();

    if(pid == 0) {
        close(fd[0]);
        long long res = factorial(5);
        write(fd[1], &res, sizeof(res));
        close(fd[1]);
    } else {
        close(fd[1]);
        long long res;
        read(fd[0], &res, sizeof(res));
        printf("Factorial from child process = %lld\n", res);
        close(fd[0]);
        wait(NULL);
    }
    return 0;
}
