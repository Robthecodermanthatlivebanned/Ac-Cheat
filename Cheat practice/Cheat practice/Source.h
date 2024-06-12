#ifndef Source_H_INCLUDED
#define Source_H_INCLUDED



#include "includes.h"
#include "mem.h"
DWORD pID(void) //retrives process ID
{
    // Getting process ID and base address
    DWORD pID = GetProcessID(L"ac_client.exe");
    if (pID == 0) {
        // Handle error when process ID is not found
        MessageBox(NULL, L"Failed to find process ID", L"Error", MB_ICONERROR);
        return NULL;
    }
	return pID;
}
DWORD LocalPlayerPointer (HANDLE handle, DWORD baseModule)//gets local player pointer
{
    DWORD LocalPlayerPtr;
    ReadProcessMemory(handle, (LPCVOID)(baseModule + 0x0195404), &LocalPlayerPtr, sizeof(LocalPlayerPtr), nullptr);
    if (LocalPlayerPtr == 0) 
    {
        // Handle error when failed to read local player pointer
        MessageBox(NULL, L"Failed to read local player pointer", L"Error", MB_ICONERROR);
        CloseHandle(handle);
    }
	return LocalPlayerPtr;
}
void modifyPlayerAttributes(HANDLE handle, DWORD baseModule, DWORD LocalPlayerPtr)// Modify player attributes 
{
    int value = 1337;
    
    WriteProcessMemory(handle, (LPVOID)(LocalPlayerPtr + offsets::RifleAmmoactive), &value, sizeof(value), nullptr);
    WriteProcessMemory(handle, (LPVOID)(LocalPlayerPtr + offsets::armour), &value, sizeof(value), nullptr);
    WriteProcessMemory(handle, (LPVOID)(LocalPlayerPtr + offsets::health), &value, sizeof(value), nullptr);
    return;
}
void namechanger(HANDLE handle, DWORD baseModule, DWORD LocalPlayerPtr)// randomized namechanger
{
    int output;
    int test = std::rand();
    WriteProcessMemory(handle, (LPVOID)(LocalPlayerPtr + offsets::playername), &test, sizeof(test), nullptr);
    ReadProcessMemory(handle, (LPCVOID)(LocalPlayerPtr + offsets::playername), &output, sizeof(output), nullptr);
    return;
}
void rapidfire(HANDLE handle, DWORD baseModule, DWORD LocalPlayerPtr)// simple rapid fire
{
    int shootspeed = -1000; // should change speed way tooooo fast
    WriteProcessMemory(handle, (LPVOID)(LocalPlayerPtr + offsets::rshootspeed), &shootspeed, sizeof(shootspeed), nullptr);
    return;
} 
int PlayerCount(HANDLE handle, DWORD baseModule, DWORD LocalPlayerPtr)// func gets player count 
{
    int playercount;
    ReadProcessMemory(handle, (LPCVOID)(baseModule + 0x18AC0C), &playercount, sizeof(playercount), nullptr);
    if (playercount == NULL) {
        // Handle error when failed to read local player pointer
        MessageBox(NULL, L"Failed to read player quantity pointer", L"Error", MB_ICONERROR);
        CloseHandle(handle);
    }
	return playercount;
} 
#endif