#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define EPS 1e-6

// 用于存储数值及其对应的表达式字符串
typedef struct {
    double val;
    char expr[100];
} Node;

// 递归函数：nodes 为当前剩余的数字集合，n 为集合大小
bool solve(Node nodes[], int n) {
    // 递归出口：只剩一个数时，判断是否为 24
    if (n == 1) {
        if (fabs(nodes[0].val - 24.0) < EPS) {
            printf("%s\n", nodes[0].expr);
            return true;
        }
        return false;
    }

    // 任选两个数 i 和 j
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;

            // 准备下一轮递归的集合
            Node next_nodes[4];
            int count = 0;
            for (int k = 0; k < n; k++) {
                if (k != i && k != j) {
                    next_nodes[count++] = nodes[k];
                }
            }

            // 尝试 4 种运算符
            for (int op = 0; op < 4; op++) {
                Node res;
                double a = nodes[i].val;
                double b = nodes[j].val;

                if (op == 0) { // 加法
                    res.val = a + b;
                    sprintf(res.expr, "(%s+%s)", nodes[i].expr, nodes[j].expr);
                } else if (op == 1) { // 减法
                    res.val = a - b;
                    sprintf(res.expr, "(%s-%s)", nodes[i].expr, nodes[j].expr);
                } else if (op == 2) { // 乘法
                    res.val = a * b;
                    sprintf(res.expr, "(%s*%s)", nodes[i].expr, nodes[j].expr);
                } else if (op == 3) { // 除法
                    if (fabs(b) < EPS) continue; // 除数不能为 0
                    res.val = a / b;
                    sprintf(res.expr, "(%s/%s)", nodes[i].expr, nodes[j].expr);
                }

                next_nodes[count] = res;
                if (solve(next_nodes, count + 1)) return true;
            }
        }
    }
    return false;
}

int main() {
    Node nodes[4];
    int val;

    // 输入 4 个整数
    for (int i = 0; i < 4; i++) {
        if (scanf("%d", &val) != 1) break;
        nodes[i].val = (double)val;
        sprintf(nodes[i].expr, "%d", val);
    }

    // 开始递归搜索
    if (!solve(nodes, 4)) {
        printf("-1\n");
    }

    return 0;
}