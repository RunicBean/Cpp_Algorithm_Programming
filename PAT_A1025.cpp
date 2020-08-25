#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int locCount;

// 定义学生构造体
struct Student
{
    char regNum[15];
    int score;
    int locNum;
    int locRank;
    int finRank;
}students[100];

// 定义比较函数
// 如果分数相同，按序号排序
bool cmp(Student a, Student b){
    if (a.score == b.score){
        return strcmp(a.regNum, b.regNum) < 0;
    } else {
        return a.score > b.score;
    }
};

int main(){
    int stuNum = 0;
    // 输入考场数
    scanf("%d", &locCount);
    // 每个考场依次循环
    for (int i=1;i<=locCount;i++){
        int locStuNum;
        // 输入当前考场学生数
        scanf("%d", &locStuNum);
        // 每位考生数据输入
        for (int l=1;l<=locStuNum;l++){
            scanf("%s %d", students[stuNum].regNum, &students[stuNum].score);
            students[stuNum].locNum = i;
            stuNum++;
        }
        // 当前考场内学生排序
        sort(students + stuNum - locStuNum, students + stuNum, cmp);

        int locRank = 1;
        int counter = 0;
        for (int m=stuNum - locStuNum;m<stuNum;m++){
            if (m == stuNum - locStuNum){
                students[m].locRank = locRank;
            } else if (students[m].score == students[m-1].score){
                students[m].locRank = locRank;
            } else if (students[m].score != students[m-1].score){
                locRank = counter + 1;
                students[m].locRank = locRank;
            }
            counter++;
        }
    }

    int allNum = stuNum;
    printf("%d\n", allNum);
    // 全部考生排序
    sort(students, students + stuNum + 1, cmp);
    int totalRank = 1;
    for (int i=0;i<stuNum;i++){
        if (i==0){
            students[i].finRank = totalRank;
        } else if (students[i].score == students[i-1].score){
            students[i].finRank = totalRank;
        } else {
            totalRank = i + 1;
            students[i].finRank = totalRank;
        }
        printf("%s %d %d %d\n", \
        students[i].regNum, \
        students[i].finRank, \
        students[i].locNum, \
        students[i].locRank);
    }
    return 0;
}

