# 实验一：完成分开编译

## ./lib/下的头文件：
//advance.h
//完成乘除运算
int multiply(int,int);
int divide (int,int);

//base.h
//完成加减运算
int add(int,int);
int subtract(int,int);

## ./下的c 文件
//advance.c
//实现include/advance.h中的函数

//base.c
//实现include/base.h中的函数

//main.c
//完成对base和advance的调用

## 要求：
1. 对advance.c和base.c进行单独编译，到lib下
2. 对lib下的.o文件进行归档，libmath.a
3. 对main.c进行编译和链接
4. 
