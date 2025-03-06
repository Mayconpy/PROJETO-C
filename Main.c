#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "WinDefender_disable.h"
#include "advanced_optmization.h"
#include <shellapi.h>





void colortext(int color){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);}


void Servicestodisable(){
    colortext(4);
    printf("Please run this program as administrator.\n\n");

    colortext(2);
    printf("all services that will be disabled\n\nServices that can be safely disabled\n\n");
    colortext(1);
    printf("1-Fax: If you do not use fax sending/receiving.\n");
    printf("2-Print Spooler: if you dont't use printers.\n");
    printf("3-Windows Insider Service: if you are not part of the windows insider program.\n");
    printf("4-Remote Registry: prevents remote changes to the Windows registry.\n");
    printf("5-Secondary Logon: if you don't use run as another user\n");
    printf("6-Smart Card: if you don't use smart cards\n");
    printf("7-Downloaded Maps Manager: If you don't use offline maps.\n");
    printf("8-Touch Keyboard and Handwriting Panel Service: If you don't use touch screen or handwriting.\n");
    printf("------------------------------------------------------------------------------------------------------------\n");

    colortext(4);
    printf("Optional services (disabling may improve performance, but may affect functionality)\n\n");
    colortext(3);
    printf("1-Windows Search: Disables file indexing, useful if you don't use Windows search often.\n");
    printf("2-SysMain: It can be disabled on SSDs, as it does not improve performance as much..\n");
    printf("3-Windows Error Reporting Service: If you don't want Windows to send error reports to Microsoft.\n");
    printf("4-Windows Update: If you want to disable automatic updates\n");
    printf("5-Connected User Experiences and Telemetry: Reduces data collection by Microsoft.\n");
    printf("----------------------------------------------------------------------------------------------------------------\n");
    colortext(7);
}

void executeoptmization(){
    
    char *services[] ={"Fax","Spooler","wisvc","RemoteRegistry","seclogon","SCardSvr","MapsBroker","TabletInputService","WSearch","SysMain","WerSvc","wuauserv","DiagTrack","WinDefend"};
    int num =  sizeof(services) / sizeof(services[0]);


    for (int i =0;i < num; i++ ){
        disable_Services(services[i]);
    }
}


int main(){

    Servicestodisable();
    int choice;
    printf("choice 1 to disable mentioned services or 2 to disable Windows Defender permanently: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1: executeoptmization();break;
    case 2: disable_windows_defender();break;
    }

    
}


