# BDD Given-When-Then

## 定义

* (Given) some context
* (When) some action is carried out
* (Then) a particular set of observable consequences should obtain

## 解析

### Given 

可理解为初始环境.用来初始化好当前这个测试集合需要的环境.例如可以初始化数据库连接,读取文件等操作

### When

可理解为需要测试的步骤.用来设定需要测试的条件.例如何以向数据库中写入数值,向文件中写入数据等.

### Then

可理解为结果判断.用来判断最终结果是否符合要求.例如检查数据库值是否写入正确,检查文件写入是否成功等.

## 为什么用Given-When-Then?

我们用测试电灯的开关功能是否正确这一测试需求来进行举例对比.

> 开关是关闭状态时,输入打开,开关应变为打开状态,
> 开关是关闭状态时,输入关闭,开关应变为关闭状态,
> 开关是开启状态时,输入打开,开关应变为打开状态,
> 开关是开启状态时,输入关闭,开关应变为关闭状态.

### GTest测试方法

需要写四个测试用例才可以,可能是这样:

```c++
void test_switchOff_On_resultOn()
{
    //构造测试对象和相关资源
    Switch s;

    //设置状态
    s.setState(Off);

    //执行需要测试的逻辑
    s.process(On);

    //测试结果
    REQUIRE(s.State() == On);

    //清理测试对象相关资源
    s.clear();
}
void test_switchOff_Off_resultOff()
{
    /*You know it.*/
}
void test_switchOn_On_resultOn()
{
    /*You know it.*/
}
void test_switchOn_Off_resultOff()
{
    /*You know it.*/
}
```

问题:

- 函数名称要写的比较长，才能说清楚想要测试什么.
- 测试用例中初始化相关的代码多次出现很冗余

### BDD风格测试用例

```c++
SCENARIO("Switch on tests", "[switch_button]")
{
    Switch s;
    GIVEN("the switch is on")
    {
        s.setState(On);
        WHEN("process on")
        {
            s.process(On);
            THEN("switch is on")
            {
                REQUIRE(s.State() == On);
            }
        }
        WHEN("process off")
        {
            s.process(Off);
            THEN("switch is off")
            {
                REQUIRE(s.State() == Off);
            }
        }
    }
    GIVEN("the switch is off")
    {
        s.setState(Off);
        WHEN("process on")
        {
            s.process(On);
            THEN("switch is On")
            {
                REQUIRE(s.State() == On);
            }
        }
        WHEN("process Off")
        {
            s.process(Off);
            THEN("switch is off")
            {
                REQUIRE(s.State() == Off);
            }
        }
    }
    s.clear();
}
```

优点:

- 逻辑表述清晰
- 极大减少冗余代码

**C++的测试库中，Catch2支持BDD Stele方式！**

## 参考链接

1. https://www.agilealliance.org/glossary/gwt/#q=~(infinite~false~filters~(postType~(~'page~'post~'aa_book~'aa_event_session~'aa_experience_report~'aa_glossary~'aa_research_paper~'aa_video)~tags~(~'given*20when*20then))~searchTerm~'~sort~false~sortDirection~'asc~page~1)
2. http://www.electronvector.com/blog/using-catch-to-write-bdd-style-unit-tests-for-c

