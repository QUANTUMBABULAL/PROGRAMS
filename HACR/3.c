#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char type[20];
    int port;
    char message[1001];
    int length;
} Message;

/*
 * Complete the 'mergeMessages' function below.
 *
 * The function returns the number of merged messages.
 *
 * Parameters:
 *  1. Message messages[]          (input array)
 *  2. int message_count           (number of messages)
 *  3. Message result[]            (store merged output here)
 *
 * Return:
 *  Number of merged messages.
 */

int mergeMessages(Message messages[],
                  int message_count,
                  Message result[])
{

    /*
     * Write your code here.
     *
     * Hint:
     * 1. Merge messages having same (type, port)
     * 2. Concatenate message strings
     * 3. Add lengths
     * 4. Sort result by type, then port
     * 5. Return number of merged messages
     */


}

int main()
{
    int n;

    scanf("%d",&n);

    Message messages[100];

    for(int i=0;i<n;i++)
    {
        scanf("%s",messages[i].type);
        scanf("%d",&messages[i].port);
        scanf("%s",messages[i].message);
        scanf("%d",&messages[i].length);
    }

    Message result[100];

    int count = mergeMessages(messages,n,result);

    for(int i=0;i<count;i++)
    {
        printf("%s %d %s %d\n",
               result[i].type,
               result[i].port,
               result[i].message,
               result[i].length);
    }

    return 0;
}