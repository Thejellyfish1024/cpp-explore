#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int used[7][7] = {0}; 
    int count = 0;

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x > y) {
            int temp = x;
            x = y;
            y = temp;
        }
        if (!used[x][y]) {
            used[x][y] = 1;
            count++;
        }
    }

    printf("%d\n", count);
    return 0;
}
