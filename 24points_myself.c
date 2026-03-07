#include <stdio.h>
#include <math.h>

// 定义一个微小的误差值，用于浮点数比较
#define EPS 1e-6

// 计算函数：根据运算符代号计算结果
double calc(double a, double b, int op) {
    if (op == 0) return a + b;
    if (op == 1) return a - b;
    if (op == 2) return a * b;
    if (op == 3) return (fabs(b) > EPS) ? a / b : -1e9; // 避免除以0
    return -1e9;
}

// 运算符代号转字符
char op_char(int op) {
    char s[] = "+-*/";
    return s[op];
}

int main() {
    int nums[4];
    for (int i = 0; i < 4; i++) scanf("%d", &nums[i]);

    // 1. 第一层大循环：对 4 个数字进行全排列 (4! = 24种可能)
    // 这里简单处理，嵌套四个循环代表四个位置放哪个数
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (j == i) continue;
            for (int k = 0; k < 4; k++) {
                if (k == i || k == j) continue;
                for (int l = 0; l < 4; l++) {
                    if (l == i || l == j || l == k) continue;

                    // 2. 第二层大循环：尝试 3 个位置的所有运算符组合 (4^3 = 64种)
                    for (int op1 = 0; op1 < 4; op1++) {
                        for (int op2 = 0; op2 < 4; op2++) {
                            for (int op3 = 0; op3 < 4; op3++) {
                                
                                // 计算形式: ((A op1 B) op2 C) op3 D
                                double r1 = calc(nums[i], nums[j], op1);
                                double r2 = calc(r1, nums[k], op2);
                                double r3 = calc(r2, nums[l], op3);

                                if (fabs(r3 - 24.0) < EPS) {
                                    printf("((%d%c%d)%c%d)%c%d\n", 
                                            nums[i], op_char(op1), nums[j], 
                                            op_char(op2), nums[k], 
                                            op_char(op3), nums[l]);
                                    return 0; // 找到一种方案就退出
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    printf("-1\n");
    return 0;
}