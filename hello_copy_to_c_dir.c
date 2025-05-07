#include <stdio.h>
#include <windows.h>

int main() {
    printf("Hello World\n");

    char currentPath[MAX_PATH];
    char destinationPath[MAX_PATH] = "C:\\HelloWorld.exe";

    // Get the current executable path
    if (GetModuleFileNameA(NULL, currentPath, MAX_PATH) == 0) {
        printf("Error getting module path: %d\n", GetLastError());
        return 1;
    }

    // Copy the file to C:\
    if (CopyFileA(currentPath, destinationPath, FALSE)) {
        printf("Copied to C:\\HelloWorld.exe successfully!\n");
    } else {
        printf("Failed to copy: %d\n", GetLastError());
    }

    return 0;
}