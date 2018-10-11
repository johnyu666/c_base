//
// Created by johnyu on 2018/10/10.
//
#include <stdio.h>

int main() {
    char buf[128];
    //基于流标准IO方式的技术
    FILE *f = fopen("a.pptx", "r");
    FILE *f1 = fopen("b.pptx", "w");

    size_t t;
    while ((t = fread(buf, sizeof(char), 128, f)) != 0) {
        fwrite(buf, sizeof(char), t, f1);
    }
    //文件结束
    if(feof(f)){
        printf("文件结束！");
    }
    fclose(f);a
    fclose(f1);
    return 0;
}