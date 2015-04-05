#表达式括号配对（栈）

stack1.c/stack.c 两种顺序栈 结构

link_stack.c 链栈 结构

bracket-matches.c 配对程序

##程序说明

###功能
输入程序或表达式，使用命令来结束输入并执行相应操作——结束程序的同时，结果将会记录在`program_data` & `error_log` 文件中。

- program_data文件储存输入的程序或表达式
- error_log文件储存错误日志

###指南
比如：
```
#include <stdio.h>
```

然后换行输入`:check`将会结束并检查程序。

换行后`:`开启命令模式

###命令大全
`:check`：结束并检查（结果存在program_data 和 error_log）

`:exit`：不检查并退出（会存在program_data）

`:continue`：不小心进入了命令模式，需要继续输入

`:clear`：清除之前输入并清屏（日志里会有clear分割线）

`:help`：查看帮助并取消之前输入（日志里会有clear分割线）