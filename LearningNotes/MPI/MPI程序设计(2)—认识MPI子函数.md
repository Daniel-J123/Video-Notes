#! https://zhuanlan.zhihu.com/p/691786586
在C语言的基础上，调用MPI接口，简单介绍它的六种基础函数接口，通常而言这六种函数接口足以实现消息的基本传递和调度。

### 1.1 MPI初始化
```c
int MPI_Init(int *argc, char ***argv);
```

该函数用于初始化MPI环境，包括进程的数量、进程的ID、进程的名字、通信域等。

### 1.2 MPI环境终止
```c
int MPI_Finalize();
```

该函数是MPI程序的最后一个调用，负责终止MPI环境，释放资源。它是MPI程序的最后一条可执行语句，否则程序运行结果不可预知。

### 1.3 当前进程标识
```c
int MPI_Comm_rank(MPI_Comm comm, int *rank);

// 输入comm为通信域，输出rank为当前进程的标识
```
这一调用返回调用进程在给定的通信域中的进程标识号，基于这一标识号，不同进程之间就可以得以区分，实现各进程的并行和协作。

### 1.4 通信域包含的进程数目
```c
int MPI_Comm_size(MPI_Comm comm, int *size);

// 输入comm为通信域，输出size为通信域中进程的数量
```

该调用返回给定通信域中进程的数量，基于这一数量，可以确定通信域中各进程的分布情况，并据此进行通信。

### 1.5 进程间通信
```c
// buf     为发送缓冲区的起始地址
// count   为发送的数据个数(非负整数)
// datatype为发送的数据类型
// dest    为目标进程标识号
// tag     为消息标签
// comm    为通信域
int MPI_Send(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm);


// buf     为接收缓冲区的起始地址
// count   为接收的数据个数(非负整数)
// datatype为接收的数据类型
// source  为源进程标识号
// tag     为消息标签，与发送操作标签相同
// comm    为本进程和发送进程所在的通信域
// status  为状态信息
int MPI_Recv(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Status *status);
```
1. 接收到的消息长度必须小于或等于接收缓冲区的长度；因为如果接收的数据过大，MPI没有进行截断，接收缓冲区会发生溢出错误。

