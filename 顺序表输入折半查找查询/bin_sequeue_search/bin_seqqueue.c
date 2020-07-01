#include"bin_seqqueue.h"

//初始化
void seqqueue_init(seq_pqueue *p)
{
    (*p) = (seq_pqueue)malloc(sizeof(seq_queue));
    (*p)->front = (*p)->rear = SIZE-1;
}
//判断队满
bool seqqueue_isfull(seq_pqueue p)
{
    if(p->front == (p->rear+1)%SIZE)
	return 1;
    else
	return 0;
}
//判断队空
bool seqqueue_isempty(seq_pqueue p)
{
    if(p->rear == p->front)
	return 1;
    else
	return 0;
}

//入队
void seqqueue_in(seq_pqueue p,datatype data)
{
    if(seqqueue_isfull(p))
    {
	printf("队已满\n");
	return ;
    }
    p->rear = (p->rear+1)%SIZE;
    p->data[p->rear] = data;
}
//出队
void seqqueue_out(seq_pqueue p,datatype *data)
{
    if(seqqueue_isempty(p))
    {
	printf("队为空\n");
	return ;
    }
    p->front = (p->front+1)%SIZE;
    *data =p->data[p->front];
}

//遍历队
void seqqueue_trevel(seq_pqueue p)
{

    int i;

    for(i = (p->front+1)%SIZE; i != (p->rear+1)%SIZE; i = (i+1)%SIZE){
	printf("%d\t",p->data[i]); 
    }
    printf("\n");
}
//折半查找
/*
    因为顺序表使用存储方式为：循环顺序表，所以增加对
    low和high的判断，保证high大于low，若处在首位中间，
    则将high视作超过SIZE的数值，进行循环。

 */
int bin_seq_search(seq_pqueue p,datatype data)
{
    int low,high,mid;

    low = (p->front+1) % SIZE;
    high = p->rear;
    if(low > high)
	high = high + SIZE;
    while(low <= high)
	{
	    mid = (low + high) / 2;
	    printf("mid-->%d",p->data[mid%SIZE]);
	    if(data == p->data[mid%SIZE])
		return mid%SIZE;
	    else if(data < p->data[mid % SIZE])
		high = mid - 1;
	    else
		low = mid + 1;
	}
	return -1; 
}
