#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define QUESTION_NUM 5   //一次出5道题

//几何题目结构体
typedef struct {
    int type;   //1圆，2矩形，3三角形
    double a,b; //圆:a半径；矩形:a长b宽；三角形:a底b高
    double answer; //正确答案(面积)
}Question;

//生成一道随机题目
void createQuestion(Question *q)
{
    q->type = rand()%3 + 1;
    if(q->type == 1){
        //圆 半径1~10
        q->a = (rand()%100)/10.0 + 1;
        q->answer = 3.14159 * q->a * q->a;
    }else if(q->type ==2){
        //矩形
        q->a = (rand()%100)/10.0 +1;
        q->b = (rand()%100)/10.0 +1;
        q->answer = q->a * q->b;
    }else{
        //三角形
        q->a = (rand()%100)/10.0 +1;
        q->b = (rand()%100)/10.0 +1;
        q->answer = 0.5 * q->a * q->b;
    }
}

//打印题目
void printQuestion(Question q)
{
    if(q.type ==1){
        printf("【圆】半径 = %.1lf，请计算圆的面积：\n",q.a);
    }else if(q.type ==2){
        printf("【矩形】长=%.1lf，宽=%.1lf，请计算矩形面积：\n",q.a,q.b);
    }else{
        printf("【三角形】底=%.1lf，高=%.1lf，请计算三角形面积：\n",q.a,q.b);
    }
}

int main()
{
    srand((unsigned int)time(NULL)); //设置随机种子
    Question q;
    double userInput;
    int score = 0;

    printf("=====几何图形题库系统=====\n");
    printf("本次一共%d道题目，请输入你的答案\n\n",QUESTION_NUM);

    for(int i=0;i<QUESTION_NUM;i++)
    {
        printf("第%d题：\n",i+1);
        createQuestion(&q);
        printQuestion(q);
        printf("你的答案：");
        scanf("%lf",&userInput);

        //允许小误差，浮点不能直接==比较
        if(abs(userInput - q.answer) < 0.1)
        {
            printf("✅回答正确！\n");
            score++;
        }
        else
        {
            printf("❌回答错误，正确答案：%.2lf\n",q.answer);
        }
        printf("----------------------\n");
    }

    printf("\n答题结束！总分：%d / %d\n",score,QUESTION_NUM);
    printf("正确率：%.1lf %% \n", 100.0*score / QUESTION_NUM);
    return 0;
}

