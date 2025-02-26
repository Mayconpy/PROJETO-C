#include <stdio.h>
#include <conio.h>
#include <windows.h>


void chartowchar(const char *srcm, wchar_t *dest, int destsize){
    MultiByteToWideChar(CP_ACP,0,srcm,-1,dest,destsize);
}

void disable_Services(const char *serviceName){
    wchar_t servicenamew[256];
    chartowchar(serviceName,servicenamew,256);

    //abre o gerenciador de controle de serviços com acesso total
    SC_HANDLE hSCMANAGEr = OpenSCManager(NULL,NULL,SC_MANAGER_ALL_ACCESS);
    if(!hSCMANAGEr){
        printf("error ao abrir o arquivo %ld",GetLastError());
        return;
    }

    SC_HANDLE Hservice  = OpenService(hSCMANAGEr,servicenamew,SERVICE_CHANGE_CONFIG| SERVICE_STOP);
    


}


void activate_game_mode();

void disable_background_apps();

void change_power_plan();


void disable_windows_defender();


void delete_temp_paste();


