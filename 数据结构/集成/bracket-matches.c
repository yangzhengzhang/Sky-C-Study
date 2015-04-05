<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef char ElemType;  // 修改类型

typedef struct Node {
    ElemType data;
    struct Node *next;
} Node, *LinkStack;

/**
 * 创建新的节点并返回节点
 * @param ElemType data
 * @param struct Node *next
 * @return LinkStack node
 */
LinkStack NodeCreate(ElemType data, struct Node *next)
{
    struct Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = next;
    return node;
}

/**
 * 初始化链栈并返回头结点
 * @return LinkStack heading
 */
LinkStack InitStack()
{
    struct Node *heading = NodeCreate(0, NULL);
    return (LinkStack)heading;
}

/**
 * 获取元素所在位置 如果i > ElemCount(s) 说明不存在
 * @param LinkStack s
 * @param ElemType data
 * @return int i
 */
int GetElem(LinkStack s, ElemType data)
{
    struct Node *node = s->next;
    int i = 1;

    while (node && node->data != data)  // 查找条件
    {
        node = node->next;
        i++;
    }

    return i;
}

/**
 * 返回某位置节点
 * @param LinkStack s
 * @param int position 第position个元素
 * @return LinkStack node
 */
LinkStack NodeShow(LinkStack s, int position)
{
    struct Node *node = s;
    int i = 0;

    while (node && i < position)
    {
        node = node->next;
        i++;
    }

    return node;
}

/**
 * 元素压入栈内
 * @param LinkStack s
 * @param ElemType data
 */
void Push(LinkStack s, ElemType data)
{
    struct Node *node = s;
    int i = 0;
    int position = ElemCount(s);

    while (node->next && i < position)
    {
        node = node->next;
        i++;
    }
    node->next = NodeCreate(data, node->next);
}

/**
 * 元素出栈
 * @param LinkStack s
 * @return ElemType elem 返回出栈节点的data
 */
ElemType Pop(LinkStack s)
{
    struct Node *node = s, *p;
    ElemType elem;
    int i = 0;
    int position = ElemCount(s);

    if (!position)
    {
        return -1;  // 保护机制 如果栈为空
    }

    while (node->next && i < position - 1)
    {
        node = node->next;
        i++;
    }
    p = node->next;
    node->next = p->next;
    elem = p->data;
    free(p);
    return elem;
}

/**
 * 返回节点（元素）个数
 * @param LinkStack s
 * @return int counter
 */
int ElemCount(LinkStack s)
{
    struct Node *node = s->next;
    int counter = 0;
    while (node != NULL)
    {
        node = node->next;
        counter++;
    }

    return counter;
}

/**
 * 清空栈内元素
 * @param LinkStack List
 */
void ClearList(LinkStack List)
{
    struct Node *node;
    while (List->next != NULL)
    {
        node = List->next;
        List->next = node->next;
        free(node);
    }
}

/**
 * 遍历节点并调用指定函数
 * @param LinkStack List
 * @param void (*pfun)(Node *p)  要调用的函数，函数要求只传入节点
 */
void Traverse(LinkStack List, void (*pfun)(Node *p))
{
    struct Node *p = List->next;
    while (p != NULL)
    {
        (*pfun)(p);
        p = p->next;
    }
}

/**
 * 显示节点元素数据
 * @param Node *p
 */
void Show(Node *p)
{
    printf("%c ", p->data);      // 需要修改%c
}

void HelpManual()
{
    printf("Help:\n");
    printf("  Function:\n");
    printf("    We will check whether the brackets are matched.\n");
    printf("    Logs will save in program_data.log & error_log.log.\n");
    printf("  How to Use:\n");
    printf("    1. Type words in the terminal and then use command to end.\n");
    printf("    2. Use ':' to change to command mode and then use the following commands\n");
    printf("  Commands List:\n");
    printf("    exit: exit the program without check what you type\n");
    printf("    check: finish your input and check the brackets\n");
    printf("    help: clear all you type and call the help manual\n");
    printf("    clear: clear all you type\n");
    printf("    continue: exit command Mode and continue your input\n");
    printf("\nNotice: u also can use Ctrl+Z(EOF) to check it.\n\n");
}

int main(void)
{
    LinkStack s = InitStack();
    ElemType elem;
    time_t t;   // 定义一个时间变量
    t = time(NULL); // 获取时间
    char *time, *p;
    time = ctime(&t);
    p = time;

    FILE *program_data, *error_log;
    program_data = fopen("program_data.log", "a+");
    error_log = fopen("error_log.log", "a+");

    fprintf(program_data, "=====");

    while (p && *p != '\n')
    {
        putc(*p, program_data);
        putc(*p, error_log);
        p++;
    }
    fprintf(program_data, "=====\n\n");
    fprintf(error_log, ":");

    int lineNum = 1;
    int breakLine = 0;  // 标记错误的行号

    /* error: 错误标记 newLine: 新行标记 commandMode: 命令模式 inputMode: 正常输入模式 */
    int error = 0, newLine = 1, commandMode = 0, inputMode = 1;
    char command[100];

    HelpManual();
    printf("Now Type something...\n");
    printf("%d ", lineNum);     // 显示行数

    while (inputMode && (elem = getchar()) != EOF)
    {
        /* 进入命令模式 */
        if (newLine && elem == ':')
        {
            commandMode = 1;
        }

        while (commandMode)
        {
            fgets(command, 100, stdin);     // 输入string到command

            /* command检查 */
            if (!strcmp("exit\n", command))
            {
                printf("Thanks for using, Press any key to exit...");
                getchar();
                fprintf(program_data, "\n========== end of file ===========\n\n");
                fclose(program_data);
                fclose(error_log);

                return 0;
            }
            else if (!strcmp("check\n", command))
            {
                inputMode = 0;
                elem = NULL;
                break;
            }
            else if (!strcmp("help\n", command))
            {
                HelpManual();
                ClearList(s);
                commandMode = 0;
                inputMode = 1;
                newLine = 1;
                lineNum = 1;
                breakLine = 0;
                error = 0;
                elem = NULL;
                fprintf(program_data, "\n============= clear ==============\n\n");
                printf("Now Type something...\n");
                printf("%d ", lineNum); // 显示行数
                break;
            }
            else if (!strcmp("continue\n", command))
            {
                commandMode = 0;
                inputMode = 1;
                elem = NULL;

                printf("%d ", lineNum);
                newLine = 1;
                break;
            }
            else if (!strcmp("clear\n", command))
            {
                ClearList(s);
                commandMode = 0;
                inputMode = 1;
                newLine = 1;
                lineNum = 0;
                breakLine = 0;
                fprintf(program_data, "\n============= clear ==============\n\n");
                error = 0;
                system("cls");
                printf("Now Type something...\n");
                elem = '\n';
                break;
            }
            else {
                printf("Wrong Command. Try Again or use help to ask for help(Will Clear what u type).\n");
            }
            putchar(':');
        }

        newLine = 0;    // 没有进入commandMode 关闭newLine标记

        if (elem == NULL)
        {
            continue;
        }

        if (elem == '\n')
        {
            lineNum++;
            printf("%d ", lineNum);
            newLine = 1;    // newLine标记
        }
        /* 开始检查括号的成对型 */
        else if (elem == '{' || elem == '[' || elem == '(' || elem == '<')
        {
            Push(s, elem);
        }
        else if (elem == '}')
        {
            if (Pop(s) != '{' && !error)
            {
                breakLine = lineNum;
                error = 1;
            }
        }
        else if (elem == ']' && !error)
        {
            if (Pop(s) != '[')
            {
                breakLine = lineNum;
                error = 1;
            }
        }
        else if (elem == ')' && !error)
        {
            if (Pop(s) != '(')
            {
                breakLine = lineNum;
                error = 1;
            }
        }
        else if (elem == '>' && !error)
        {
            if (Pop(s) != '<')
            {
                breakLine = lineNum;
                error = 1;
            }
        }
        putc(elem, program_data);
    }

    fprintf(program_data, "\n========== end of file ===========\n\n");


    /* 左括号多余 */
    if (ElemCount(s))
    {
        error = 1;
        breakLine = 0;
    }

    if (error && breakLine)
    {
        printf("Error in Line %d : brackets not match. Reading program_data.log for more.\n", breakLine);
        fprintf(error_log, "Error in Line %d : brackets not match.\n", breakLine);

    }
    else if (error && !breakLine)
    {
        printf("Error: Losing the brackets. Reading program_data.log for more.\n");
        fprintf(error_log, "Error: Extra brackets.\n");
    }
    else
    {
        printf("No Error, Congratulations\n");
        fprintf(error_log, "No Error\n");
    }

    printf("Line Counter: %d\n", lineNum - 1);
    printf("Press any keys to exit...\n");
    getchar();

    fclose(program_data);
    fclose(error_log);

    return 0;
}
=======
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef char ElemType;  // 修改类型

typedef struct Node {
    ElemType data;
    struct Node *next;
} Node, *LinkStack;

/**
 * 创建新的节点并返回节点
 * @param ElemType data
 * @param struct Node *next
 * @return LinkStack node
 */
LinkStack NodeCreate(ElemType data, struct Node *next)
{
    struct Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = next;
    return node;
}

/**
 * 初始化链栈并返回头结点
 * @return LinkStack heading
 */
LinkStack InitStack()
{
    struct Node *heading = NodeCreate(0, NULL);
    return (LinkStack)heading;
}

/**
 * 获取元素所在位置 如果i > ElemCount(s) 说明不存在
 * @param LinkStack s
 * @param ElemType data
 * @return int i
 */
int GetElem(LinkStack s, ElemType data)
{
    struct Node *node = s->next;
    int i = 1;

    while (node && node->data != data)  // 查找条件
    {
        node = node->next;
        i++;
    }

    return i;
}

/**
 * 返回某位置节点
 * @param LinkStack s
 * @param int position 第position个元素
 * @return LinkStack node
 */
LinkStack NodeShow(LinkStack s, int position)
{
    struct Node *node = s;
    int i = 0;

    while (node && i < position)
    {
        node = node->next;
        i++;
    }

    return node;
}

/**
 * 元素压入栈内
 * @param LinkStack s
 * @param ElemType data
 */
void Push(LinkStack s, ElemType data)
{
    struct Node *node = s;
    int i = 0;
    int position = ElemCount(s);

    while (node->next && i < position)
    {
        node = node->next;
        i++;
    }
    node->next = NodeCreate(data, node->next);
}

/**
 * 元素出栈
 * @param LinkStack s
 * @return ElemType elem 返回出栈节点的data
 */
ElemType Pop(LinkStack s)
{
    struct Node *node = s, *p;
    ElemType elem;
    int i = 0;
    int position = ElemCount(s);

    if (!position)
    {
        return -1;  // 保护机制 如果栈为空
    }

    while (node->next && i < position - 1)
    {
        node = node->next;
        i++;
    }
    p = node->next;
    node->next = p->next;
    elem = p->data;
    free(p);
    return elem;
}

/**
 * 返回节点（元素）个数
 * @param LinkStack s
 * @return int counter
 */
int ElemCount(LinkStack s)
{
    struct Node *node = s->next;
    int counter = 0;
    while (node != NULL)
    {
        node = node->next;
        counter++;
    }

    return counter;
}

/**
 * 清空栈内元素
 * @param LinkStack List
 */
void ClearList(LinkStack List)
{
    struct Node *node;
    while (List->next != NULL)
    {
        node = List->next;
        List->next = node->next;
        free(node);
    }
}

/**
 * 遍历节点并调用指定函数
 * @param LinkStack List
 * @param void (*pfun)(Node *p)  要调用的函数，函数要求只传入节点
 */
void Traverse(LinkStack List, void (*pfun)(Node *p))
{
    struct Node *p = List->next;
    while (p != NULL)
    {
        (*pfun)(p);
        p = p->next;
    }
}

/**
 * 显示节点元素数据
 * @param Node *p
 */
void Show(Node *p)
{
    printf("%c ", p->data);      // 需要修改%c
}

void HelpManual()
{
    printf("Help:\n");
    printf("  Function:\n");
    printf("    We will check whether the brackets are matched.\n");
    printf("    Logs will save in program_data.log & error_log.log.\n");
    printf("  How to Use:\n");
    printf("    1. Type words in the terminal and then use command to end.\n");
    printf("    2. Use ':' to change to command mode and then use the following commands\n");
    printf("  Commands List:\n");
    printf("    exit: exit the program without check what you type\n");
    printf("    check: finish your input and check the brackets\n");
    printf("    help: clear all you type and call the help manual\n");
    printf("    clear: clear all you type\n");
    printf("    continue: exit command Mode and continue your input\n");
    printf("\nNotice: u also can use Ctrl+Z(EOF) to check it.\n\n");
}

int main(void)
{
    LinkStack s = InitStack();
    ElemType elem;
    time_t t;   // 定义一个时间变量
    t = time(NULL); // 获取时间
    char *time, *p;
    time = ctime(&t);
    p = time;

    FILE *program_data, *error_log;
    program_data = fopen("program_data.log", "a+");
    error_log = fopen("error_log.log", "a+");

    fprintf(program_data, "=====");

    while (p && *p != '\n')
    {
        putc(*p, program_data);
        putc(*p, error_log);
        p++;
    }
    fprintf(program_data, "=====\n\n");
    fprintf(error_log, ":");

    int lineNum = 1;
    int breakLine = 0;  // 标记错误的行号

    /* error: 错误标记 newLine: 新行标记 commandMode: 命令模式 inputMode: 正常输入模式 */
    int error = 0, newLine = 1, commandMode = 0, inputMode = 1;
    char command[100];

    HelpManual();
    printf("Now Type something...\n");
    printf("%d ", lineNum);     // 显示行数

    while (inputMode && (elem = getchar()) != EOF)
    {
        /* 进入命令模式 */
        if (newLine && elem == ':')
        {
            commandMode = 1;
        }

        while (commandMode)
        {
            fgets(command, 100, stdin);     // 输入string到command

            /* command检查 */
            if (!strcmp("exit\n", command))
            {
                printf("Thanks for using, Press any key to exit...");
                getchar();
                fprintf(program_data, "\n========== end of file ===========\n\n");
                fclose(program_data);
                fclose(error_log);

                return 0;
            }
            else if (!strcmp("check\n", command))
            {
                inputMode = 0;
                elem = NULL;
                break;
            }
            else if (!strcmp("help\n", command))
            {
                HelpManual();
                ClearList(s);
                commandMode = 0;
                inputMode = 1;
                newLine = 1;
                lineNum = 1;
                breakLine = 0;
                error = 0;
                elem = NULL;
                fprintf(program_data, "\n============= clear ==============\n\n");
                printf("Now Type something...\n");
                printf("%d ", lineNum); // 显示行数
                break;
            }
            else if (!strcmp("continue\n", command))
            {
                commandMode = 0;
                inputMode = 1;
                elem = NULL;

                printf("%d ", lineNum);
                newLine = 1;
                break;
            }
            else if (!strcmp("clear\n", command))
            {
                ClearList(s);
                commandMode = 0;
                inputMode = 1;
                newLine = 1;
                lineNum = 0;
                breakLine = 0;
                fprintf(program_data, "\n============= clear ==============\n\n");
                error = 0;
                system("cls");
                printf("Now Type something...\n");
                elem = '\n';
                break;
            }
            else {
                printf("Wrong Command. Try Again or use help to ask for help(Will Clear what u type).\n");
            }
            putchar(':');
        }

        newLine = 0;    // 没有进入commandMode 关闭newLine标记

        if (elem == NULL)
        {
            continue;
        }

        if (elem == '\n')
        {
            lineNum++;
            printf("%d ", lineNum);
            newLine = 1;    // newLine标记
        }
        /* 开始检查括号的成对型 */
        else if (elem == '{' || elem == '[' || elem == '(' || elem == '<')
        {
            Push(s, elem);
        }
        else if (elem == '}')
        {
            if (Pop(s) != '{' && !error)
            {
                breakLine = lineNum;
                error = 1;
            }
        }
        else if (elem == ']' && !error)
        {
            if (Pop(s) != '[')
            {
                breakLine = lineNum;
                error = 1;
            }
        }
        else if (elem == ')' && !error)
        {
            if (Pop(s) != '(')
            {
                breakLine = lineNum;
                error = 1;
            }
        }
        else if (elem == '>' && !error)
        {
            if (Pop(s) != '<')
            {
                breakLine = lineNum;
                error = 1;
            }
        }
        putc(elem, program_data);
    }

    fprintf(program_data, "\n========== end of file ===========\n\n");


    /* 左括号多余 */
    if (ElemCount(s))
    {
        error = 1;
        breakLine = 0;
    }

    if (error && breakLine)
    {
        printf("Error in Line %d : brackets not match. Reading program_data.log for more.\n", breakLine);
        fprintf(error_log, "Error in Line %d : brackets not match.\n", breakLine);

    }
    else if (error && !breakLine)
    {
        printf("Error: Losing the brackets. Reading program_data.log for more.\n");
        fprintf(error_log, "Error: Extra brackets.\n");
    }
    else
    {
        printf("No Error, Congratulations\n");
        fprintf(error_log, "No Error\n");
    }

    printf("Line Counter: %d\n", lineNum - 1);
    printf("Press any keys to exit...\n");
    getchar();

    fclose(program_data);
    fclose(error_log);

    return 0;
}
>>>>>>> a0e8d74199742fbdb78356ff34cbaa1198f5fe58
