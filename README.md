# code-specification-file

### 目标：

1. 代码简洁精炼、美观、可持续性好。
2. 自解释性
3. 高效率
4. 高复用
5. 高内聚、低耦合
6. 没有冗余
7. 规范性，代码有规可寻
8. 特殊排版，特殊语法，特殊指令，必须特别说明。

### 代码规范的参考书

1. C++编码规范，陈世忠，人民电邮出版社。
2. 高质量程序设计指南：C++/C语言，林锐等，电子工业出版社，2003

### 代码规范参考

1. google，华为等大厂。
2. 典型的开源项目，如opencv，opengl，boost库等。





---

#### .h文件

头文件引用

第三方库文件使用 `#inclute "lvgl.h"`

根目录的库使用`#inclute <stdint.h>`





#### .c文件

1. 文件命名有两种`驼峰法`和`下划线法`。
2. c文件中的内容顺序：所包含的头文件，宏定义，类型声明，全局变量，函数定义。
3. 函数介绍格式

   ```c
   /**
   * @brief Function for displaying all array info by log printer.
   * 
   * @param[in] event_array: The array linked to the memory allcated by malloc() .
   *
   * @retval NRF_SUCCESS         Initiate successfully.
   * @retval NRF_ERROR_NO_MEM    The malloc() failed.
   *
   * */
   ```

   

3. 测试代码规范,测试代码要在#if里面

```c
#if 1 //only for debug

void demo(void)
{

}

#endif
```

4. 不被外部调用的函数使用static去定义。
