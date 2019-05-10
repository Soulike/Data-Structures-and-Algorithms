#include <stdio.h>

void hanoiTower(int n, int x, int y, int z);

int main()
{
    hanoiTower(64, 1, 2, 3);
}

// n 个碟子从塔 x 上借助塔 z 移动到塔 y
void hanoiTower(int n, int x, int y, int z)
{
    if (n > 0)
    {
        hanoiTower(n - 1, x, z, y);
        printf("把塔 %d 最上面的碟移动到塔 %d 最上面\n", x, y);
        hanoiTower(n - 1, z, y, x);
    }
}