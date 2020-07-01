#include"seq.h"
//初始化栈
int seq_inis(sep *p)
{
    //申请空间
    (*p) = (sep)malloc(sizeof(se));
    //申请空间失败
    if((*p) == NULL)
    {
	perror("malloc");
	exit(1);
    }
    //初始化栈
    (*p)->front = -1;
    return 0;
}
//入栈
int seq_in(sep p,typedata data)
{
    if(seq_is_full(p))
    {
	printf("seq is full\n");
	return 1;
    }
    p->front++;
    p->data[p->front] = data;
    return 0;
}
//出栈  需要传出数据所以要对传如data地址
int seq_out(sep p,typedata *data)
{
    if(seq_is_empty(p))
    {
	printf("seq is septy\n");
	return 1;
    }
    (*data) = p->data[p->front];
    p->front--;
    return 0;
}
//判断栈是否为空
bool seq_is_empty(sep p)
{
    if(p->front == -1)
	return 1;
    else
	return 0;

}
//判断栈是否已满
bool seq_is_full(sep p)
{
    if(p->front == MAXSIZE)
	return 1;
    else
	return 0;
}
//遍历栈内数据从栈底到栈顶
