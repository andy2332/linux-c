#include"seq.h"

int main(void)
{
    sep h;
    seq_inis(&h);//因为要更改h本身内容,所以必须传h地址过去
    
    int a,b;

    for(a = 0;a < 10;a++)
    {
	seq_in(h,a);
    }
    for(a = 0;a<10;a++)
    {
	seq_out(h,&b);
	printf("%d\n",b);
    }
    return 0;
}
