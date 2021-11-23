#include "my_mat.h"
//MAX_INT is intentionaly not max value
#define MAX_INT 200000000

void is_connected(int matrice[N][N])
{
    if(get_shortest_route(matrice)>0)
    {
        printf("True\n");
        return;
    }
    printf("False\n");
}
void set_values(int matrice[N][N])
{   
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int input = 0;
            scanf("%d", &input);
            matrice[i][j] = input;
        }
    }
}

int get_shortest_route(int matrice[N][N])
{
    int vertex_i = 0; 
    int vertex_j = 0;
    scanf("%d",&vertex_i);
    scanf("%d",&vertex_j);
    int route_dist[N][N] = {{0}};
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            route_dist[i][j] = matrice[i][j];
            if(route_dist[i][j]==0&&i!=j)
            {
                route_dist[i][j] = MAX_INT;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if(route_dist[j][k]>route_dist[j][i]+route_dist[i][k])
                {
                    route_dist[j][k] = route_dist[j][i]+route_dist[i][k];
                }
            }
        }
    }
    if(route_dist[vertex_i][vertex_j]>=MAX_INT || route_dist[vertex_i][vertex_j]==0)
    {
        return -1;
    }
    return route_dist[vertex_i][vertex_j];
    
}
void print_mat(int matrice[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d,",matrice[i][j]);
        }
        printf("\n");
    }  
}