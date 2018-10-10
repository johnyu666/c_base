#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

//时间格式化输出
void printTime(struct tm* x){
    printf("%d-%d-%d %d:%d:%d\n",x->tm_year+1900,x->tm_mon+1,x->tm_mday,x->tm_hour,x->tm_min,x->tm_sec);
}
void printFileAllTime(time_t m ,time_t m1,time_t m2){
    struct tm *t;
    t=gmtime(&m);
    printf("最近一次访问：");
    printTime(t);
    t=gmtime(&m1);
    printf("内容最近一次修改:");
    printTime(t);
    t=gmtime(&m2);
    printf("权限的最近一次修改：");
    printTime(t);
}
int main(int argc,char* argv[]) {
    char* filename=argv[1];
    int fd=open(filename,O_RDWR);

    struct stat st;
    //系统调用，获取stat对象，描述出文件的全部情况
    fstat(fd,&st);
    //上一次被访问的时间
    time_t  m=st.st_atime;

    //内容上一次被修改的时间
    time_t m1=st.st_mtime;
    //权限上一次被修改的时间
    time_t m2=st.st_ctime;
    printFileAllTime(m,m1,m2);


    printf("文件大小是：%d\n",st.st_size);
    printf("文件的硬链接数是:%d\n",st.st_nlink);
    printf("用户id是：%d\n",st.st_uid);//可以使用id -a john查看
    printf("组id是：%d\n",st.st_gid);


    //这是一个短整类型的数据
    mode_t  mt=st.st_mode;
    if(S_ISDIR(mt)){
        printf("是目录\n");
    }
    if(S_ISREG(mt)){
        printf("是普通文件\n");
    }
    if(mt&S_IFREG){
        printf("是普通文件的第二种判定方法\n");
        //S_IFDIR,S_IFBLK,S_IFCHR,S_IFIFO
    }
    if(S_ISCHR(mt)){
        printf("是字符类设备文件\n");
    }

    if(S_ISBLK(mt)){
        printf("是块设备文件\n");
    }
    if(S_ISFIFO(mt)){
        printf("是通信管道文件\n");
    }
    //利用掩码判断，文件的权限
    if(S_IRUSR&mt){
        printf("具备用户读权限\n");
        //以下掩码，获取文件的其它权限情况
        //S_IRGRP,S_IROTH, S_IREAD
        //S_IWUSR,S_IWGRP,S_IWOTH,S_IWRITE
        //S_IXUSR,S_IXGRP,S_IXOTH,S_IEXEC
        //S_IRWXO,S_IRWXU,S_IRWXG
    }
    close(fd);
    return 0;
}