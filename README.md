# GESP C++ & CSP-J/S & NOIP 算法题解与成长题库

记录从 CCF GESP C++ (1~8级) 到 CSP-J/S 及 NOIP 普及组编程成长的完整学习过程与代码实现。
全站所有学习资源、大纲梳理与题目深度剖析，详见 [OneCoder 算法博客](https://www.coderli.com) 及 [GESP 学习专题站](https://wiki.coderli.com)。

## 考纲解析 (GESP 1~8级官方全量考点梳理)

### 一级（考纲解析）

| 考点要求 | 官方考纲深度梳理与知识讲解 | 考试级别 |
|:---|:---|:---:|
| （1）了解计算机的基本构成（CPU，内存，I/O 设备等） ，了解 Windows、Linux等操作系统基本概念和常见操作，了解计算机的历史及在现代社会中的常见应用。 | [【GESP】C++一级考试大纲知识点梳理（1）计算机基础和操作系统](https://www.coderli.com/gesp-1-exam-syllabus-computer-basics/) | [一级](https://www.coderli.com/categories/GESP/一级/) |
| （2）熟悉集成开发环境使用（例如 Dev C++）：创建文件、编辑文件、保存文件、编译、解释、调试。 | [【GESP】C++一级考试大纲知识点梳理(考点2,4,10,13), (2) 开发环境与程序基础](https://www.coderli.com/gesp-1-exam-syllabus-2-env-basics/) | [一级](https://www.coderli.com/categories/GESP/一级/) |
| （3）掌握基础的 cin 语句、scanf 语句、cout 语句、printf 语句，赋值语句等。 | [【GESP】C++一级考试大纲知识点梳理(考点3,5,6,9), (3) 变量、数据类型与输入输出](https://www.coderli.com/gesp-1-exam-syllabus-3-data-io/) | [一级](https://www.coderli.com/categories/GESP/一级/) |
| （7）掌握逻辑运算与（&&）、或（--）、非（！）。 | [【GESP】C++一级考试大纲知识点梳理(考点7,8,11), (4) 逻辑运算与分支结构](https://www.coderli.com/gesp-1-exam-syllabus-4-branching/) | [一级](https://www.coderli.com/categories/GESP/一级/) |
| （12）掌握循环结构程序的编写，掌握 for、while、do-while 循环语句的使用以及 continue 语句和 break 语句在循环中的应用。 | [【GESP】C++一级考试大纲知识点梳理(考点12), (5) 循环结构](https://www.coderli.com/gesp-1-exam-syllabus-5-loops/) | [一级](https://www.coderli.com/categories/GESP/一级/) |

### 二级（考纲解析）

| 考点要求 | 官方考纲深度梳理与知识讲解 | 考试级别 |
|:---|:---|:---:|
| （1）了解计算机存储的基本概念及分类，了解随机存储器（RAM）、只读存储器（ROM）和高速缓冲存储器（Cache）的功能及区别。 | [【GESP】C++二级考试大纲知识点梳理, （1）计算机存储的基本概念及分类](https://www.coderli.com/gesp-2-exam-syllabus-computer-storage/) | [二级](https://www.coderli.com/categories/GESP/二级/) |
| （2）了解计算机网络的概念，了解计算机网络的分类（广域网（WAN）、城域网（MAN）、局域网（LAN）），了解计算机网络的层级结构及作用（TCP/IP 四层模型与 OSI七层模型），了解不同层级的重要协议，了解 IP 地址及子网划分。 | [【GESP】C++二级考试大纲知识点梳理, （2）计算机网络的基本概念及分类](https://www.coderli.com/gesp-2-exam-syllabus-network/) | [二级](https://www.coderli.com/categories/GESP/二级/) |
| （3）了解程序设计语言的几大分类及特点（机器语言、汇编语言、高级语言），了解常见的高级语言（C++、Python 等）。 | [【GESP】C++二级考试大纲知识点梳理, （3）计算机程序设计语言相关知识](https://www.coderli.com/gesp-2-exam-syllabus-coding-language/) | [二级](https://www.coderli.com/categories/GESP/二级/) |
| （4）了解流程图的概念及基本表示符号，掌握绘制流程图的方法，能正确使用流程图描述程序设计的三种基本结构。 | [【GESP】C++二级考试大纲知识点梳理, （4）流程图](https://www.coderli.com/gesp-2-exam-syllabus-flow-chart/) | [二级](https://www.coderli.com/categories/GESP/二级/) |
| （5）了解编码的基本概念，了解 ASCII 编码原理，能识别常用字符的 ASCII 码（空格：32、“0”：48、“A”：65、“a”：97），并掌握 ASCII 码和字符之间相互转换的方法。 | [【GESP】C++二级考试大纲知识点梳理, （5）编码与 ASCII](https://www.coderli.com/gesp-2-exam-syllabus-5-coding-ascii/) | [二级](https://www.coderli.com/categories/GESP/二级/) |
| （6）掌握数据类型的转换：强制类型转换和隐式类型转换。 | [【GESP】C++二级考试大纲知识点梳理, （6）数据类型转换](https://www.coderli.com/gesp-2-exam-syllabus-6-type-conversion/) | [二级](https://www.coderli.com/categories/GESP/二级/) |
| （7）掌握多层分支结构，掌握 if 语句、if...else 语句、switch 语句，及相互嵌套的方法。 | [【GESP】C++二级考试大纲知识点梳理, （7）多层分支结构](https://www.coderli.com/gesp-2-exam-syllabus-7-multibranch/) | [二级](https://www.coderli.com/categories/GESP/二级/) |
| （8）掌握多层循环结构，掌握 for 语句、while 语句、do...while 语句，及相互嵌套的方法。 | [【GESP】C++二级考试大纲知识点梳理, （8）多层循环结构](https://www.coderli.com/gesp-2-exam-syllabus-8-multiloop/) | [二级](https://www.coderli.com/categories/GESP/二级/) |
| （9）掌握常用的数学函数：绝对值函数、平方根函数、最大值函数、最小值函数、随机数函数理解相应的算法原理。 | [【GESP】C++二级考试大纲知识点梳理, （9）常用数学函数](https://www.coderli.com/gesp-2-exam-syllabus-9-math-functions/) | [二级](https://www.coderli.com/categories/GESP/二级/) |

### 三级（考纲解析）

| 考点要求 | 官方考纲深度梳理与知识讲解 | 考试级别 |
|:---|:---|:---:|
| （1）了解二进制数据编码:原码、反码、补码。 | [【GESP】C++三级考试大纲知识点梳理, （1）二进制数据编码](https://www.coderli.com/gesp-3-exam-syllabus-data-encoding/) | [三级](https://www.coderli.com/categories/GESP/三级/) |
| （2）掌握数据的进制转换：二进制、八进制、十进制、十六进制。 | [【GESP】C++三级考试大纲知识点梳理, （2）数据的进制转换](https://www.coderli.com/gesp-3-exam-syllabus-data-conversion/) | [三级](https://www.coderli.com/categories/GESP/三级/) |
| （3）掌握位运算：与(&)、或(\-)、非(~)、异或(^)、左移(<<)、右移(>>)的基本使用方法及原理。 | [【GESP】C++三级考试大纲知识点梳理, （3）位运算](https://www.coderli.com/gesp-3-exam-syllabus-bit-operation/) | [三级](https://www.coderli.com/categories/GESP/三级/) |
| （4）了解算法的概念与描述，熟练运用自然语言、流程图、伪代码方式来描述算法。 | [【GESP】C++三级考试大纲知识点梳理, （4）算法](https://www.coderli.com/gesp-3-exam-syllabus-algo/) | [三级](https://www.coderli.com/categories/GESP/三级/) |
| (7) (8) 理解枚举算法、模拟算法的原理及特点，可以解决实际问题。 | [【GESP】C++三级考试大纲知识点梳理, (7) (8) 枚举算法、模拟算法](https://www.coderli.com/gesp-3-exam-syllabus-algo-enumeration-simulation/) | [三级](https://www.coderli.com/categories/GESP/三级/) |
| （6）掌握字符串及其函数的使用包括但不限于大小写转换、字符串搜索、分割、替换。 | [【GESP】C++三级考试大纲知识点梳理, (6) 字符串](https://www.coderli.com/gesp-3-exam-syllabus-string/) | [三级](https://www.coderli.com/categories/GESP/三级/) |

### 四级（考纲解析）

| 考点要求 | 官方考纲深度梳理与知识讲解 | 考试级别 |
|:---|:---|:---:|
| （1）理解 C++指针类型的概念，掌握指针类型变量的定义、赋值、解引用。 | [【GESP】C++四级考试大纲知识点梳理, (1) 指针](https://www.coderli.com/gesp-4-exam-syllabus-pointer/) | [四级](https://www.coderli.com/categories/GESP/四级/) |
| （2）掌握 C++结构体、二维及多维数组的基本概念及使用 | [【GESP】C++四级考试大纲知识点梳理, (2) 结构体和二维数组](https://www.coderli.com/gesp-4-exam-syllabus-struct-two-dimensional-array/) | [四级](https://www.coderli.com/categories/GESP/四级/) |
| （3）理解模块化编程思想，掌握函数的声明、定义及调用，掌握形参与实参的概念及区别。 | [【GESP】C++四级考试大纲知识点梳理, (3) 模块化和函数](https://www.coderli.com/gesp-4-exam-syllabus-module-function/) | [四级](https://www.coderli.com/categories/GESP/四级/) |
| （4）掌握变量作用域的概念，理解全局变量与局部变量的区别。 | [【GESP】C++四级考试大纲知识点梳理, (4) 变量和作用域](https://www.coderli.com/gesp-4-exam-syllabus-variable-scope/) | [四级](https://www.coderli.com/categories/GESP/四级/) |
| （5）掌握函数参数的传递方式：C++值传递、引用传递、指针传递；Python 值传递、引用传递。 | [【GESP】C++四级考试大纲知识点梳理, (5) 值传递](https://www.coderli.com/gesp-4-exam-syllabus-pass-by-value-reference-pointer/) | [四级](https://www.coderli.com/categories/GESP/四级/) |
| （6）掌握递推算法基本思想、递推关系式的推导以及递推问题求解。 | [【GESP】C++四级考试大纲知识点梳理, (6) 递推算法](https://www.coderli.com/gesp-4-exam-syllabus-iteration-algo/) | [四级](https://www.coderli.com/categories/GESP/四级/) |
| （7）掌握排序算法的概念，了解内排序和外排序的概念及差别，理解排序算法的时间复杂度、空间复杂度、使用场景以及稳定性。 | [【GESP】C++四级考试大纲知识点梳理, (7) 排序算法基本概念](https://www.coderli.com/gesp-4-exam-syllabus-sorting-algo-conception/) | [四级](https://www.coderli.com/categories/GESP/四级/) |
| （8）掌握排序算法中的冒泡排序、插入排序、选择排序的算法思想、排序步骤及代码实现。 | [【GESP】C++四级考试大纲知识点梳理, (8) 冒泡、插入、选择排序](https://www.coderli.com/gesp-4-exam-syllabus-three-sorting-methods/) | [四级](https://www.coderli.com/categories/GESP/四级/) |
| （9）简单算法复杂度的估算，含多项式、指数复杂度。 | [【GESP】C++四级考试大纲知识点梳理, (9) 简单算法复杂度的估算](https://www.coderli.com/gesp-4-exam-syllabus-estimation-of-algorithm-time-complexity/) | [四级](https://www.coderli.com/categories/GESP/四级/) |
| （10）掌握文件操作中的重定向，实现文件读写操作，了解文本文件的分类，掌握写操作、读操作、读写操作。 | [【GESP】C++四级考试大纲知识点梳理, (10) 文件读写和重定向](https://www.coderli.com/gesp-4-exam-syllabus-file-read-write/) | [四级](https://www.coderli.com/categories/GESP/四级/) |
| （11）了解异常处理机制，掌握异常处理的常用方法。 | [【GESP】C++四级考试大纲知识点梳理, (11) 异常处理机制](https://www.coderli.com/gesp-4-exam-syllabus-exception/) | [四级](https://www.coderli.com/categories/GESP/四级/) |

### 五级（考纲解析）

| 考点要求 | 官方考纲深度梳理与知识讲解 | 考试级别 |
|:---|:---|:---:|
| （1）掌握初等数论相关知识的概念和应用，包括素数与合数、最大公约数与最小公倍数、同余与模运算、约数与倍数、质因数分解、奇偶性等。 | [【GESP】C++五级考试大纲知识点梳理, (1) 初等数论](https://www.coderli.com/gesp-5-exam-syllabus-elementary-number-theory/) | [五级](https://www.coderli.com/categories/GESP/五级/) |
| （2）掌握 C++数组模拟高精度加法、减法、乘法和除法的相关知识。 | [【GESP】C++五级考试大纲知识点梳理, (2) 模拟高精度计算](https://www.coderli.com/gesp-5-exam-syllabus-simulate-high-precision-arithmetic/) | [五级](https://www.coderli.com/categories/GESP/五级/) |
| （3）掌握链表的创建、插入、删除、遍历和反转操作，理解单链表、双链表、循环链表的区别。 | [【GESP】C++五级考试大纲知识点梳理, (3-1) 链表-单链表](https://www.coderli.com/gesp-5-exam-syllabus-linked-list-1-singly/) | [五级](https://www.coderli.com/categories/GESP/五级/) |
| （3）掌握链表的创建、插入、删除、遍历和反转操作，理解单链表、双链表、循环链表的区别。 | [【GESP】C++五级考试大纲知识点梳理, (3-2) 链表-双向链表](https://www.coderli.com/gesp-5-exam-syllabus-linked-list-2-double/) | [五级](https://www.coderli.com/categories/GESP/五级/) |
| （3）掌握链表的创建、插入、删除、遍历和反转操作，理解单链表、双链表、循环链表的区别。 | [【GESP】C++五级考试大纲知识点梳理, (3-3) 链表-单向循环链表](https://www.coderli.com/gesp-5-exam-syllabus-3-linked-list-3-singly-circle/) | [五级](https://www.coderli.com/categories/GESP/五级/) |
| （3）掌握链表的创建、插入、删除、遍历和反转操作，理解单链表、双链表、循环链表的区别。 | [【GESP】C++五级考试大纲知识点梳理, (3-4) 链表-双向循环链表](https://www.coderli.com/gesp-5-exam-syllabus-3-linked-list-4-double-circle/) | [五级](https://www.coderli.com/categories/GESP/五级/) |
| （4）掌握辗转相除法（也称欧几里得算法）、素数表的埃氏筛法和线性筛法、唯一分解定理的原理和应用。 | [【GESP】C++五级考试大纲知识点梳理, (4) 辗转相除法、素数表和唯一性定理](https://www.coderli.com/gesp-5-exam-syllabus-4-three-theorem-and-algorithm/) | [五级](https://www.coderli.com/categories/GESP/五级/) |
| （5）掌握算法复杂度估算方法（含多项式、对数）。 | [【GESP】C++五级考试大纲知识点梳理, (5) 算法复杂度估算（多项式、对数）](https://www.coderli.com/gesp-5-exam-syllabus-5-estimation-of-algorithm-polynomial-logarithmic/) | [五级](https://www.coderli.com/categories/GESP/五级/) |
| （6）掌握二分查找和二分答案算法（也称二分枚举法）的基本原理，能够在有序数组中快速定位目标值。 | [【GESP】C++五级考试大纲知识点梳理, (6) 二分查找和二分答案](https://www.coderli.com/gesp-5-exam-syllabus-6-binary-search/) | [五级](https://www.coderli.com/categories/GESP/五级/) |
| （7）掌握递归算法的基本原理，能够应用递归解决问题，能够分析递归算法的时间复杂度和空间复杂度，了解递归的优化策略。 | [【GESP】C++五级考试大纲知识点梳理, (7) 递归算法 - 1 基本原理](https://www.coderli.com/gesp-5-exam-syllabus-7-recursion-1/) | [五级](https://www.coderli.com/categories/GESP/五级/) |
| （7）掌握递归算法的基本原理，能够应用递归解决问题，能够分析递归算法的时间复杂度和空间复杂度，了解递归的优化策略。 | [【GESP】C++五级考试大纲知识点梳理, (7) 递归算法 -2 复杂度分析](https://www.coderli.com/gesp-5-exam-syllabus-7-recursion-2/) | [五级](https://www.coderli.com/categories/GESP/五级/) |
| （7）掌握递归算法的基本原理，能够应用递归解决问题，能够分析递归算法的时间复杂度和空间复杂度，了解递归的优化策略。 | [【GESP】C++五级考试大纲知识点梳理, (7) 递归算法 -3 优化策略](https://www.coderli.com/gesp-5-exam-syllabus-7-recursion-3/) | [五级](https://www.coderli.com/categories/GESP/五级/) |
| （8）掌握贪心算法的基本原理，理解最优子结构，能够使用贪心算法解决相关问题。 | [【GESP】C++五级考试大纲知识点梳理, (8) 贪心算法](https://www.coderli.com/gesp-5-exam-syllabus-8-greedy-algorithm/) | [五级](https://www.coderli.com/categories/GESP/五级/) |
| （9）掌握分治算法的基本原理，能够使用归并排序和快速排序对数组进行排序。 | [【GESP】C++五级考试大纲知识点梳理, (9) 分治算法](https://www.coderli.com/gesp-5-exam-syllabus-9-divide-and-conquer/) | [五级](https://www.coderli.com/categories/GESP/五级/) |

### 六级（考纲解析）

| 考点要求 | 官方考纲深度梳理与知识讲解 | 考试级别 |
|:---|:---|:---:|
| （1）掌握树的基本概念，掌握其构造与遍历的相关算法。 | [【GESP】C++六级考试大纲知识点梳理, (1) 树的概念与遍历](https://www.coderli.com/gesp-6-exam-syllabus-1-tree/) | [六级](https://www.coderli.com/categories/GESP/六级/) |
| （2）掌握哈夫曼树、完全二叉树、二叉排序树的相关概念和应用。 | [【GESP】C++六级考试大纲知识点梳理, (2) 哈夫曼树、完全二叉树与二叉排序树](https://www.coderli.com/gesp-6-exam-syllabus-2-huffman-bst/) | [六级](https://www.coderli.com/categories/GESP/六级/) |
| （3）理解哈夫曼编码、格雷编码相关原理并能进行简单应用。 | [【GESP】C++六级考试大纲知识点梳理, (3) 哈夫曼编码与格雷码](https://www.coderli.com/gesp-6-exam-syllabus-3-huffman-gray/) | [六级](https://www.coderli.com/categories/GESP/六级/) |
| （4）掌握深度优先搜索算法（DFS）、宽度优先搜索算法（也称广度优先搜索算法，BFS）、二叉树的搜索算法的概念及应用，能够根据现实问题，选择合适的搜索算法。 | [【GESP】C++六级考试大纲知识点梳理, (4) 搜索算法](https://www.coderli.com/gesp-6-exam-syllabus-4-search/) | [六级](https://www.coderli.com/categories/GESP/六级/) |
| （5）掌握简单动态规划的算法思想，能够使用代码解决相应的一维动态规划问题和简单背包问题。 | [【GESP】C++六级考试大纲知识点梳理, (5) 动态规划与背包问题](https://www.coderli.com/gesp-6-exam-syllabus-5-dp-knapsack/) | [六级](https://www.coderli.com/categories/GESP/六级/) |
| （6）掌握面向对象的思想，了解封装、继承、多态的基本概念，并掌握类的创建和基本的使用方法。 | [【GESP】C++六级考试大纲知识点梳理, (6) 面向对象编程(OOP)基础](https://www.coderli.com/gesp-6-exam-syllabus-6-oop/) | [六级](https://www.coderli.com/categories/GESP/六级/) |
| （7）掌握栈、队列、循环队列的基本定义，应用场景和常见操作。 | [【GESP】C++六级考试大纲知识点梳理, (7) 栈与队列](https://www.coderli.com/gesp-6-exam-syllabus-7-stack-queue/) | [六级](https://www.coderli.com/categories/GESP/六级/) |

### 七级（考纲解析）

| 考点要求 | 官方考纲深度梳理与知识讲解 | 考试级别 |
|:---|:---|:---:|
| （1）掌握数学库常用函数（三角、对数、指数），三角函数包括 sin(x)，cos(x)等； | [【GESP】C++七级考试大纲知识点梳理, (1) 数学库常用函数](https://www.coderli.com/gesp-7-exam-syllabus-math-library/) | [七级](https://www.coderli.com/categories/GESP/七级/) |
| （2）掌握复杂动态规划（二维动态规划、动态规划最值优化）。包括区间动态规划、最长上升子序列（LIS）、最长公共子序列（LCS）等内容，理解基于滚动数组等降低动态规划空间复杂度的方法。 | [【GESP】C++七级考试大纲知识点梳理, (2) 复杂动态规划](https://www.coderli.com/gesp-7-exam-syllabus-complex-dp/) | [七级](https://www.coderli.com/categories/GESP/七级/) |
| （3）图的定义及及基本图论算法。包括图的定义、图的种类（有向图、无向图），图节点的度的概念。掌握编程时图的数据结构表示，以及基于深度优先搜索（DFS）和广度优先搜索（BFS）的图搜索与遍历方法，图的泛洪（flood fill）算法。 | [【GESP】C++七级考试大纲知识点梳理 (3) 图论基础与遍历算法](https://www.coderli.com/gesp-7-exam-syllabus-graph-theory/) | [七级](https://www.coderli.com/categories/GESP/七级/) |
| （4）掌握哈希表的概念与知识及其应用。 | [【GESP】C++七级考试大纲知识点梳理 (4) 哈希表：概念、实现与应用](https://www.coderli.com/gesp-7-exam-syllabus-hash-table/) | [七级](https://www.coderli.com/categories/GESP/七级/) |

### 八级（考纲解析）

| 考点要求 | 官方考纲深度梳理与知识讲解 | 考试级别 |
|:---|:---|:---:|
| （1）掌握计数原理。包括加法原理和乘法原理。 | [【GESP】C++八级考试大纲知识点梳理 (1) 计数原理：加法与乘法](https://www.coderli.com/gesp-8-exam-syllabus-counting-principles/) | [八级](https://www.coderli.com/categories/GESP/八级/) |
| （2）掌握排列与组合基础知识。包括排列、组合的基本概念，及能实现基础排列和组合编程问题的一般方法。 | [【GESP】C++八级考试大纲知识点梳理 (2) 排列与组合](https://www.coderli.com/gesp-8-exam-syllabus-permutations-combinations/) | [八级](https://www.coderli.com/categories/GESP/八级/) |
| （3）掌握杨辉三角形（又称帕斯卡三角形）的概念。 | [【GESP】C++八级考试大纲知识点梳理 (3) 杨辉三角与组合数](https://www.coderli.com/gesp-8-exam-syllabus-yanghui-triangle/) | [八级](https://www.coderli.com/categories/GESP/八级/) |
| （4）掌握倍增法概念。了解倍增法的时间复杂度。 | [【GESP】C++八级考试大纲知识点梳理 (4) 倍增法](https://www.coderli.com/gesp-8-exam-syllabus-binary-lifting/) | [八级](https://www.coderli.com/categories/GESP/八级/) |
| (5)掌握代数与平面几何基础知识（初中数学部分）。包括方程的概念及一元一次方程、二元一次方程的基本求解技巧，求基础平面几何概念、求基本图形（如长方形、三角形、圆形等）的面积等 | [【GESP】C++八级考试大纲知识点梳理 (5) 代数与平面几何](https://www.coderli.com/gesp-8-exam-syllabus-algebra-geometry/) | [八级](https://www.coderli.com/categories/GESP/八级/) |
| (6) 掌握图论算法及综合应用技巧。包括最小生成树的概念、Kruskal 算法、Prim 算法，掌握最短路径的概念、单源最短路径的 Dijkstra 算法、Floyd 算法等。理解实现同一功能的不同算法的比较，并可以灵活解决相关问题。 | [【GESP】C++八级考试大纲知识点梳理 (6) 图论算法：最小生成树与最短路](https://www.coderli.com/gesp-8-exam-syllabus-graph-theory/) | [八级](https://www.coderli.com/categories/GESP/八级/) |
| (7) 算法的时间和空间效率分析。能够掌握 **较为复杂算法** 的时间和空间复杂度分析方法，能够分析各类算法（包括排序算法、查找算法、**树和图的遍历算法**、**搜索算法**、分治及 **动态规划算法** 等）的时间和空间复杂度。 | [【GESP】C++八级考试大纲知识点梳理 (7) 算法的时间和空间效率分析](https://www.coderli.com/gesp-8-exam-syllabus-complexity-analysis/) | [八级](https://www.coderli.com/categories/GESP/八级/) |
| (8) 算法优化。理解不同方法求解一个问题在时间复杂度和空间复杂度上的差异，理解使用数学知识辅助求解问题的技巧（如可以用循环求出等差数列的和，也可以用数学公式求出等差数列的和），掌握一般的算法优化技巧。 | [【GESP】C++八级考试大纲知识点梳理 (8) 算法优化技巧](https://www.coderli.com/gesp-8-exam-syllabus-algorithm-optimization/) | [八级](https://www.coderli.com/categories/GESP/八级/) |

---

## 真题解析-客观题

### 一级(客观题)

| 考试时间 | 题目解析 | 来源 |
|:---:|:---|:---:|
| 2023年3月 | [GESP第一次认证真题解析\|C++一级真题回顾](https://mp.weixin.qq.com/s/2SJtOkaPqnb8IZblSbnfrQ) | CCF GESP官方 |
| 2023年6月 | [GESP第二次认证真题解析\|C++一级真题回顾](https://mp.weixin.qq.com/s/-sawtagzrCM27SWz85W0dw) | CCF GESP官方 |
| 2023年9月 | [GESP第三次认证真题解析\|C++一级真题回顾](https://mp.weixin.qq.com/s/i4zchYyW3mt5ZHoyQPMDFA) | CCF GESP官方 |
| 2024年3月 | [GESP第五次认证真题解析\|C++一级真题回顾](https://mp.weixin.qq.com/s/c7uS6mLE436fkJMu1Cuehg) | CCF GESP官方 |
| 2024年6月 | [GESP第六次认证真题解析\|C++一级真题回顾](https://mp.weixin.qq.com/s/AWazv8ttKrxYhWxxfGYzwQ) | CCF GESP官方 |
| 2024年9月 | [GESP第七次认证真题解析\|C++一级真题回顾](https://mp.weixin.qq.com/s/nQ8d5JcxFFUzh0-JXTj0Ug) | CCF GESP官方 |
| 2024年12月 | [GESP第八次认证真题解析\|C++一级真题回顾](https://mp.weixin.qq.com/s/snIW9bO14f5burkJ74xBug) | CCF GESP官方 |
| 2025年3月 | [GESP第九次认证真题解析\|C++一级真题回顾](https://mp.weixin.qq.com/s/oi1_CfNbTthz81b1bPWgVg) | CCF GESP官方 |
| 2025年6月 | [【GESP】C++ 2025年6月一级考试-客观题真题解析](https://www.coderli.com/gesp-1-analysis-of-real-questions-202506/) | [本站](https://www.coderli.com/) |

### 二级(客观题)

| 考试时间 | 题目解析 | 来源 |
|:---:|:---|:---:|
| 2023年3月 | [GESP第一次认证真题解析\|C++二级真题回顾](https://mp.weixin.qq.com/s/kErNGnm060WC8G3TxSiOrA) | CCF GESP官方 |
| 2023年6月 | [GESP第二次认证真题解析\|C++二级真题回顾](https://mp.weixin.qq.com/s/dFw_mXEr8u3cH1Nlzv6lIQ) | CCF GESP官方 |
| 2024年3月 | [GESP第五次认证真题解析\|C++二级真题回顾](https://mp.weixin.qq.com/s/4iNXFfAlmDCeCfYbxMUqTA) | CCF GESP官方 |
| 2024年6月 | [GESP第六次认证真题解析\|C++二级真题回顾](https://mp.weixin.qq.com/s/8Zta63WK6SE1km1sfkJvww) | CCF GESP官方 |
| 2024年9月 | [GESP第七次认证真题解析\|C++二级真题回顾](https://mp.weixin.qq.com/s/dG42rCy8EBoI6n4go1hIEQ) | CCF GESP官方 |
| 2024年12月 | [GESP第八次认证真题解析\|C++二级真题回顾](https://mp.weixin.qq.com/s/92G6w7Mx8pbHtXDSj0qEyQ) | CCF GESP官方 |
| 2025年3月 | [GESP第九次认证真题解析\|C++二级真题回顾](https://mp.weixin.qq.com/s/2Kg19RFhcUn6WWilIn4RQw) | CCF GESP官方 |

### 三级(客观题)

| 考试时间 | 题目解析 | 来源 |
|:---:|:---|:---:|
| 2023年6月 | [GESP第二次认证真题解析\|C++三级真题回顾](https://mp.weixin.qq.com/s/xV482BvP2f_71T4mG-5n5A) | CCF GESP官方 |
| 2024年3月 | [GESP第五次认证真题解析\|C++三级真题回顾](https://mp.weixin.qq.com/s/4iNXFfAlmDCeCfYbxMUqTA) | CCF GESP官方 |
| 2025年3月 | [【GESP】C++ 2025年3月三级考试-客观题真题解析](https://www.coderli.com/gesp-3-analysis-of-real-questions-202503/) | [本站](https://www.coderli.com/) |

---

## 真题解析-编程题 (CCF GESP 官方认证真题)

### 一级(编程题)

| 考试时间 | 题号 | 题目名称 | 题目类型 | 题解链接 |
|:---:|:---:|:---|:---|:---|
| 2024年9月 | luogu-B4034 | [GESP202409 一级] 小杨购物 | 基础语句 | [查看题解](https://www.coderli.com/gesp-1-luogu-b4034/) |
| 2024年9月 | luogu-B4035 | [GESP202409 一级] 美丽数字 | 基础语句 | [查看题解](https://www.coderli.com/gesp-1-luogu-b4035/) |
| 2024年12月 | luogu-B4062 | [GESP202412 一级] 温度转换 | 基础语句 | [查看题解](https://www.coderli.com/gesp-1-luogu-b4062/) |
| 2024年12月 | luogu-B4063 | [GESP202412 一级] 奇数和偶数 | 基础语句 | [查看题解](https://www.coderli.com/gesp-1-luogu-b4063/) |
| 2025年3月 | luogu-B4257 | [GESP202503 一级] 图书馆里的老鼠 | 基础语句 | [查看题解](https://www.coderli.com/gesp-1-luogu-b4257/) |
| 2025年3月 | luogu-B4258 | [GESP202503 一级] 四舍五入 | 基础语句 | [查看题解](https://www.coderli.com/gesp-1-luogu-b4258/) |
| 2025年6月 | - | C++ 2025年6月一级考试-客观题真题解析 | 真题解析 | [查看题解](https://www.coderli.com/gesp-1-analysis-of-real-questions-202506/) |
| 2025年6月 | luogu-B4354 | [GESP202506 一级] 假期阅读 | 基础语句 | [查看题解](https://www.coderli.com/gesp-1-luogu-b4354/) |
| 2025年6月 | luogu-B4355 | [GESP202506 一级] 值日 | 基础语句 | [查看题解](https://www.coderli.com/gesp-1-luogu-b4355/) |
| 2025年9月 | luogu-B4409 | [GESP202509 一级] 商店折扣 | 基础语句 | [查看题解](https://www.coderli.com/gesp-1-luogu-b4409/) |
| 2025年9月 | luogu-B4410 | [GESP202509 一级] 金字塔 | 基础语句 | [查看题解](https://www.coderli.com/gesp-1-luogu-b4410/) |
| 2026年3月 | luogu-B4495 | [GESP202603 一级] 交朋友 | 基础语句 | [查看题解](https://www.coderli.com/gesp-1-luogu-b4495/) |
| 2026年3月 | luogu-B4496 | [GESP202603 一级] 数字替换 | 数位分离 | [查看题解](https://www.coderli.com/gesp-1-luogu-b4496/) |
| 2026年6月 | luogu-B4551 | [GESP202606 一级] 去旅行 | 基础语句 | [查看题解](https://www.coderli.com/gesp-1-luogu-b4551/) |
| 2026年6月 | luogu-B4552 | [GESP202606 一级] 交税 | 基础语句 | [查看题解](https://www.coderli.com/gesp-1-luogu-b4552/) |
| 2026年9月 | luogu-B4573 | [GESP202609 一级] 新龟兔赛跑 | 分支结构 | [查看题解](https://www.coderli.com/gesp-1-luogu-b4573-turtle-rabbit/) |
| 2026年9月 | luogu-B4574 | [GESP202609 一级] 棋盘上的奖赏 | 循环结构 | [查看题解](https://www.coderli.com/gesp-1-luogu-b4574-chessboard-wheat/) |

### 二级(编程题)

| 考试时间 | 题号 | 题目名称 | 题目类型 | 题解链接 |
|:---:|:---:|:---|:---|:---|
| 2023年3月 | luogu-B3836 | [GESP202303 二级] 百鸡问题 | 多重循环 | [查看题解](https://www.coderli.com/gesp-2-luogu-b3836/) |
| 2023年3月 | luogu-B3837 | [GESP202303 二级] 画三角形 | 多重循环 | [查看题解](https://www.coderli.com/gesp-2-luogu-b3837/) |
| 2023年6月 | luogu-B3840 | [GESP202306 二级] 找素数 | 多重循环 | [查看题解](https://www.coderli.com/gesp-2-luogu-b3840/) |
| 2023年6月 | luogu-B3841 | [GESP202306 二级] 自幂数判断 | 多重循环 | [查看题解](https://www.coderli.com/gesp-2-luogu-b3841/) |
| 2023年9月 | luogu-B3865 | [GESP202309 二级] 小杨的 X 字矩阵 | 多重循环 | [查看题解](https://www.coderli.com/gesp-2-luogu-b3865/) |
| 2023年9月 | luogu-B3866 | [GESP202309 二级] 数字黑洞 | 多重循环 | [查看题解](https://www.coderli.com/gesp-2-luogu-b3866/) |
| 2023年12月 | luogu-B3923 | [GESP202312 二级] 小杨做题 | 多重循环 | [查看题解](https://www.coderli.com/gesp-2-luogu-b3923/) |
| 2023年12月 | luogu-B3924 | [GESP202312 二级] 小杨的H字矩阵 | 多重循环 | [查看题解](https://www.coderli.com/gesp-2-luogu-b3924/) |
| 2024年3月 | luogu-B3954 | [GESP202403 二级] 乘法问题 | 多重循环 | [查看题解](https://www.coderli.com/gesp-2-luogu-b3954/) |
| 2024年3月 | luogu-B3955 | [GESP202403 二级] 小杨的日字矩阵 | 多重循环 | [查看题解](https://www.coderli.com/gesp-2-luogu-b3955/) |
| 2024年6月 | luogu-B4002 | [GESP202406 二级] 平方之和 | 多重循环 | [查看题解](https://www.coderli.com/gesp-2-luogu-b4002/) |
| 2024年6月 | luogu-B4007 | [GESP202406 二级] 计数 | 多重循环 | [查看题解](https://www.coderli.com/gesp-2-luogu-b4007/) |
| 2024年9月 | luogu-B4036 | [GESP202409 二级] 数位之和 | 多重循环 | [查看题解](https://www.coderli.com/gesp-2-luogu-b4036/) |
| 2024年9月 | luogu-B4037 | [GESP202409 二级] 小杨的 N 字矩阵 | 多重循环 | [查看题解](https://www.coderli.com/gesp-2-luogu-b4037/) |
| 2024年12月 | luogu-B4064 | [GESP202412 二级] 寻找数字 | 多重循环 | [查看题解](https://www.coderli.com/gesp-2-luogu-b4064/) |
| 2024年12月 | luogu-B4065 | [GESP202412 二级] 数位和 | 多重循环 | [查看题解](https://www.coderli.com/gesp-2-luogu-b4065/) |
| 2025年3月 | luogu-B4259 | [GESP202503 二级] 等差矩阵 | 多重循环 | [查看题解](https://www.coderli.com/gesp-2-luogu-b4259/) |
| 2025年3月 | luogu-B4260 | [GESP202503 二级] 时间跨越 | 基础语句 | [查看题解](https://www.coderli.com/gesp-2-luogu-b4260/) |
| 2025年6月 | luogu-B4356 | [GESP202506 二级] 数三角形 | 多重循环 | [查看题解](https://www.coderli.com/gesp-2-luogu-b4356/) |
| 2025年6月 | luogu-B4357 | [GESP202506 二级] 幂和数 | 多重循环 | [查看题解](https://www.coderli.com/gesp-2-luogu-b4357/) |
| 2025年9月 | luogu-B4411 | [GESP202509 二级] 优美的数字 | 多重循环 | [查看题解](https://www.coderli.com/gesp-2-luogu-b4411/) |
| 2025年9月 | luogu-B4412 | [GESP202509 二级] 菱形 | 多重循环 | [查看题解](https://www.coderli.com/gesp-2-luogu-b4412/) |
| 2026年3月 | luogu-B4497 | [GESP202603 二级] 数数 | 数位分离 | [查看题解](https://www.coderli.com/gesp-2-luogu-b4497/) |
| 2026年3月 | luogu-B4498 | [GESP202603 二级] 画画 | 双重循环 | [查看题解](https://www.coderli.com/gesp-2-luogu-b4498/) |
| 2026年6月 | luogu-B4553 | [GESP202606 二级] 完全平方数计数 | 循环 | [查看题解](https://www.coderli.com/gesp-2-luogu-b4553/) |
| 2026年6月 | luogu-B4554 | [GESP202606 二级] 菱形 | 循环 | [查看题解](https://www.coderli.com/gesp-2-luogu-b4554/) |
| 2026年9月 | luogu-B4575 | [GESP202609 二级] 直角三角形 | 勾股定理 | [查看题解](https://www.coderli.com/gesp-2-luogu-b4575-right-triangle/) |
| 2026年9月 | luogu-B4576 | [GESP202609 二级] 字符变换 | 二维数组 | [查看题解](https://www.coderli.com/gesp-2-luogu-b4576-char-transform/) |

### 三级(编程题)

| 考试时间 | 题号 | 题目名称 | 题目类型 | 题解链接 |
|:---:|:---:|:---|:---|:---|
| 2023年6月 | luogu-B3842 | [GESP202306 三级] 春游 | 一维数组 | [查看题解](https://www.coderli.com/gesp-3-luogu-b3842/) |
| 2023年6月 | luogu-B3843 | [GESP202306 三级] 密码合规 | 字符串 | [查看题解](https://www.coderli.com/gesp-3-luogu-b3843/) |
| 2023年9月 | luogu-B3867 | [GESP202309 三级] 小杨的储蓄 | 一维数组 | [查看题解](https://www.coderli.com/gesp-3-luogu-b3867/) |
| 2023年9月 | luogu-B3868 | [GESP202309 三级] 进制判断 | 一维数组 | [查看题解](https://www.coderli.com/gesp-3-luogu-b3868/) |
| 2023年12月 | luogu-B3925 | [GESP202312 三级] 小猫分鱼 | 多重循环 | [查看题解](https://www.coderli.com/gesp-3-luogu-b3925/) |
| 2023年12月 | luogu-B3926 | [GESP202312 三级] 单位转换 | 字符串 | [查看题解](https://www.coderli.com/gesp-3-luogu-b3926/) |
| 2024年3月 | luogu-B3956 | [GESP202403 三级] 字母求和 | 字符串 | [查看题解](https://www.coderli.com/gesp-3-luogu-b3956/) |
| 2024年3月 | luogu-B3957 | [GESP202403 三级] 完全平方数 | 字符串 | [查看题解](https://www.coderli.com/gesp-3-luogu-b3957/) |
| 2024年6月 | luogu-B4003 | [GESP202406 三级] 移位 | 字符串 | [查看题解](https://www.coderli.com/gesp-3-luogu-b4003/) |
| 2024年6月 | luogu-B4004 | [GESP202406 三级] 寻找倍数 | 一维数组 | [查看题解](https://www.coderli.com/gesp-3-luogu-b4004/) |
| 2024年9月 | luogu-B4038 | [GESP202409 三级] 平衡序列 | 一维数组 | [查看题解](https://www.coderli.com/gesp-3-luogu-b4038/) |
| 2024年9月 | luogu-B4039 | [GESP202409 三级] 回文拼接 | 字符串 | [查看题解](https://www.coderli.com/gesp-3-luogu-b4039/) |
| 2024年12月 | luogu-B4066 | [GESP202412 三级] 数字替换 | 一维数组 | [查看题解](https://www.coderli.com/gesp-3-luogu-b4066/) |
| 2024年12月 | luogu-B4067 | [GESP202412 三级] 打印数字 | 字符串 | [查看题解](https://www.coderli.com/gesp-3-luogu-b4067/) |
| 2025年3月 | - | C++ 2025年3月三级考试-客观题真题解析 | 真题解析 | [查看题解](https://www.coderli.com/gesp-3-analysis-of-real-questions-202503/) |
| 2025年3月 | luogu-B4261 | [GESP202503 三级] 2025 | 位运算 | [查看题解](https://www.coderli.com/gesp-3-luogu-b4261/) |
| 2025年3月 | luogu-B4262 | [GESP202503 三级] 词频统计 | 字符串 | [查看题解](https://www.coderli.com/gesp-3-luogu-b4262/) |
| 2025年6月 | luogu-B4358 | [GESP202506 三级] 奇偶校验 | 进制转换 | [查看题解](https://www.coderli.com/gesp-3-luogu-b4358/) |
| 2025年6月 | luogu-B4359 | [GESP202506 三级] 分糖果 | 模拟算法 | [查看题解](https://www.coderli.com/gesp-3-luogu-b4359/) |
| 2025年9月 | luogu-B4413 | [GESP202509 三级] 数组清零 | 多重循环 | [查看题解](https://www.coderli.com/gesp-3-luogu-b4413/) |
| 2025年9月 | luogu-B4414 | [GESP202509 三级] 日历制作 | 多重循环 | [查看题解](https://www.coderli.com/gesp-3-luogu-b4414/) |
| 2026年3月 | luogu-B4499 | [GESP202603 三级] 二进制回文串 | 进制转换 | [查看题解](https://www.coderli.com/gesp-3-luogu-b4499/) |
| 2026年3月 | luogu-B4500 | [GESP202603 三级] 凯撒密码 | 字符串处理 | [查看题解](https://www.coderli.com/gesp-3-luogu-b4500/) |
| 2026年6月 | luogu-B4555 | [GESP202606 三级] 加密 | 数组 | [查看题解](https://www.coderli.com/gesp-3-luogu-b4555/) |
| 2026年6月 | luogu-B4556 | [GESP202606 三级] 字符转换 | 字符处理 | [查看题解](https://www.coderli.com/gesp-3-luogu-b4556/) |
| 2026年9月 | luogu-B4577 | [GESP202609 三级] 公共二进制位 | 位运算 | [查看题解](https://www.coderli.com/gesp-3-luogu-b4577-common-binary-bits/) |
| 2026年9月 | luogu-B4578 | [GESP202609 三级] 分割字符串 | 字符串 | [查看题解](https://www.coderli.com/gesp-3-luogu-b4578-split-string/) |

### 四级(编程题)

| 考试时间 | 题号 | 题目名称 | 题目类型 | 题解链接 |
|:---:|:---:|:---|:---|:---|
| 2023年6月 | luogu-B3850 | [GESP202306 四级] 幸运数 | 函数 | [查看题解](https://www.coderli.com/gesp-4-luogu-b3850/) |
| 2023年6月 | luogu-B3851 | [GESP202306 四级] 图像压缩 | 函数 | [查看题解](https://www.coderli.com/gesp-4-luogu-b3851/) |
| 2023年9月 | luogu-B3869 | [GESP202309 四级] 进制转换 | 函数 | [查看题解](https://www.coderli.com/gesp-4-luogu-b3869/) |
| 2023年9月 | luogu-B3870 | [GESP202309 四级] 变长编码 | 函数 | [查看题解](https://www.coderli.com/gesp-4-luogu-b3870/) |
| 2023年12月 | luogu-B3927 | [GESP202312 四级] 小杨的字典 | 一维数组 | [查看题解](https://www.coderli.com/gesp-4-luogu-b3927/) |
| 2023年12月 | luogu-B3928 | [GESP202312 四级] 田忌赛马 | 一维数组 | [查看题解](https://www.coderli.com/gesp-4-luogu-b3928/) |
| 2024年3月 | luogu-B3958 | [GESP202403 四级] 相似字符串 | 函数 | [查看题解](https://www.coderli.com/gesp-4-luogu-b3958/) |
| 2024年3月 | luogu-B3959 | [GESP202403 四级] 做题 | 排序 | [查看题解](https://www.coderli.com/gesp-4-luogu-b3959/) |
| 2024年6月 | luogu-B4005 | [GESP202406 四级] 黑白方块 | 多维数组 | [查看题解](https://www.coderli.com/gesp-4-luogu-b4005/) |
| 2024年6月 | luogu-B4006 | [GESP202406 四级] 宝箱 | 排序 | [查看题解](https://www.coderli.com/gesp-4-luogu-b4006/) |
| 2024年9月 | luogu-B4040 | [GESP202409 四级] 黑白方块 | 多维数组 | [查看题解](https://www.coderli.com/gesp-4-luogu-b4040/) |
| 2024年9月 | luogu-B4041 | [GESP202409 四级] 区间排序 | 排序 | [查看题解](https://www.coderli.com/gesp-4-luogu-b4041/) |
| 2024年12月 | luogu-B4068 | [GESP202412 四级] Recamán | 排序 | [查看题解](https://www.coderli.com/gesp-4-luogu-b4068/) |
| 2024年12月 | luogu-B4069 | [GESP202412 四级] 字符排序 | 排序 | [查看题解](https://www.coderli.com/gesp-4-luogu-b4069/) |
| 2025年3月 | luogu-B4263 | [GESP202503 四级] 荒地开垦 | 多维数组 | [查看题解](https://www.coderli.com/gesp-4-luogu-b4263/) |
| 2025年3月 | luogu-B4264 | [GESP202503 四级] 二阶矩阵 | 多维数组 | [查看题解](https://www.coderli.com/gesp-4-luogu-b4264/) |
| 2025年6月 | luogu-B4360 | [GESP202506 四级] 画布裁剪 | 多维数组 | [查看题解](https://www.coderli.com/gesp-4-luogu-b4360/) |
| 2025年6月 | luogu-B4361 | [GESP202506 四级] 排序 | 排序 | [查看题解](https://www.coderli.com/gesp-4-luogu-b4361/) |
| 2025年9月 | luogu-B4415 | [GESP202509 四级] 排兵布阵 | 多维数组 | [查看题解](https://www.coderli.com/gesp-4-luogu-b4415/) |
| 2025年9月 | luogu-B4416 | [GESP202509 四级] 最长连续段 | 排序 | [查看题解](https://www.coderli.com/gesp-4-luogu-b4416/) |
| 2026年3月 | luogu-B4501 | [GESP202603 四级] 山之谷 | 二维数组 | [查看题解](https://www.coderli.com/gesp-4-luogu-b4501/) |
| 2026年3月 | luogu-B4502 | [GESP202603 四级] 礼盒排序 | 结构体排序 | [查看题解](https://www.coderli.com/gesp-4-luogu-b4502/) |
| 2026年6月 | luogu-B4557 | [GESP202606 四级] 扫雷 | 二维数组 | [查看题解](https://www.coderli.com/gesp-4-luogu-b4557/) |
| 2026年6月 | luogu-B4558 | [GESP202606 四级] 身高体重指数 | 排序 | [查看题解](https://www.coderli.com/gesp-4-luogu-b4558/) |
| 2026年9月 | luogu-B4579 | [GESP202609 四级] 新汉诺塔 | 递归 | [查看题解](https://www.coderli.com/gesp-4-luogu-b4579-new-hanoi/) |
| 2026年9月 | luogu-B4580 | [GESP202609 四级] 有序网格 | 二维数组 | [查看题解](https://www.coderli.com/gesp-4-luogu-b4580-ordered-grid/) |

### 五级(编程题)

| 考试时间 | 题号 | 题目名称 | 题目类型 | 题解链接 |
|:---:|:---:|:---|:---|:---|
| 2023年9月 | luogu-B3871 | [GESP202309 五级] 因数分解 | 数论 | [查看题解](https://www.coderli.com/gesp-5-luogu-b3871/) |
| 2023年9月 | luogu-B3872 | [GESP202309 五级] 巧夺大奖 | 贪心 | [查看题解](https://www.coderli.com/gesp-5-luogu-b3872/) |
| 2023年12月 | luogu-B3929 | [GESP202312 五级] 小杨的幸运数 | 数论 | [查看题解](https://www.coderli.com/gesp-5-luogu-b3929/) |
| 2023年12月 | luogu-B3930 | [GESP202312 五级] 烹饪问题 | 贪心 | [查看题解](https://www.coderli.com/gesp-5-luogu-b3930/) |
| 2024年3月 | luogu-B3968 | [GESP202403 五级] 成绩排序 | 排序 | [查看题解](https://www.coderli.com/gesp-5-luogu-b3968/) |
| 2024年3月 | luogu-B3969 | [GESP202403 五级] B-smooth 数 | 数论 | [查看题解](https://www.coderli.com/gesp-5-luogu-b3969/) |
| 2024年6月 | luogu-P10719 | [GESP202406 五级] 黑白格 | 前缀和 | [查看题解](https://www.coderli.com/gesp-5-luogu-p10719/) |
| 2024年6月 | luogu-P10720 | [GESP202406 五级] 小杨的幸运数字 | 数论 | [查看题解](https://www.coderli.com/gesp-5-luogu-p10720/) |
| 2024年9月 | luogu-B4050 | [GESP202409 五级] 挑战怪物 | 数论 | [查看题解](https://www.coderli.com/gesp-5-luogu-b4050/) |
| 2024年9月 | luogu-B4051 | [GESP202409 五级] 小杨的武器 | 贪心 | [查看题解](https://www.coderli.com/gesp-5-luogu-b4051/) |
| 2024年12月 | luogu-B4070 | [GESP202412 五级] 奇妙数字 | 数论 | [查看题解](https://www.coderli.com/gesp-5-luogu-b4070/) |
| 2024年12月 | luogu-B4071 | [GESP202412 五级] 武器强化 | 贪心 | [查看题解](https://www.coderli.com/gesp-5-luogu-b4071/) |
| 2025年3月 | luogu-P11960 | [GESP202503 五级] 平均分配 | 贪心 | [查看题解](https://www.coderli.com/gesp-5-luogu-p11960/) |
| 2025年3月 | luogu-P11961 | [GESP202503 五级] 原根判断 | 数论 | [查看题解](https://www.coderli.com/gesp-5-luogu-p11961/) |
| 2025年6月 | luogu-P13013 | [GESP202506 五级] 奖品兑换 | 二分答案 | [查看题解](https://www.coderli.com/gesp-5-luogu-p13013/) |
| 2025年6月 | luogu-P13014 | [GESP202506 五级] 最大公因数 | 数论 | [查看题解](https://www.coderli.com/gesp-5-luogu-p13014/) |
| 2025年9月 | luogu-P14073 | [GESP202509 五级] 数字选取 | 数论 | [查看题解](https://www.coderli.com/gesp-5-luogu-p14073/) |
| 2025年9月 | luogu-P14074 | [GESP202509 五级] 有趣的数字和 | 前缀和 | [查看题解](https://www.coderli.com/gesp-5-luogu-p14074/) |
| 2026年3月 | luogu-P15798 | [GESP202603 五级] 有限不循环小数 | 数论 | [查看题解](https://www.coderli.com/gesp-5-luogu-p15798/) |
| 2026年3月 | luogu-P15799 | [GESP202603 五级] 找数 | 二分查找 | [查看题解](https://www.coderli.com/gesp-5-luogu-p15799/) |
| 2026年6月 | luogu-P17010 | [GESP202606 五级] 排排坐 | 排序 | [查看题解](https://www.coderli.com/gesp-5-luogu-p17010/) |
| 2026年6月 | luogu-P17011 | [GESP202606 五级] 晚宴 | 枚举 | [查看题解](https://www.coderli.com/gesp-5-luogu-p17011/) |
| 2026年9月 | luogu-P17455 | [GESP202609 五级] 哥德巴赫猜想 | 数论 | [查看题解](https://www.coderli.com/gesp-5-luogu-p17455-goldbach/) |
| 2026年9月 | luogu-P17456 | [GESP202609 五级] 饮品调制 | 贪心 | [查看题解](https://www.coderli.com/gesp-5-luogu-p17456-beverage-mix/) |

### 六级(编程题)

| 考试时间 | 题号 | 题目名称 | 题目类型 | 题解链接 |
|:---:|:---:|:---|:---|:---|
| 2026年3月 | luogu-P15800 | [GESP202603 六级] 选数 | 算法 | [查看题解](https://www.coderli.com/gesp-6-luogu-p15800/) |
| 2026年3月 | luogu-P15801 | [GESP202603 六级] 完全二叉树 | 算法 | [查看题解](https://www.coderli.com/gesp-6-luogu-p15801/) |
| 2026年6月 | luogu-P17012 | [GESP202606 六级] 条形蛋糕 | 算法 | [查看题解](https://www.coderli.com/gesp-6-luogu-p17012/) |
| 2026年6月 | luogu-P17013 | [GESP202606 六级] 满二叉树 | 二叉树 | [查看题解](https://www.coderli.com/gesp-6-luogu-p17013/) |
| 2026年9月 | luogu-P17457 | [GESP202609 六级] 数组划分 | 动态规划 | [查看题解](https://www.coderli.com/gesp-6-luogu-p17457-array-partition/) |
| 2026年9月 | luogu-P17458 | [GESP202609 六级] 分树规划 | 树形结构 | [查看题解](https://www.coderli.com/gesp-6-luogu-p17458-tree-partition/) |

### 七级(编程题)

| 考试时间 | 题号 | 题目名称 | 题目类型 | 题解链接 |
|:---:|:---:|:---|:---|:---|
| 2026年9月 | luogu-P17459 | [GESP202609 七级] 必经之路 | 图论 | [查看题解](https://www.coderli.com/gesp-7-luogu-p17459-must-pass-node/) |
| 2026年9月 | luogu-P17460 | [GESP202609 七级] 括号序列 | 动态规划 | [查看题解](https://www.coderli.com/gesp-7-luogu-p17460-bracket-sequence/) |

### 八级(编程题)

| 考试时间 | 题号 | 题目名称 | 题目类型 | 题解链接 |
|:---:|:---:|:---|:---|:---|
| 2026年9月 | luogu-P17461 | [GESP202609 八级] 生成树计数 | 高级图论 | [查看题解](https://www.coderli.com/gesp-8-luogu-p17461-cactus-spanning-tree/) |
| 2026年9月 | luogu-P17462 | [GESP202609 八级] 末班车 | 高级图论 | [查看题解](https://www.coderli.com/gesp-8-luogu-p17462-last-subway/) |

---

## CSP 认证与复赛真题解析 (CCF 官方真题)

### CSP-J 普及组历年复赛真题

| 年份 | 题号 | 题目名称 | 对应源码路径 | 题解链接 |
|:---:|:---:|:---|:---|:---|
| 2025年 | luogu-P14357 | [CSP-J 2025真题] 拼数 | `csp/j/2025/P14357.cpp` | [查看题解](https://www.coderli.com/csp-j-2025-p14357/) |
| 2025年 | luogu-P14358 | [CSP-J 2025真题] 座位 | `csp/j/2025/P14358.cpp` | [查看题解](https://www.coderli.com/csp-j-2025-p14358/) |
| 2025年 | luogu-P14359 | [CSP-J 2025真题] 异或和 | `csp/j/2025/P14359.cpp` | [查看题解](https://www.coderli.com/csp-j-2025-p14359/) |
| 2025年 | luogu-P14360 | [CSP-J 2025真题] 多边形 | `csp/j/2025/P14360.cpp` | [查看题解](https://www.coderli.com/csp-j-2025-p14360/) |
| 2024年 | luogu-P11227 | [CSP-J 2024真题] 扑克牌 | `csp/j/2024/P11227.cpp` | [查看题解](https://www.coderli.com/csp-j-2024-p11227/) |
| 2024年 | luogu-P11228 | [CSP-J 2024真题] 地图探险 | `csp/j/2024/P11228.cpp` | [查看题解](https://www.coderli.com/csp-j-2024-p11228/) |
| 2023年 | luogu-P9749 | [CSP-J 2023真题] 公路 | `csp/j/2023/P9749.cpp` | [查看题解](https://www.coderli.com/csp-j-2023-p9749-road/) |
| 2022年 | luogu-P8813 | [CSP-J 2022真题] 乘方 | `csp/j/2022/P8813.cpp` | [查看题解](https://www.coderli.com/csp-j-2022-p8813-power/) |
| 2022年 | luogu-P8814 | [CSP-J 2022真题] 解密 | `csp/j/2022/P8814.cpp` | [查看题解](https://www.coderli.com/csp-j-2022-p8814-decode/) |
| 2021年 | luogu-P7909 | [CSP-J 2021真题] 分糖果 | `csp/j/2021/P7909.cpp` | [查看题解](https://www.coderli.com/csp-j-2021-p7909/) |
| 2021年 | luogu-P7910 | [CSP-J 2021真题] 插入排序 | `csp/j/2021/P7910.cpp` | [查看题解](https://www.coderli.com/csp-j-2021-p7910/) |
| 2021年 | luogu-P7911 | [CSP-J 2021真题] 网络连接 | `csp/j/2021/P7911.cpp` | [查看题解](https://www.coderli.com/csp-j-2021-p7911/) |
| 2020年 | luogu-P7071 | [CSP-J 2020真题] 优秀的拆分 | `csp/j/2020/P7071.cpp` | [查看题解](https://www.coderli.com/csp-j-2020-p7071/) |
| 2020年 | luogu-P7072 | [CSP-J 2020真题] 直播获奖 | `csp/j/2020/P7072.cpp` | [查看题解](https://www.coderli.com/csp-j-2020-p7072/) |
| 2019年 | luogu-P5661 | [CSP-J 2019真题] 公交换乘 | `csp/j/2019/P5661.cpp` | [查看题解](https://www.coderli.com/csp-j-2019-p5661/) |
| 2019年 | luogu-P5662 | [CSP-J 2019真题] 纪念品 | `csp/j/2019/P5662.cpp` | [查看题解](https://www.coderli.com/csp-j-2019-p5662/) |
| 2019年 | luogu-P5681 | CSP-J 2019 江西真题 - 面积 | `csp/j/2019/P5681.cpp` | [查看题解](https://www.coderli.com/csp-j-2019-p5681/) |
| 2019年 | luogu-P5682 | CSP-J 2019 江西真题 - 次大值 | `csp/j/2019/P5682.cpp` | [查看题解](https://www.coderli.com/csp-j-2019-p5682/) |
| 2018年 | luogu-B4072 | [CSP-X 2018真题] 小明的照片 | `csp/j/2018/B4072.cpp` | [查看题解](https://www.coderli.com/csp-x-2018-b4072/) |
| 2018年 | luogu-B4073 | [CSP-X 2018真题] 快递费用 | `csp/j/2018/B4073.cpp` | [查看题解](https://www.coderli.com/csp-x-2018-b4073/) |
| 2018年 | luogu-B4074 | [CSP-X 2018真题] 统计成绩 | `csp/j/2018/B4074.cpp` | [查看题解](https://www.coderli.com/csp-x-2018-b4074/) |
| 2018年 | luogu-B4075 | [CSP-X 2018真题] 11的倍数 | `csp/j/2018/B4075.cpp` | [查看题解](https://www.coderli.com/csp-x-2018-b4075/) |

### CSP-XL 辽宁省复赛真题

| 年份 | 题目标识 | 题目名称 | 对应源码路径 | 题解链接 |
|:---:|:---:|:---|:---|:---|
| 2025年复赛 | BUY | [CSP-XL 2025] 购物 | `csp/xl/2025/2025-11-10-csp-xl-2025ln-4-buy.cpp` | [查看题解](https://www.coderli.com/csp-xl-2025ln-4-buy/) |
| 2025年复赛 | COUNT | [CSP-XL 2025] 字符串数数 | `csp/xl/2025/2025-11-05-csp-xl-2025ln-1-count.cpp` | [查看题解](https://www.coderli.com/csp-xl-2025ln-1-count/) |
| 2025年复赛 | MATCH | [CSP-XL 2025] 小L打比赛 | `csp/xl/2025/2025-11-08-csp-xl-2025ln-3-match.cpp` | [查看题解](https://www.coderli.com/csp-xl-2025ln-3-match/) |
| 2025年复赛 | POINTS | [CSP-XL 2025] 积分 | `csp/xl/2025/2025-11-07-csp-xl-2025ln-2-points.cpp` | [查看题解](https://www.coderli.com/csp-xl-2025ln-2-points/) |

---

## NOIP 普及组历年经典真题解析 (CCF 官方真题)

| 年份 | 题号 | 题目名称 | 对应源码路径 | 题解链接 |
|:---:|:---:|:---|:---|:---|
| 1997年 | luogu-P2241 | [NOIP1997] 统计方形 | `noi/p/1997/P2241.cpp` | [查看题解](https://www.coderli.com/noi-p-1997-luogu-p2241/) |
| 1998年 | luogu-P1008 | [NOIP1998] 三连击 | `noi/p/1998/P1008.cpp` | [查看题解](https://www.coderli.com/noi-p-1998-luogu-p1008/) |
| 1998年 | luogu-P1009 | [NOIP1998] 阶乘之和 | `noi/p/1998/P1009.cpp` | [查看题解](https://www.coderli.com/noi-p-1998-luogu-p1009/) |
| 1998年 | luogu-P1010 | [NOIP1998] 幂次方 | `noi/p/1998/P1010.cpp` | [查看题解](https://www.coderli.com/noi-p-1998-luogu-p1010/) |
| 1998年 | luogu-P1011 | [NOIP1998] 车站 | `noi/p/1998/P1011.cpp` | [查看题解](https://www.coderli.com/noi-p-1998-luogu-p1011/) |
| 1999年 | luogu-P1014 | [NOIP1999] Cantor 表 | `noi/p/1999/P1014.cpp` | [查看题解](https://www.coderli.com/noi-p-1999-luogu-p1014/) |
| 1999年 | luogu-P1015 | [NOIP1999] 回文数 | `noi/p/1999/P1015.cpp` | [查看题解](https://www.coderli.com/noip-1999-luogu-p1015/) |
| 1999年 | luogu-P1016 | [NOIP1999] 旅行家的预算 | `noi/p/1999/P1016.cpp` | [查看题解](https://www.coderli.com/noi-p-1999-luogu-p1016/) |
| 2000年 | luogu-P1017 | [NOIP2000] 进制转换 | `noi/p/2000/P1017.cpp` | [查看题解](https://www.coderli.com/noip-2000-luogu-p1017/) |
| 2000年 | luogu-P1022 | [NOIP2000] 计算器的改良 | `noi/p/2000/P1022.cpp` | [查看题解](https://www.coderli.com/noip-2000-luogu-p1022/) |
| 2000年 | luogu-P1023 | [NOIP2000] 税收与补贴问题 | `noi/p/2000/P1023.cpp` | [查看题解](https://www.coderli.com/noip-2000-luogu-p1023/) |
| 2001年 | luogu-P1024 | [NOIP2001] 一元三次方程求解 | `noi/p/2001/P1024.cpp` | [查看题解](https://www.coderli.com/noi-p-2001-luogu-p1024/) |
| 2001年 | luogu-P1029 | [NOIP2001] 最大公约数和最小公倍数问题 | `noi/p/2001/P1029.cpp` | [查看题解](https://www.coderli.com/noip-2001-luogu-p1029/) |
| 2005年 | luogu-P1048 | [NOIP2005] 采药 | `noi/p/2005/P1048.cpp` | [查看题解](https://www.coderli.com/noip-2005-luogu-p1048/) |
| 2008年 | luogu-P1125 | [NOIP2008] 笨小猴 | `noi/p/2008/P1125.cpp` | [查看题解](https://www.coderli.com/noip-2008-luogu-p1125/) |
| 2011年 | luogu-P1003 | [NOIP2011] 铺地毯 | `noi/p/2011/P1003.cpp` | [查看题解](https://www.coderli.com/noi-p-2011-luogu-p1003/) |
| 2015年 | luogu-P2678 | [NOIP2015] 跳石头 | `noi/p/2015/P2678.cpp` | [查看题解](https://www.coderli.com/noip-2015-luogu-p2678/) |

---

## 编程武器库

| 分类 | 功能 | 教程 |
|:---|:---|:----------|
| [字符判断](https://www.coderli.com/tags/%E6%AD%A6%E5%99%A8%E5%BA%93-%E5%AD%97%E7%AC%A6/) | 判断是否为数字(0-9) | [【GESP/CSP】编程武器库-1, 字符类型判断](https://www.coderli.com/gesp-arsenal-1-char-check-number-alpha/) |
| [字符判断](https://www.coderli.com/tags/%E6%AD%A6%E5%99%A8%E5%BA%93-%E5%AD%97%E7%AC%A6/) | 判断是否为字母(a-z/A-Z) | [【GESP/CSP】编程武器库-1, 字符类型判断](https://www.coderli.com/gesp-arsenal-1-char-check-number-alpha/) |
| [字符判断](https://www.coderli.com/tags/%E6%AD%A6%E5%99%A8%E5%BA%93-%E5%AD%97%E7%AC%A6/) | 判断是否为大写字母(A-Z) | [【GESP/CSP】编程武器库-1, 字符类型判断](https://www.coderli.com/gesp-arsenal-1-char-check-number-alpha/) |
| [字符判断](https://www.coderli.com/tags/%E6%AD%A6%E5%99%A8%E5%BA%93-%E5%AD%97%E7%AC%A6/) | 判断是否为小写字母(a-z) | [【GESP/CSP】编程武器库-1, 字符类型判断](https://www.coderli.com/gesp-arsenal-1-char-check-number-alpha/) |
| [进制转换](https://www.coderli.com/tags/%E6%AD%A6%E5%99%A8%E5%BA%93-%E8%BF%9B%E5%88%B6%E8%BD%AC%E6%8D%A2/) | 十进制和十六进制转换 | [【GESP/CSP】编程武器库-2, 十进制转十六进制](https://www.coderli.com/gesp-arsenal-2-dec-hex-conversion/) |
| [进制转换](https://www.coderli.com/tags/%E6%AD%A6%E5%99%A8%E5%BA%93-%E8%BF%9B%E5%88%B6%E8%BD%AC%E6%8D%A2/) | 十进制和十六进制转换 | [【GESP/CSP】编程武器库-3, 十六进制转十进制](https://www.coderli.com/gesp-arsenal-3-hex-dec-conversion/) |
| [数论算法](https://www.coderli.com/tags/%E6%95%B0%E8%AE%BA/) | 最大公约数和最小公倍数(gcd/lcm) | [【GESP/CSP】编程武器库-4, 最大公约数和最小公倍数](https://www.coderli.com/gesp-arsenal-4-gcd-lcm/) |
| [二分查找](https://www.coderli.com/tags/%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE/) | 二分查找标准库(lower_bound/upper_bound) | [【GESP/CSP】编程武器库-5, 二分查找标准库](https://www.coderli.com/gesp-arsenal-5-lower-upper-bound/) |
| [去重算法](https://www.coderli.com/tags/%E5%8E%BB%E9%87%8D/) | 数组/向量快速去重(unique) | [【GESP/CSP】编程武器库-6, 去重算法(unique)](https://www.coderli.com/gesp-arsenal-6-unique/) |

---

### 专项清单导航

- **GESP 认证体系**：
  - [GESP一级练习题与真题清单](GESP1.md)
  - [GESP二级练习题与真题清单](GESP2.md)
  - [GESP三级练习题与真题清单](GESP3.md)
  - [GESP四级练习题与真题清单](GESP4.md)
  - [GESP五级练习题与真题清单](GESP5.md)
  - [GESP六级练习题与真题清单](GESP6.md)
  - [GESP七级练习题与真题清单](GESP7.md)
  - [GESP八级练习题与真题清单](GESP8.md)
- **CSP 竞赛体系**：
  - [CSP-J / CSP-S / CSP-XL 题解清单与源码索引](CSP.md)
- **NOIP 普及组经典体系**：
  - [NOIP 普及组历年真题清单与源码索引](NOIP.md)

## 联系我们

- C++ GESP学习交流网站：[https://www.coderli.com](https://www.coderli.com)
- ***GESP/CSP 认证学习微信公众号***

![GESP/CSP 认证学习微信公众号](/resources/wechat_qrcode.jpg)
