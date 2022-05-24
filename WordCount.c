#include <stdio.h>
const char* file_name;
const char* mode;
int flag=-1;
int main(char argc,char** argv){
    mode=argv[1];
    if(strcmp(mode,"-c")==0) flag=1;
    else if(strcmp(mode,"-w")==0) flag=0;
    file_name=argv[2];
    FILE* fp=fopen(file_name,"r");
    if(fp==NULL){
        printf("fail to open the file!\n");
        exit(1);
    }
    int charCount=0;
    int WordCount=0;
    char ch;
    while ((ch=fgetc(fp))!=EOF)
    {
        if(flag==1){
            charCount++;
        }
        else if(flag==0&&ch==' '||ch==','||ch=='.'){
            WordCount++;
        }
    }
    if(flag==1)  printf("字符数:%d\n",charCount);
    else if(flag==0) printf("单词数量: %d \n",WordCount);
    fclose(fp);
    return 0;
}

