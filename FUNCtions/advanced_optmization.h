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
#include <Windows.h>
#include <initguid.h>
#include <powrprof.h> //API windows





void chartowchar(const char *src, wchar_t *dest, int destsize){
    MultiByteToWideChar(CP_ACP,0,src,-1,dest,destsize);


    //function to convert char * in wchar_t
    // src str char * dest wchar_t

    //MultiByteToWideChar convert string char to wchar so that it is compatible with Windows functions



}

void disable_Services(const char *serviceName){
    wchar_t servicenamew[256];
    chartowchar(serviceName,servicenamew,256);

    //abre o gerenciador de controle de serviços com acesso total
    SC_HANDLE hSCMANAGEr = OpenSCManager(NULL,NULL,SC_MANAGER_ALL_ACCESS);
    // OpenSCManager Obtém um manipulador para o gerenciador de serviços.
    //NULL, NULL: Usa os valores padrão para conectar ao gerenciador de serviços local.
    //SC_MANAGER_ALL_ACCESS: Concede todas as permissões necessárias para modificar serviços.

    // Se hSCManager for NULL, significa que ocorreu um erro ao abrir o gerenciador:
    if(!hSCMANAGEr){
        printf("ERROR");
        return;
    }

    SC_HANDLE Hservice  = OpenServiceW(hSCMANAGEr,servicenamew,SERVICE_CHANGE_CONFIG | SERVICE_STOP);
    if(!Hservice){
        printf("ERROR");
        CloseServiceHandle(hSCMANAGEr);
        return;
    }

    if(!ChangeServiceConfig(Hservice,SERVICE_NO_CHANGE,SERVICE_DISABLED,SERVICE_NO_CHANGE,NULL,NULL,NULL,NULL,NULL,NULL,NULL)){
            printf("error");

        }
        else{
            printf("ok");
        }
    SERVICE_STATUS status;

    if(ControlService(Hservice,SERVICE_CONTROL_STOP,&status)){
        printf("serviço parado");
    }
    else{
        printf("falha");
    }


    CloseServiceHandle(Hservice);
    CloseServiceHandle(hSCMANAGEr);

}












void delete_temp_paste();


