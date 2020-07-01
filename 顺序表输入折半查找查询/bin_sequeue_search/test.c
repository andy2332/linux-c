/*
    使用顺序表存储数据。
    存储完SIZE-1个数据后
    使用折半查找，因为存储结构为循环存储。
    影响头尾大小的判断，将超出最高位的数值视为，SIZE+front.
    2020.6.21
    gcz
 */


#include"bin_seqqueue.h"

int main(void)
{
    seq_pqueue s;
    datatype data;
    int rat,i;
    seqqueue_init(&s);
    /*
    注意使用循环队列解决假溢出情况时.
    存储存储的数据个数为 SIAE-1 个。
    同时注意：
    front 代表第一个数据前一个位置下标。
    rear代表尾数据。    
    */
    printf("输入%d个整数:\n",SIZE-1);
    for(i = 0;i < 27;i++ )
    {
	rat = scanf("%d",&data);
	while(getchar() != '\n');
	if(rat)
	{
	    seqqueue_in(s,data);
	    seqqueue_trevel(s);
	}
	else
	{
	    seqqueue_out(s,&data);  
	    seqqueue_trevel(s);
	}
     }
    int t;
    while(1)
    {
	printf("请输入要查询的是数据：");
	scanf("%d",&data);
	while(getchar() != '\n');
	t = bin_seq_search(s,data);
	if(t == -1)
	{
	    printf("无数据!\n");
	}
	else
	    printf("查询结果为：%d\n",s->data[t]);
    }	
    return 0;
}
