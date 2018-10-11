#include <stdio.h>
int main(){
    FILE* in=fopen("a.pptx","r");
    FILE* out=fopen("c.pptx","w");

    int c;
    //内部的缓存机制工作
    while ((c=getc(in))!=EOF){
        putc(c,out);
    }
    fclose(in);
    fclose(out);
    return 0;
}