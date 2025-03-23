#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

int main() {
    int a;
    pid_t p;
    struct stat statbuf;

    while (true) {
        printf("System calls\n");
        printf("Menu\n");
        printf("1. fork\n");
        printf("2. exec\n");
        printf("3. get pid\n");
        printf("4. wait\n");
        printf("5. close\n");
        printf("6. stat\n");
        printf("7. opendir\n");
        printf("8. readdir\n");
        printf("9. exit\n");
        scanf("%d", &a);

        if (a == 1) {
            printf("A child process is created\n");
            p = fork();
            if (p != 0) {
                printf("Pid of currently executing process %d\n", getpid());
            } else {
                printf("FAILURE in creating a child process\n");
            }
        }
        else if (a == 2) {
            p = fork();
            if (p == 0) {
                char *args[] = {"/bin/ls", "-l", NULL};
                execvp(args[0], args);
                perror("Exec failed");
                exit(1);
            }
            else if (p > 0) {
                wait(NULL);
            }
            else {
                printf("Fork failed\n");
            }
        }
        else if (a == 3) {
            printf("PID of currently executing process %d\n", getpid());
        }
        else if (a == 4) {
            wait(NULL);
            printf("Child process has been terminated\n");
        }
        else if (a == 5) {
            int fd = open("testfile.txt", O_CREAT | O_RDWR, 0666);
            if (fd == -1) {
                perror("Failed to open file");
            } else {
                printf("File opened. Now closing the file descriptor.\n");
                close(fd);
                printf("File descriptor closed.\n");
            }
        }
        else if (a == 6) {
            if (stat("testfile.txt", &statbuf) == 0) {
                printf("File Size: %ld bytes\n", statbuf.st_size);
            } else {
                perror("Failed to get file stats");
            }
        }
        else if (a == 7) {
            DIR *dir = opendir(".");
            if (dir == NULL) {
                perror("Failed to open directory");
            } else {
                printf("Directory opened successfully.\n");
                closedir(dir);
            }
        }
        else if (a == 8) {
            DIR *dir = opendir(".");
            struct dirent *entry;
            if (dir == NULL) {
                perror("Failed to open directory");
            } else {
                printf("Directory contents:\n");
                while ((entry = readdir(dir)) != NULL) {
                    printf("%s\n", entry->d_name);
                }
                closedir(dir);
            }
        }
        else if (a == 9) {
            printf("Exiting......\n");
            exit(0);
        }
        else {
            printf("Invalid option\n");
        }
    }

    return 0;
}

