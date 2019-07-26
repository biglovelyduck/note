## 5. I/O库再探

三个更特殊的IO库特性：格式控制，未格式化IO，随机访问

除了<u>条件状态</u>外，每个iostream对象还维护了一个格式状态来控制IO如何格式化的细节（进制，浮点精度，元素宽度)

###1.格式控制

**取消cout格式状态的改变**，我们使用noboolalpha：

```c++
bool bool_val=get_status();
cout<<boolalpha		//设置cout的内部状态
    <<bool_val
    <<noboolalpha;	//将内部状态恢复为默认格式
```

**指定整型值的进制**：

```c++
cout<<"default:"<<20<<" "<<1024;	//默认十进制
cout<<"octal"<<oct<<20<<" "<<1024;	//八进制
cout<<"hex:"<<hex<<20<<" "<<1024;	//16进制
cout<<"decimal:"<<dec<<20<<" "<<1024;	//十进制**
```

**在输出中指定进制**：

```c++
cout<<showbase<<....<<noshowbase
```

**控制浮点数精度：**

```c++
cout<<cout.precision();	//返回当前的精度值
cout.precision(12);	//将打印精度设置为12位数字，等于setprecision(12)
```

![1560389882079](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1560389882079.png)

![1560389900915](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1560389900915.png)

![1560390024341](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1560390024341.png)

### 2.未格式化IO

![1560395191542](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1560395191542.png)

![1560395258207](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1560395258207.png)

![1560395265035](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1560395265035.png)

### 3.流随机访问

![1560395307893](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1560395307893.png)

```c++
//我们的程序将逐行读取文件。对每一行，我们将递增计数器，将刚刚读取的一行长度加到计数器
//统计文件长度
int main(){
    //以读写方式打开文件，并定位到文件尾
    fstream inOut("copyOut",fstream::ate|fstream::in||fstream::out);
    if(!inOut){
        cerr<<"Unable to open file!"<<endl;
        return EXIT_FAILURE;
    }
    auto end_mark=inOut.tellg();	//记住原文件的尾位置
    inOut.seekg(0,fstream::beg);	//重定位到文件开始
    size_t cnt=0;					//字节数累加器
    string line;
    //继续读取的条件，还未遇到错误并且还在读取原数据
    while(inOut&&inOut.tellg()!=end_mark&&getline(inOut,line)){	//且还可以获取一行输入
        cnt+=line.size()+1;	//加1表示换行符
        auto mark=inOut.tellg();	//记住读取位置
        inOut.seekp(0,fstream::end);	//将写标记移动到文件尾
        inOut<<cnt;		//输出累积的长度
        //如果不是最后一行，打印一个分隔符
        if(mark!=end_mark) inOut<<" ";
        inOut.seekg(mark);	//恢复读位置
    }
    inOut.seekp(0,fstream::end);
    return 0;
}
```



# 18章  用于大型程序的工具

##1.异常处理

### 抛出异常

当找不到匹配的catch时，程序将调用标准库函数**terminate**,**terminate**负责终止程序的执行过程

### 捕获异常

### noexcept异常说明

```c++
void recoup(int) noexpect;	//不会抛出异常
void recoup(int) noexpect(true);	//不会抛出异常
void recoup(int) noexpect(fasle);	//可能抛出异常
```

**noexcept**说明符：

```c++
noexcept(recoup(i))	//recoup(i)不抛出异常返回true		
```

如果一个虚函数承诺了它不会抛出异常，那么后续派生出来的虚函数也必须做出同样的承诺。

如果基类的虚函数允许抛出异常，那么派生类可以抛出异常也可以不抛出异常。

**标准exception类层次**

![1560501484753](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1560501484753.png)

## 2.命名空间

命名空间定义：关键字namespace+名字，每个命名空间都是一个作用域

**命名空间的别名**:namespace primer=cplusplus_primer

## 3.多重继承和虚继承



![1560504891646](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1560504891646.png)

![1560505127845](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1560505127845.png)

Panda继承了Bear和Endangered

通过Bear的指针或引用访问一个Panda对象时,Panda对象中的特有部分以及属于Endangered的部分都是不可见的

#### 虚继承

虚继承的目的是令某个类做出声明，承诺愿意共享它的基类，不管虚基类在继承体系中出现了多少次，在派生类中都只包含唯一一个共享的虚基类子对象。

![1560506805900](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1560506805900.png)

虚派生只影响了从指定了虚基类的的派生类中进一步派生出来的类，他不会影响派生类本身。virtual说明符表明了一种愿望，即在后序的派生类当中共享虚基类的同一份实例，



在虚派生中，虚基类是由最低层的派生类初始化的。

![1560508718727](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1560508718727.png)



# 第19章  特殊工具与技术

