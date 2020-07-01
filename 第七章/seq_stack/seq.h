#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#define MAXSIZE 100

typedef int typedata;//将此处更改为要保存数据的结构体类型，可在不同数据间通用

typedef struct seq
{
    typedata data[MAXSIZE];//保存数据的数组
    int front;//保存栈顶数的下标
}se,*sep;//se为结构体，sep为结构体指针。
extern int seq_inis(sep *p);
extern int seq_in(sep p,typedata data);
extern int seq_out(sep p,typedata *data);
extern bool seq_is_empty(sep p);
extern bool seq_is_full(sep p);

