#ifndef  __SEQQUEUE_H__
#define  __SEQQUEUE_H__ 

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define SIZE 10

typedef int datatype;

typedef struct seqqueue
{
    datatype data[SIZE];
    int front,rear;
}seq_queue,*seq_pqueue;

extern void seqqueue_init(seq_pqueue *p);
extern bool seqqueue_isfull(seq_pqueue p);
extern bool seqqueue_isempty(seq_pqueue p);
extern void seqqueue_in(seq_pqueue p,datatype data);
extern void seqqueue_out(seq_pqueue p,datatype *data);
extern void seqqueue_trevel(seq_pqueue p);
extern int  bin_seq_search(seq_pqueue p,datatype data);
#endif
