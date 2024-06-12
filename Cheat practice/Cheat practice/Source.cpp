#include "Source.h"
bool namechangerT;
bool infiniteT;
bool rapidfireT;
int main() {

    std::cout << "UnoWare" << std::endl;
    std::cout << "Version: 0.1" << std::endl;
    std::cout << "credits: neonthefrog" << std::endl;
    // toggle for namechanger
    std::cout << "toggle name changer:  ";
    std::cin >> namechangerT;
    // toggle for infinite
    std::cout << "toggle infinte stuff:  ";
    std::cin >> infiniteT;
    // toggle for rapid fire
    std::cout << "toggle rapid fire:  ";
    std::cin >> rapidfireT;

    
    DWORD baseModule = GetModuleBaseAddress(pID(), L"ac_client.exe");
    if (baseModule == 0) {
        // Handle error when base module address is not found
        MessageBox(NULL, L"Failed to find base module address", L"Error", MB_ICONERROR);
        return 1;
    }

    // Opening process handle
    HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, NULL, pID());
    if (handle == NULL) {
        // Handle error when failed to open process
        MessageBox(NULL, L"Failed to open process", L"Error", MB_ICONERROR);
        return 1;
    }

    // Getting local player pointer
   DWORD LocalPlayerPtr = LocalPlayerPointer(handle, baseModule);



	while (true) // main cheat loop
    {
        if (namechangerT)
        {
            namechanger(handle, baseModule, LocalPlayerPtr); // namechanger | defined in source.h
        }

        if (infiniteT)
        {
            modifyPlayerAttributes( handle, baseModule, LocalPlayerPtr); // changes health, ammo, etc | defined in source.h
        }

        if (rapidfireT)
        {   
            rapidfire( handle, baseModule, LocalPlayerPtr); // rapidfire | defined in source.h
        }
        //std::cout << "loop competelted";
    }

    return 0;
}






/*

*/
