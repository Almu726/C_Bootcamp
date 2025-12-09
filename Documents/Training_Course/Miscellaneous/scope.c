#include <stdio.h> 

int main(void)
{
    int i;
    int j = 0;
    for( i = 0; i < 10; i++ )
    {
        j=0;
        for( j = 10; j > 0; j-- )
        {
            if( i > j )
            {
                printf("Variable i (%d) is bigger than j (%d) \n", i, j);
                break;
            }
        }
    }
    
    /* print result */
    printf("Last values: i (%d), j (%d) \n", i, j);
    
    return 0;
}