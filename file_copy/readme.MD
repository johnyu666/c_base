# 

## 标准IO中的文件操作（stdio.h）
### fopen
` File* fopen(const char* filename,const char* mode)`
+ File是一个结构体，在标准库被称为“流”
+ mode的选项：
    - r 只读(文件必须存在)
    - w 写入（覆盖，不存在则创建）
    - a 写入（追回，不存在则创建）
    - r+ 读写（从stream(File*)的头开始读写，原文件内容保留，文件必须存在）
    - w+ 读写（覆盖，不存在则创建）
    - a+ 读写（覆盖，不存在则创建）

### fclose
`int fclose(FILE *);`

### fread
`size_t  fread(void * buf, size_t size, size_t nitems, FILE * stream);`
+ 返回：读取到的字节数,结束时返回0
+ 参数：
    * buf 读入的缓存
    * 数据单元，一般用sizeof运算得到
    * 数据单元的数量
    * 流
### fwrite
`size_t fwrite(const void * buf, size_t size, size_t nitems, FILE *stream) `
+ 返回：写入的字节数
+ 参数：
    * buf 读入的缓存
    * 数据单元，一般用sizeof运算得到
    * 数据单元的数量
    * 流
### fflush
`int  fflush(FILE *);`
### fseek
`int fseek(FILE *, long, int mode);`
+ 参数：
    * mode: SEEK_SET 0文件开始的绝对位置
    * SEEK_CRU 相对于当前位置的相对位置
    * SEEK_END 相对于文件结尾的相对位置
### fgetc,getc,getchar

`int     fgetc(FILE *); `
* 读取一个字符
`int     getc(FILE *); `
* fgetc的别名
`int getchar()`
* 从标准输入中读一个字符

### fputc,putc,putchar
`int     fputc(int, FILE *);`
`int     putc(int, FILE *);`
* fputc的别名
`int     putchar(int);`
* 向标准输出输出一个字符
### fgets,gets
`char   *fgets(char * sp, int num, FILE * f);`
+ 作用：从流中读入字符串
+ 返回：
    1. 遇到换行符时，返回当前行字符串（换行符也会保留,并且末尾加上\0）
    2. 遇到文件结尾，返回NULL,并且ferror(File*)为1
    3. 当个数达到n-1个时，则返回读到的n-1个字符串，并且末尾加入\0
+ 参数：
    1. sp 读入数据的buf
    2. num,一次最多读入的字符数（注意，中文并不是一个字符）
    3. f stream
`char   *gets(char *);`
+ 作用：从标准输入流中，读取字符串
+ 返回：
    * 换行符之前的所有数据，不包括换行符
