#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>

int mygetch();  // 无须回车，只要按键就会触发事件
void into(); //1. 程序入口，加载
void init(int status); //2. 初始2048主页 
void start(); // 进入游戏入口
void paint_start(int status); // 渲染进入入口界面
void about(); // 进入关于作者界面
void paint(int (*arr)[6]); // 渲染游戏界面
void generate(int (*arr)[6]); // 每移动一次，生成新的块
void left(int (*arr)[6]); // 向左
void right(int (*arr)[6]); // 向右
void top(int arr[6][6], int cols); // 向上
void bottom(int arr[6][6], int cols); // 向下
void level(); // 最高得分
void setStone(int arr[6][6]); // 是否设置石头
void stone_paint(int status);


char buf[11];  // 玩家姓名
int score = 0; // 玩家得分
time_t ts, te; // 计个时
int shi=0,fen=0,miao=0;

int arr[6][6] = {{0}}; // 2048棋盘

int mygetch()
{
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON|ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

void paint_start(int status)
{
    system("clear");
    printf("`==================================================`\n");
    printf("||                                                ||\n");
    printf("||                                                ||\n");
    printf("||                                                ||\n");
    printf("||         \033[41m      \033[0m  \033[42m      \033[0m  \033[43m  \033[0m  \033[43m  \033[0m  \033[44m      \033[0m         ||\n");
    printf("||             \033[41m  \033[0m  \033[42m  \033[0m  \033[42m  \033[0m  \033[43m  \033[0m  \033[43m  \033[0m  \033[44m  \033[0m  \033[44m  \033[0m         ||\n");     
    printf("||         \033[41m      \033[0m  \033[42m  \033[0m  \033[42m  \033[0m  \033[43m      \033[0m  \033[44m      \033[0m         ||\n");
    printf("||         \033[41m  \033[0m      \033[42m  \033[0m  \033[42m  \033[0m      \033[43m  \033[0m  \033[44m  \033[0m  \033[44m  \033[0m         ||\n");
    printf("||         \033[41m      \033[0m  \033[42m      \033[0m      \033[43m  \033[0m  \033[44m      \033[0m         ||\n");
    printf("||                                                ||\n");
    printf("||                                                ||\n");
    printf(">--------------------------------------------------<\n");
    printf("||                                                ||\n");
    if (status == 1)
    {
        printf("||                  \033[43m            \033[0m                  ||\n");
        printf("||                  \033[31;43m  开始游戏  \033[0m                  ||\n");
        printf("||                  \033[43m            \033[0m                  ||\n");
        printf("||                                                ||\n");
        printf("||                  \033[1;37;40m            \033[0m                  ||\n");
        printf("||                  \033[1;37;40m  设置石头  \033[0m                  ||\n");
        printf("||                  \033[1;37;40m            \033[0m                  ||\n");
        printf("||                                                ||\n");
        printf("||                  \033[1;37;40m            \033[0m                  ||\n");
        printf("||                  \033[1;37;40m  最高分者  \033[0m                  ||\n");
        printf("||                  \033[1;37;40m            \033[0m                  ||\n");
        printf("||                                                ||\n");
        printf("||                  \033[1;37;40m            \033[0m                  ||\n");
        printf("||                  \033[1;37;40m  关于作者  \033[0m                  ||\n");
        printf("||                  \033[1;37;40m            \033[0m                  ||\n");
    }
    if (status == 2)
    {
        printf("||                  \033[1;37;40m            \033[0m                  ||\n");
        printf("||                  \033[1;37;40m  开始游戏  \033[0m                  ||\n");
        printf("||                  \033[1;37;40m            \033[0m                  ||\n");
        printf("||                                                ||\n");
        printf("||                  \033[43m            \033[0m                  ||\n");
        printf("||                  \033[31;43m  设置石头  \033[0m                  ||\n");
        printf("||                  \033[43m            \033[0m                  ||\n");
        printf("||                                                ||\n");
        printf("||                  \033[1;37;40m            \033[0m                  ||\n");
        printf("||                  \033[1;37;40m  最高分者  \033[0m                  ||\n");
        printf("||                  \033[1;37;40m            \033[0m                  ||\n");
        printf("||                                                ||\n");
        printf("||                  \033[1;37;40m            \033[0m                  ||\n");
        printf("||                  \033[1;37;40m  关于作者  \033[0m                  ||\n");
        printf("||                  \033[1;37;40m            \033[0m                  ||\n");
    }
    if (status == 3)
    {
        printf("||                  \033[1;37;40m            \033[0m                  ||\n");
        printf("||                  \033[1;37;40m  开始游戏  \033[0m                  ||\n");
        printf("||                  \033[1;37;40m            \033[0m                  ||\n");
        printf("||                                                ||\n");
        printf("||                  \033[1;37;40m            \033[0m                  ||\n");
        printf("||                  \033[1;37;40m  设置石头  \033[0m                  ||\n");
        printf("||                  \033[1;37;40m            \033[0m                  ||\n");
        printf("||                                                ||\n");
        printf("||                  \033[43m            \033[0m                  ||\n");
        printf("||                  \033[31;43m  最高分者  \033[0m                  ||\n");
        printf("||                  \033[43m            \033[0m                  ||\n");
        printf("||                                                ||\n");
        printf("||                  \033[1;37;40m            \033[0m                  ||\n");
        printf("||                  \033[1;37;40m  关于作者  \033[0m                  ||\n");
        printf("||                  \033[1;37;40m            \033[0m                  ||\n");
    }
    if (status == 4)
    {
        printf("||                  \033[1;37;40m            \033[0m                  ||\n");
        printf("||                  \033[1;37;40m  开始游戏  \033[0m                  ||\n");
        printf("||                  \033[1;37;40m            \033[0m                  ||\n");
        printf("||                                                ||\n");
        printf("||                  \033[1;37;40m            \033[0m                  ||\n");
        printf("||                  \033[1;37;40m  设置石头  \033[0m                  ||\n");
        printf("||                  \033[1;37;40m            \033[0m                  ||\n");
        printf("||                                                ||\n");
        printf("||                  \033[1;37;40m            \033[0m                  ||\n");
        printf("||                  \033[1;37;40m  最高分者  \033[0m                  ||\n");
        printf("||                  \033[1;37;40m            \033[0m                  ||\n");
        printf("||                                                ||\n");
        printf("||                  \033[43m            \033[0m                  ||\n");
        printf("||                  \033[31;43m  关于作者  \033[0m                  ||\n");
        printf("||                  \033[43m            \033[0m                  ||\n");
    }
    printf("||                                                ||\n");
    printf("`==================================================`\n");
    printf("按Esc退出游戏\n");
}
void into()
{
    system("clear");
    srand(time(NULL));
    int i=0;
    int time = 0;
    while ( i<=100)
    {
        time = rand()%20000+10000;
        printf("\r加载中: %d%%", i); usleep(time); fflush(stdout);
        i ++;
    }
    system("clear");
    printf("请输入姓名：(注：最多10个字符，只能为英文和数字\n");
    fgets(buf, 11, stdin);
    i = 0;
    while (*(buf+i) != '\0')
    {
        if (*(buf+i) == '\n')
        {
            *(buf+i) = '\0';
        }
        i ++;
    }
    init(1);
}
void start()
{
    srand(time(NULL));
    int x, y;
    int sj_shu = 3; // 初始随机生成三个数
    while (sj_shu--)
    {
        x = rand() % 6;
        y = rand() % 6;
        while (arr[x][y] != 0) {
            x = rand() % 6;
            y = rand() % 6;
        }
        arr[x][y] = 2;
    }
    int rows, cols;
    int cmp[6][6];
    int ci, cj;
    paint(arr);
    int inp;
    int flag = 0;
    while (1)
    {
        inp = mygetch();
        for (ci=0; ci<6; ci++)
        {
            for (cj=0; cj<6; cj++)
            {
                cmp[ci][cj] = arr[ci][cj];
            }
        }
        switch(inp)
        {
            case 27:
                flag = 1;
                break;
            case 97: // 左
                for (rows=0; rows<6; rows++) 
                {
                    left(arr+rows);
                }
                paint(arr);
                if (memcmp(arr, cmp, sizeof(int)*36)!=0)
                {
                    generate(arr);
                }
                break;
            case 100: // 右
                for (rows=0; rows<6; rows++)
                {
                    right(arr+rows);
                }
                paint(arr);
                if (memcmp(arr, cmp, sizeof(int)*36)!=0)
                {
                    generate(arr);
                }
                break;
            case 119: // 上
                for (cols=0; cols<6; cols++)
                {
                    top(arr, cols);
                }
                paint(arr);
                if (memcmp(arr, cmp, sizeof(int)*36)!=0)
                {
                    generate(arr);
                }
                break;
            case 115: // 下
                for (cols=0; cols<6; cols++)
                {
                    bottom(arr, cols);
                }
                paint(arr);
                if (memcmp(arr, cmp, sizeof(int)*36)!=0)
                {
                    generate(arr);
                }
                break;
        }
        if (flag == 1)
        {
            break;
        }
    }
    init(1);
}
void setStone(int arr[6][6])
{
    int status=0;
    int key = 0;
    stone_paint(status);
    while ((key=mygetch()) != 10)
    {
        switch(key)
        {
            case 49: // 左
                status = 1;
                break;
            case 51: // 右
                status = 0;
                break;
        }
        stone_paint(status);
    }
    int i,j;
    // 重置数组
    score = 0;
    for (i=0; i<6; i++)
    {
        for (j=0; j<6; j++)
        {
            arr[i][j] = 0;
        }
    }
    srand(time(NULL));
    i = rand() % 6;
    j = rand() % 6;
    if(status == 1)
    {
        arr[i][j] = -3; // 为石头
    }
    init(2);
}
void stone_paint(int status)
{
    system("clear");
    printf("  是否设置石头\n");
    if (status == 1)
    {
        printf("\033[1;31;40m Y \033[0m   N \n");
    }
    else
    {
        printf(" Y   \033[1;31;40m N \033[0m\n");
    }
    printf("设置石头会导致难度加大喔~~~\n");
}
void level()
{
    system("clear");
    int i=0;
    FILE * p_r = fopen(".rank", "r");
    char name[11];
    char scores[100];
    int scoreNum = 0;
    fscanf(p_r, "%s%s", name, scores); // 读取数据
    i = 0;
    for (; i<strlen(scores); i++)
    {
        scoreNum = scoreNum*10+(scores[i]-48);
    }
    if (scoreNum >= score)
    {
        printf("   \033[1;31m最强王者\033[0m\n");
        printf("Player: %s, Score: %d\n", name, scoreNum);
    }
    else
    {
        FILE * p_w = fopen(".rank", "w");
        fprintf(p_w, "%s %d\n", buf, score);
        fclose(p_w);
    }
    fclose(p_r);
    printf("请按Esc返回\n");
    while (1) 
    {
        if (mygetch() == 27)
        {
            break;
        }
    }
    init(3);
}
void about()
{
    system("clear");
    printf("======================================\n");
    printf("||                                  ||\n");
    printf("||         \033[1;33m 版权所有       \033[0m         ||\n");
    printf("||         作者: \033[4m周宇涛\033[0m             ||\n");
    printf("||         时间: [2016/7/5]         ||\n");
    printf("||                                  ||\n");
    printf("======================================\n");
    printf("按Esc键退回\n");
    while (1)
    {
        if (mygetch() == 27)
        {
            break ;
        }
    }
    init(4);
}
void init(int status)
{
    int c;
    int flag = 0;
    time(&ts);
    paint_start(status);
    while (1)
    {
        c = mygetch();
        switch(c)
        {
            case 53:   // 向上 小键盘5号
                if (status > 1)
                {
                    status --;
                }
                paint_start(status);
                break;
            case 50:    // 向下 小键盘2号
                if (status < 4)
                {
                    status ++;
                }
                paint_start(status);
                break;
            case 10:
                if (status == 1)
                {
                    flag = 1;
                }
                if (status == 2)
                {
                    flag = 2;
                }
                if (status == 3)
                {
                    flag = 3;
                }
                if (status == 4)
                {
                    flag = 4;
                }
                break;
            case 27: // 退出游戏
                time(&te);
                miao = (int)(te - ts);
                if (miao >= 60)
                {
                    fen = miao / 60;
                    miao = miao % 60;
                    if (fen >=60)
                    {
                        shi = fen / 60;
                        fen = fen % 60;
                    }
                }
                printf("      耗时\033[1;32m%2d时:%2d分:%2d秒\033[0m\n", shi, fen, miao);
                exit(0);
        }
        if (flag >= 1)
        {
            break;
        }
    }
    if (flag == 1)
    {
        start(); // 开始游戏
    }
    if (flag == 2) // 设置石头
    {
        setStone(arr);
    }
    if (flag == 3) // 查看最高分
    {
        level();
    }
    if (flag == 4)
    {
        about(); // 关于作者
    }

}
void paint(int (*arr)[6])
{
    system("clear");
    int i, j;
    printf("Score: %d                    Player: %s\n", score, buf);
    for (i=0; i<6; i++)
    {
         for (j=0; j<6; j++)
         {
             if ((*(arr+i))[j] == 0)
             {
                 printf("\033[1;40m      \033[0m  ");
             }
             else if ((*(arr+i))[j] == -3)
             {
                 printf("\033[2;43m      \033[0m  ");
             }
             else
             {
                 printf("\033[44m      \033[0m  ");
             }
         }
         printf("\n");
         for (j=0; j<6; j++)
         {
             if ((*(arr+i))[j] == 0)
             {
                 printf("\033[1;40m      \033[0m  ");
             }
             else if ((*(arr+i))[j] == -3)
             {
                 printf("\033[2;43m      \033[0m  ");
             }
             else
             {
                 printf("\033[44m%6d\033[0m  ", (*(arr+i))[j]);
             }
         }
         printf("\n");
         for (j=0; j<6; j++)
         {
             if ((*(arr+i))[j] == 0)
             {
                 printf("\033[1;40m      \033[0m  ");
             }
             else if ((*(arr+i))[j] == -3)
             {
                 printf("\033[2;43m      \033[0m  ");
             }
             else
             {
                 printf("\033[44m      \033[0m  ");
             }
         }
         printf("\n\n");
    }
    printf("请按Esc退出\n");
}
void generate(int (*arr)[6])
{

    int x = rand() % 6;
    int y = rand() % 6;
    int addNum = 0;
    int sj = rand()%11+1; // 随即数 [1, 11]
    if (sj <= 7)
    {
        addNum = 2;
    }
    else if (sj <= 10)
    {
        addNum = 4;
    }
    else
    {
        addNum = 8;
    }
    while ((*(arr+x))[y] != 0)
    {
         x = rand() % 6;
         y = rand() % 6;
    }
    (*(arr+x))[y] = addNum;
    paint(arr);
}
void left(int (*arr)[6]) // 按左键，向左
{
    int i=0, j=0;
    int item = 0;
    int * p_arr = *arr;
    int *l, *r;
    while (i<6)
    {
        while (p_arr[i] == 0)
        {
            i ++;
            if (i>5) // 说明全为0，表明不需要变化
            {
                break;
            }
        }
        if (i >= 5)
        {
            break ;
        }
        l = p_arr + i;
        r = l + 1;
        j = i + 1;
        while (*r == 0)
        {
            r ++;
            j ++;
            if (j>5)
            {
                break ;
            }
        }
        if (*l == *r && j < 6)
        {
            score += *l;
            *l += *r;
            *r = 0;
        }
        i ++;
    }
    int tmp[6] = {0};
    for (i=0; i<6; i++)
    {
        if (p_arr[i] != 0)
        {
            tmp[item++] = p_arr[i];
        }
    }
    for (i=0; i<6; i++)
    {
        p_arr[i] = tmp[i];
    }
}
void right(int (*arr)[6]) // 按右键，向右
{
    int i=5, j=5;
    int item = 0;
    int * p_arr = *arr;
    int *l, *r;
    while (i>=0)
    {
        while (p_arr[i] == 0)
        {
            i --;
            if (i<0) // 说明全为0，表明不需要变化
            {
                break;
            }
        }
        if (i <= 0)
        {
            break ;
        }
        l = p_arr + i;
        r = l - 1;
        j = i - 1;
        while (*r == 0)
        {
            r --;
            j --;
            if (j<0)
            {
                break ;
            }
        }
        if (*l == *r && j >= 0)
        {
            score += *l;
            *l += *r;
            *r = 0;
        }
        i --;
    }
    int tmp[6] = {0};
    for (i=5; i>=0; i--)
    {
        if (p_arr[i] != 0)
        {
            tmp[item++] = p_arr[i];
        }
    }
    int k = 0;
    for (i=5; i>=0; i--)
    {
        p_arr[i] = tmp[k];
        k ++;
    }
}
void top(int arr[6][6], int cols) // 向上,行数不同，列数相同
{
    int *t, *b;
    int i=0, j=0;
    int item = 0;
    while (i <= 5)
    {
        while (*(*(arr+i)+cols) == 0)
        {
            i ++;
            if (i > 5)
            {
                break;
            }
        }
        if (i>=5)
        {
            break;
        }
        t = (*(arr+i)+cols);
        j = i+1;
        b = (*(arr+j)+cols);
        while (*b == 0)
        {
            j ++;
            b = (*(arr+j)+cols);
            if (j>5)
            {
                break;
            }
        }
        if (*t == *b && j<=5)
        {
            score += *t;
            *t += *b;
            *b = 0;
        }
        i ++;
    }
    int tmp[6] = {0};
    for (i=0; i<6; i++)
    {
        if (*(*(arr+i)+cols) != 0)
        {
            tmp[item ++] = *(*(arr+i)+cols);
        }
    }
    for (i=0; i<6; i++)
    {
        *(*(arr+i)+cols) = tmp[i];
    }
}
void bottom(int arr[6][6], int cols) // 向下,行数不同，列数相同
{
    int *t, *b;
    int i=5, j=5;
    int item = 0;
    while (i >= 0)
    {
        while (*(*(arr+i)+cols) == 0)
        {
            i --;
            if (i < 0)
            {
                break;
            }
        }
        if (i<=0)
        {
            break;
        }
        t = (*(arr+i)+cols);
        j = i-1;
        b = (*(arr+j)+cols);
        while (*b == 0)
        {
            j --;
            b = (*(arr+j)+cols);
            if (j<0)
            {
                break;
            }
        }
        if (*t == *b && j>=0)
        {
            score += *t;
            *t += *b;
            *b = 0;
        }
        i --;
    }
    int tmp[6] = {0};
    for (i=5; i>=0; i--)
    {
        if (*(*(arr+i)+cols) != 0)
        {
            tmp[item ++] = *(*(arr+i)+cols);
        }
    }
    int k=0;
    for (i=5; i>=0; i--)
    {
        *(*(arr+i)+cols) = tmp[k];
        k ++;
    }
}
int main( void )
{
    into();
    return 0;
}
