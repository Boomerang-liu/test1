#include <stdio.h>
#include <string.h>

// 定义方向数组：马走的8个方向 + 原点
const int fx[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
const int fy[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};

int main() {
    int bx, by, mx, my;
    // 读取棋盘终点坐标(bx,by)和马的位置(mx,my)
    scanf("%d%d%d%d", &bx, &by, &mx, &my);

    // 用long long防止结果溢出
    long long dp[40][40];
    // 标记马的控制点，1表示不可走
    int block[40][40] = {0};

    // 初始化马的位置为障碍
    block[mx][my] = 1;
    // 标记马能跳到的8个位置为障碍
    for (int i = 1; i <= 8; i++) {
        int nx = mx + fx[i];
        int ny = my + fy[i];
        // 确保坐标在棋盘范围内
        if (nx >= 0 && nx <= bx && ny >= 0 && ny <= by) {
            block[nx][ny] = 1;
        }
    }

    // 初始化dp数组，起点(0,0)方案数为1（也可以从(1,1)开始，看题目定义）
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    // 动态规划递推：只能向右或向下走
    for (int i = 0; i <= bx; i++) {
        for (int j = 0; j <= by; j++) {
            // 如果当前位置是障碍，方案数为0
            if (block[i][j]) {
                dp[i][j] = 0;
                continue;
            }
            // 起点已经初始化，跳过
            if (i == 0 && j == 0) continue;

            // 状态转移：从上方或左方走来
            if (i > 0) dp[i][j] += dp[i-1][j];
            if (j > 0) dp[i][j] += dp[i][j-1];
        }
    }

    // 输出终点的方案数
    printf("%lld\n", dp[bx][by]);
    return 0;
}