#include<stdio.h>
#include<windows.h>
int main()
{
    system("color 0c");
    float x, y, a;
    for (y = 1.4f; y > -1.4f;y-=0.1f)
    {
        for (x = -1.4f; x < 1.4f;x+=0.05f)
        {
            a = x * x + y * y - 1;
            putchar((a*a*a-x*x*y*y*y<0.0f)?'x':' ');
        }
        printf("\n");
        Sleep(100);
    }
    // printf("天天开心");
    return 0;
}