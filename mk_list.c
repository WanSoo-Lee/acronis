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
        printf("Usage : mk_list [저장파일이름]\n");
        exit(0);
    }

    if (access(argv[1],F_OK) == 0)
    {
        printf("파일이 존재합니다. %s 파일을 백업해놓으시고, 삭제 하세요.\n", argv[1]);
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

        printf("## %d 번째 서버이름을 입력해 주세요. :", i+1);
        fgets(buf_in, 128, stdin);
        if (!strcmp(buf_in, aName)) {
            break;
        } else {
        fprintf(fp_out,"### %s", buf_in);
        }
        printf("TIB파일이 저장될 경로를 입력해 주세요. :");
        fgets(buf_in, 128, stdin);
        if (!strcmp(buf_in, aName)){
            printf("TIB파일이 저장될 경로는 정확히 입력되어야 합니다.");
            return 0;
        } else {
        fputs(buf_in, fp_out);
        }
        printf("Archive 이름을 입력해 주세요. :");
        fgets(buf_in, 128, stdin);
        if (!strcmp(buf_in, aName)){
            printf("Archive 이름은 정확히 입력되어야 합니다.");
            return 0;
        } else {
        fputs(buf_in, fp_out);
        }
        printf("압축 해제될 파일이 저장될 경로를 입력해 주세요 :");
        fgets(buf_in, 128, stdin);
        if (!strcmp(buf_in, aName)){
            printf("압축 해제될 파일이 저장될 경로는 정확히 입력되어야 합니다.");
            return 0;
        } else {
        fputs(buf_in, fp_out);
        }
        i ++;
    }
    fclose(fp_out);
    return 0;
}
