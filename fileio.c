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
//        arr[3][strlen(arr[3]) - 1] = '\0'; //������ ���� ���๮�ڰ� �ִ� ���� �� ��
        printf("%s ���� ���� ���Դϴ�.", arr[0]);
        sprintf(cmd_buff,"acrocmd.exe recover file --loc=%s --arc=%s --target=%s",arr[1], arr[2], arr[3]);
 //       printf("%s",cmd_buff);
        system(cmd_buff);
    }
    return 0;
    if(fp == NULL)
    {
        printf("������ �������� �ʽ��ϴ�. mk_list.exe ������� serverlist.txt ������ ������ �ּ���! \n");
        return 0;
    }
    if (argc >= 2 )
    {
        printf("�ɼǾ��� ����ϼ���.\n");
        return 0;
    }
    if (strcmp(argv[1], "/?") == 0)
    {
        printf("�� ��ɾ�� �ɼ� ���� ����մϴ�.\n");
        printf("���������� serverlist.txt�� �����մϴ�.\n");
        printf("serverlist.txt�� ������ TIB������ �ִ� ���丮, Archive �̸�, ������ ������ ��� ���丮 ������ �����մϴ�.\n");
        printf("C:\\TIB\\directory\n");
        printf("Archive_name\n");
        printf("D:\\Destination\\directory \n");
        return 0;
    }
    fclose(fp);
    return 0;
}
