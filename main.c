#include "my_mat.h"

int main()
{
    char menu = 'A';
    int mat[10][10] = {{0}};
    while(menu!='D')
    {
        scanf("%c",&menu);
        if(menu=='A')
        {
            set_values(mat);
        }
        if(menu=='B')
        {
            is_connected(mat);
        }
        if(menu=='C')
        {
            printf("%d\n",get_shortest_route(mat));
        }
    }
    return 0;
}