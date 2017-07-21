/*use_q.c--测试Queue接口的驱动程序*/
#include<stdio.h>
#include"queue.h"

int main()
{
    Queue line;
    Item temp;
    char ch;

    InitializeTheQueue(&line);
    puts("Test the Queue interface.");
    puts("Type a to add a value.   Type d to delete a value");
    puts("Type q to quit!");
    while((ch = getchar()) != 'q')
    {
        if(ch != 'a' && ch != 'd')
            continue;
        if(ch == 'a')
        {
            printf("Integer to add:");
            scanf("%d",&temp);
            if(!QueueIsFull(&line))
            {
                printf("Putting %d into queue\n",temp);
                Enqueue(temp,&line);
            }
            else
                puts("The queue is full!");
        }
        else
        {
            if(QueueIsEmpty(&line))
                puts("Nothing to delete!");
            else
            {
                DeQueue(&temp,&line);
                printf("Removing %d from queue\n",temp);
            }
        }

        printf("%d items in queue\n",QueueItemCount(&line));
        puts("Type a to add,d to delete,q tu quit:");
    }

    EmptyQueue(&line);
    puts("::::Bye::::");

    return 0;
}