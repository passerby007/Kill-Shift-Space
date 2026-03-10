#include <Windows.h>
#include <TlHelp32.h>
#include <iostream>

#pragma comment(linker, "/subsystem:\"console\"")

int main()
{
    const wchar_t *targetName = L"kill-shift-space.exe";
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot == INVALID_HANDLE_VALUE)
    {
        std::cerr << "Failed to create process snapshot" << std::endl;
        return 1;
    }

    PROCESSENTRY32W entry = {};
    entry.dwSize = sizeof(entry);
    bool found = false;

    if (Process32FirstW(snapshot, &entry))
    {
        do
        {
            if (_wcsicmp(entry.szExeFile, targetName) == 0)
            {
                HANDLE process = OpenProcess(PROCESS_TERMINATE, FALSE, entry.th32ProcessID);
                if (process)
                {
                    if (TerminateProcess(process, 0))
                    {
                        std::cout << "Killed kill-shift-space.exe (PID: " << entry.th32ProcessID << ")" << std::endl;
                        found = true;
                    }
                    else
                    {
                        std::cerr << "Failed to terminate PID: " << entry.th32ProcessID << std::endl;
                    }
                    CloseHandle(process);
                }
                else
                {
                    std::cerr << "Failed to open PID: " << entry.th32ProcessID << " (need admin?)" << std::endl;
                }
            }
        } while (Process32NextW(snapshot, &entry));
    }

    CloseHandle(snapshot);

    if (!found)
        std::cout << "kill-shift-space.exe not found in process list" << std::endl;

    return 0;
}
