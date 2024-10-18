#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define X 120
#define csv_line 50

struct 
{
    int No;
    char Name[20];
    char sex[20];
    int age;
    int grade;
} stu[X];
 
void add()
{
    printf("请输入学生学号，姓名，性别，年龄，成绩\n");
    int i = 0;
    while (i<X)
    {
        if (stu[i].No == 0)
        {
            break;
        }
        i++;
    }
    scanf("%d,%s,%s,%d,%d", &stu[i].No, &stu[i].Name, &stu[i].sex, &stu[i].age, &stu[i].grade);
    stu_ui();
}

void print()
{
    if (stu[0].No == 0)
    {
        printf("没有学生信息\n");
        stu_ui();
    }
    printf("学号\t姓名\t性别\t年龄\t成绩\t");
    for (int i = 0; i < X; i++)
    {
        if (stu[i].No == 0)
        {
            break;
        }
        printf("%d\t%s\t%s\t%d\t%d\n", stu[i].No, stu[i].Name, stu[i].sex, stu[i].age, stu[i].grade);
        printf("\n");
    }
    stu_ui();
}

void Save()
{
    const char *filename = "student.csv";
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        perror("Error opening file \t");
        stu_ui();
    }
    fprintf(file, "学号，姓名，性别，年龄，成绩\n");
    for (int i = 0; i < X; i++)
    {
        if (stu[i].No == 0)
        {
            break;
        }
        fprintf(file, "%d,%s,%s,%d,%s\n", stu[i].No.stu[i].Name, stu[i].sex, stu[i].age, stu[i].grade);
    }
    fclose(file);
    printf("学生信息已保存到 %s\n", filename);
}

void parse_csv_line(char *line,char fields[][csv_line])
{
    int field_index = 0;
    char *token = strtok(line, ",");
    while (token != NULL)
    {
        strncpy(field[field_index], token, csv_line);
        field_index++;
        token = strtok(NULL, ",");
    }
} 

void Read()
{
    FILE *file = fopen("students.csv", "r");
    if (file == NULL)
    {
        perror("未找到文件");
        exit(0);
    }
    char line[csv_line];
    char fields[5][csv_line];
    while (fgets(line,sizeof(line),file))
    {
        line[strcspn(line, "\n")] = 0;
        parse_csv_line(line, fields);
        for (int i = 0;fields[i][0] != '\0'; i++)
        {
            printf("%s\t", fields[i]);
            if (i == 4)
            {
                printf("\n");
            }
        }
    }
    fclose(file);
    stu_ui();
}

void Tongji()
{
    int temp = 0;
    for (int i = 0; i < X; i++)
    {
        if (stu[i].No == 0)
        {
            break;
        }
        temp++;
    }
    printf("学生人数为:%d\n", temp);
    stu_ui();
}

void Find()
{
    int x;
    printf("请输入要查找的学生学号:");
    scanf("%d", &x);
    for (int i = 0; i < X; i++)
    {
        if (stu[i].No == x)
        {
            printf("学号：%d\n姓名：%s\n性别：%s\n年龄：%d\n成绩：%d\n",stu[i].No,stu[i].Name,stu[i].sex,stu[i].age,stu[i].grade);
            break;
        }
    }
    stu_ui();
}

void Change()
{
    printf("请输入需要修改的学生的学号:\n");
    int n, temp;
    scanf("%d", % n);
    for (int i = 0; i < X; i++)
    {
        if (stu[i].No == n)
        {
            temp = i;
        }
    }
    printf("请选择想要修改的信息\n");
    printf("1.学号，2.姓名，3.性别，4.年龄，5.成绩\n");
    int x, a;
    char b;
    scanf("%d", &x);
    printf("请输入想要修改信息\n");
    switch (x)
    {
    case 1:
        scanf("%d",&a);
        stu[temp].No = a;
        break;
    }
}

void Delate()
{
    int x;
    printf("请输入想要删除的学生的学号:");
    scanf("%d",&x);
    for (int i = 0; i < X; i++)
    {
        if (stu[i].No == x)
        {
            stu[i].No = 0;
        }
    }
}
void Quit()
{
    exit(0);
}
void stu_ui()
{
    int x;
    printf("""\n1.录入学生信息""");
    printf("请选择模式\n");
    scanf("%d",&x);
    switch (x)
    {
    case 1:
        add();
        break;
    }
}
int main()
{
    stu_ui();
    return 0;
}