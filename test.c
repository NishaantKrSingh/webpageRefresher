#include <windows.h>
#include <stdio.h>

void ExecuteHiddenPythonScript() {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    si.dwFlags = STARTF_USESHOWWINDOW;  // Important to set this flag
    si.wShowWindow = SW_HIDE;           // Hide the window

    ZeroMemory(&pi, sizeof(pi));

    // Prepare the command line
    // You might need to specify the full path to the Python executable
    // and the script file depending on your environment
    char cmd[] = "python refresh.py";

    // Create the process
    if (!CreateProcess(NULL,   // No module name (use command line)
        cmd,                   // Command line
        NULL,                  // Process handle not inheritable
        NULL,                  // Thread handle not inheritable
        FALSE,                 // Set handle inheritance to FALSE
        0,                     // No creation flags
        NULL,                  // Use parent's environment block
        NULL,                  // Use parent's starting directory 
        &si,                   // Pointer to STARTUPINFO structure
        &pi)                   // Pointer to PROCESS_INFORMATION structure
       ) {
        printf("CreateProcess failed (%d).\n", GetLastError());
        return;
    }

    // Wait until child process exits.
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Close process and thread handles. 
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

int main() {
    ExecuteHiddenPythonScript();
    return 0;
}
