#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char cmd_buff[300];
    char arr[4][128];
    FILE *fp = fopen("serverlist.txt","r");
    while(!feof(fp))
    {
        fgets(arr[0], 128, fp);
//        arr[0][strlen(arr[0]) - 1] = '\0';
        fgets(arr[1], 128, fp);
        arr[1][strlen(arr[1]) - 1] = '\0';
        fgets(arr[2], 128, fp);
        arr[2][strlen(arr[2]) - 1] = '\0';
        fgets(arr[3], 128, fp);
//        arr[3][strlen(arr[3]) - 1] = '\0'; //마지막 행이 개행문자가 있는 것이 더 편리
        printf("%s 서버 복구 중입니다.", arr[0]);
        sprintf(cmd_buff,"acrocmd.exe recover file --loc=%s --arc=%s --target=%s",arr[1], arr[2], arr[3]);
 //       printf("%s",cmd_buff);
        system(cmd_buff);
    }
    return 0;
    if(fp == NULL)
    {
        printf("파일이 존재하지 않습니다. mk_list.exe 명령으로 serverlist.txt 파일을 생성해 주세요! \n");
        return 0;
    }
    if (argc >= 2 )
    {
        printf("옵션없이 사용하세요.\n");
        return 0;
    }
    if (strcmp(argv[1], "/?") == 0)
    {
        printf("이 명령어는 옵션 없이 사용합니다.\n");
        printf("설정파일은 serverlist.txt에 저장합니다.\n");
        printf("serverlist.txt의 내용은 TIB파일이 있는 디렉토리, Archive 이름, 파일을 저장할 대상 디렉토리 순으로 저장합니다.\n");
        printf("C:\\TIB\\directory\n");
        printf("Archive_name\n");
        printf("D:\\Destination\\directory \n");
        return 0;
    }
    fclose(fp);
    return 0;
}
