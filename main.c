#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>
#include <windows.h> // Include for Windows API functions

int main() {
    struct stat attr;
    char str[100] = "";  // Initialize to empty string to avoid uninitialized memory comparison

    while (1) {
        if (stat("content.md", &attr) == -1) {
            perror("Error in stat");
            return 1;
        }

        char *ctime_str = ctime(&attr.st_mtime);

        if (strcmp(ctime_str, str) != 0) {
            system("start python refresh.py"); // Execute the Python script using system call
            strcpy(str, ctime_str);
        }
        Sleep(5000); // Sleep for 5000 milliseconds (5 seconds)
    }
    return 0;
}
