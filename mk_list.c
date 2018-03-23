#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *fp_out;
    int i=0;
    int max_server=255;
    char buf_in[128];
    char *tmp;

    if (argc != 2)
    {
        printf("Usage : mk_list [���������̸�]\n");
        exit(0);
    }

    if (access(argv[1],F_OK) == 0)
    {
        printf("������ �����մϴ�. %s ������ ����س����ð�, ���� �ϼ���.\n", argv[1]);
        exit(0);
    }

    fp_out = fopen(argv[1],"w");
    if (fp_out == NULL)
    {
        perror("file open error 1 : ");
        exit(0);
    }

    while (1)
    {
        char aName[10] = "\n";

        printf("## %d ��° �����̸��� �Է��� �ּ���. :", i+1);
        fgets(buf_in, 128, stdin);
        if (!strcmp(buf_in, aName)) {
            break;
        } else {
        fprintf(fp_out,"### %s", buf_in);
        }
        printf("TIB������ ����� ��θ� �Է��� �ּ���. :");
        fgets(buf_in, 128, stdin);
        if (!strcmp(buf_in, aName)){
            printf("TIB������ ����� ��δ� ��Ȯ�� �ԷµǾ�� �մϴ�.");
            return 0;
        } else {
        fputs(buf_in, fp_out);
        }
        printf("Archive �̸��� �Է��� �ּ���. :");
        fgets(buf_in, 128, stdin);
        if (!strcmp(buf_in, aName)){
            printf("Archive �̸��� ��Ȯ�� �ԷµǾ�� �մϴ�.");
            return 0;
        } else {
        fputs(buf_in, fp_out);
        }
        printf("���� ������ ������ ����� ��θ� �Է��� �ּ��� :");
        fgets(buf_in, 128, stdin);
        if (!strcmp(buf_in, aName)){
            printf("���� ������ ������ ����� ��δ� ��Ȯ�� �ԷµǾ�� �մϴ�.");
            return 0;
        } else {
        fputs(buf_in, fp_out);
        }
        i ++;
    }
    fclose(fp_out);
    return 0;
}
