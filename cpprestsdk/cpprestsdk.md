---
marp: true
theme: default
paginate: true
footer: cpprestsdk - pplx
---

# <!-- fit -->cpprestsdk - pplx

代钤莹

---

**工具和环境**

Visual Studio 2015 update3

---

## cpprestsdk是什么

REST SDK是微软的一个项目，用于在本地代码中使用现代异步C++ API设计进行基于云的客户机-服务器通信。该项目旨在帮助C++开发者连接到服务并与服务进行交互。

---

## ppl是什么

并行模式库(PPL)提供了一个命令式编程模型，该模型可以提高开发并发应用程序的可扩展性和易用性。PPL建立在并发运行时的调度和资源管理组件之上。它通过提供通用的、类型安全的算法和容器，提高了应用程序代码和底层线程机制之间的抽象程度，这些算法和容器可以并行地作用于数据。PPL还通过提供共享状态的替代方案，可用于开发可扩展的应用程序。PPL提供以下功能:

- 任务并行：一种在Windows ThreadPool之上工作的机制，可以并行执行多个工作项（任务）。
- 并行算法：通用算法，工作在并发运行时之上，以并行方式对数据集合进行操作。
- 并行容器和对象：提供安全并发访问其元素的通用容器类型。

---

## pplx是什么

pplx是PPL(Parallel Patterns Library，微软为C++提供的任务并行、并行算法和容器)的删减版.PPLX只提供任务并行的功能，没有提供并行算法和并行容器和对象。


---

### 简单示例

1.以函数来创建异步任务

```cpp
#include <pplx/pplxtasks.h>
int dosomething()
{
    std::cout << "do something need 5 second\n";
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "do something done..\n";
    return 1;
}
int sampleMain()
{
    pplx::task<int> task = pplx::task<int>(dosomething);
    task.wait();
    int value = task.get();
    std::cout << "dosomething result:" << value << std::endl;
    return 0;
}
```

---

2.以已有数值创建异步任务
```cpp
#include <pplx/pplxtasks.h>
int sampleMain()
{
    pplx::task<int> task = pplx::task_from_result<int>(1);
    task.wait();
    int value = task.get();
    std::cout << "dosomething result:" << value << std::endl;
    return 0;
}
```

---


### 异步调用链

```cpp

```

---

### 异步调用链中处理异常

如果上一步调用会产生异常，那么当前调用接收的函数参数不是上一步调用的结果而是```pplx::task<RetureType> arg```在当前函数体内部

---

谢谢大家🙂

![width:530px](mywechat.jpg)

