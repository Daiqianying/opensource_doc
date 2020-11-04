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
int asyncChainMain()
{
    pplx::task<int> task = pplx::task<int>(dosomething);
    task.then([](int result) {
            std::cout << "result:" << result << "\n";
            return std::string("hello world.");
        })
        .then([](std::string result) {
            std::cout << "result:" << result << "\n";
            return 2333.0f;
        });
    task.wait();
    int value = task.get(); //这里拿到的结果仍然是创建task的时候的任务返回值，调用链并无法影响该值
    return 0;
}
```

---

### 异步调用链中处理异常

如果上一步调用会产生异常，那么当前调用接收的函数参数不是上一步调用的结果而是```pplx::task<RetureType> arg```在当前函数体内部等待任务完成处理异常然后执行下一个调用。

---

```cpp
int ThrowExFunc()
{
    throw std::runtime_error("ThrowExFunc throw ex.");
    return 1;
}
```

---

```cpp
int exceptionMain()
{
    pplx::task<int> resp = pplx::task<int>(ThrowExFunc);
    resp.then([](pplx::task<int> resp) {
        try
        {
            pplx::task_status status = resp.wait();
            int value = resp.get();
            std::cout << "value is:" << value << std::endl;
        }
        catch (const std::exception& ex)
        {
            std::cout << ex.what() << std::endl;
        }
    });
    ::getchar();
    return 0;
}
```

---

### 取消任务

```cpp
int cancelAsynTaskMain()
{
    pplx::cancellation_token_source ct;
    auto task = pplx::task<int>([ct]() { //需要值捕获
        int value = 100;
        for (int i = 0; i < 3; i++)
        {
            if (ct.get_token().is_canceled())//检查是否需要取消
            {
                break;
            }
            pplx::wait(1000 * 1);
            value += 100;
        }
        return value;
    });

    std::this_thread::sleep_for(std::chrono::milliseconds(1200));
    ct.cancel();//取消信号

    task.wait();
    std::cout << task.get() << std::endl;
    return 0;
}
```

---

### 任务组

```cpp
int taskGroupMain()
{
    auto task1 = pplx::task_from_result<int>(1);
    auto task2 = pplx::task_from_result<int>(2);
    auto task3 = pplx::task_from_result<int>(3);
    pplx::task<std::vector<int>> group = task1 && task2 && task3;

    group.wait();
    std::vector<int> result = group.get();
    std::cout << result << std::endl; // 1 2 3
    return 0;
}
```

---

### 等待外部事件触发任务执行

```cpp
int externEventTriggerTaskMain()
{
    pplx::task_completion_event<int> tce;
    pplx::task<int> task = pplx::create_task(tce);

    tce.set(999);

    task.wait();
    std::cout << "result:" << task.get() << std::endl;
    return 0;
}
```

---

### 自定义调度器

需要实现纯虚函数schedule
```cpp
typedef void (__cdecl * TaskProc_t)(void *);
struct __declspec(novtable) scheduler_interface
{
    virtual void schedule( TaskProc_t, void* ) = 0;
};
```

---

```cpp
class pplx_dflt_scheduler : public pplx::scheduler_interface
{
    struct _Scheduler_Param
    {
        pplx::TaskProc_t m_proc;
        void* m_param;
        _Scheduler_Param(pplx::TaskProc_t proc, void* param) : m_proc(proc), m_param(param) { }
    };

    static void CALLBACK DefaultWorkCallbackTest(PTP_CALLBACK_INSTANCE, PVOID pContext, PTP_WORK)
    {
        auto schedulerParam = std::unique_ptr<_Scheduler_Param>(static_cast<_Scheduler_Param*>(pContext));
        schedulerParam->m_proc(schedulerParam->m_param);
    }

    virtual void schedule(pplx::TaskProc_t proc, void* param)
    {
        auto schedulerParam = std::unique_ptr<_Scheduler_Param>(new _Scheduler_Param(proc, param));
        auto work = ::CreateThreadpoolWork(DefaultWorkCallbackTest, schedulerParam.get(), NULL);
        if (work == nullptr)
        {
            throw utility::details::create_system_error(GetLastError());
        }
        ::SubmitThreadpoolWork(work);
        ::CloseThreadpoolWork(work);
        schedulerParam.release();
    }
};
```

---

扫码关注我，谢谢大家🙂
![width:530px](mywechat.jpg)

