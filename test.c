#include <stdio.h>

#define MAX 100

int queue[MAX];
int rear = -1;

void add_element(int data)
{
    if (rear == MAX - 1)
    {
        printf("Queue is full. Cannot add more elements.\n");
        return;
    }
    queue[++rear] = data;
}

void remove_element(int position)
{
    if (position < 0 || position > rear)
    {
        printf("Invalid position.\n");
        return;
    }
    for (int i = position; i < rear; i++)
    {
        queue[i] = queue[i + 1];
    }
    rear--;
}

void find_element(int data)
{
    for (int i = 0; i <= rear; i++)
    {
        if (queue[i] == data)
        {
            printf("yes %d is present in the list\n", queue[i]);
            return;
        }
    }
    printf("Element %d not found in the queue.\n", data);
}

void print_queue()
{
    if (rear == -1)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    for (int i = 0; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    int x = 0, num = 0;
    printf("Enter the number of element want to insert in the queue\n ---->>Warning MSG !!!! Buffer size is 100 <----\n ");
    scanf("%d", &x);
    for (int i = 0; i < x; i++)
    {
        printf("Enter the number want to insert in queue \n");
        scanf("%d", &num);
        add_element(num);
    }
    

    print_queue();

    int X=0;
    printf("which position element want to remove from the list\n");
    scanf("%d",&X);
    remove_element(X-1);
    print_queue();
    
    printf("enter the element want to find in the queue\n");
    int find=0;
    scanf("%d",&find);
    find_element(find);
    print_queue();

    return 0;
}