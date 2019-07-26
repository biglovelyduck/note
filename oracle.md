# 开篇

## Oracle11g服务详细介绍及哪些服务是必须开启的？

**Oracle ORCL VSS Writer Service**

Oracle卷映射拷贝写入服务，VSS（Volume Shadow Copy Service）能够让存储基础设备（比如磁盘，阵列等）创建高保真的时间点映像，即映射拷贝（shadow copy）。它可以在多卷或者单个卷上创建映射拷贝，同时不会影响到系统的系统能。（非必须启动）

**OracleDBConsolexx（xx表示实例名称）**

Oracle数据库控制台服务，orcl是Oracle的实例标识，默认的实例为orcl。在运行Enterprise Manager（企业管理器OEM）的时候，需要启动这个服务。（非必须启动）

**OracleJobSchedulerORCL**

Oracle作业调度（定时器）服务，ORCL是Oracle实例标识。（非必须启动）

**OracleMTSRecoveryService**

服务端控制。该服务允许数据库充当一个微软事务服务器MTS、COM/COM+对象和分布式环境下的事务的资源管理器。（非必须启动）

**OracleOraDb11g_home1ClrAgent**

Oracle数据库.NET扩展服务的一部分。（非必须启动）

**OracleOraDb11g_home1TNSListener**

监听器服务，服务只有在数据库需要远程访问的时候才需要。（非必须启动，下面会有详细详解）。

（监听器服务，服务只有在数据库需要远程访问时才需要（无论是通过另外一台主机还是在本地通过 SQL*Net 网络协议都属于远程访问），不用这个服务就可以访问本地数据库，它的缺省启动类型为自动。服务进程为TNSLSNR.EXE，参数文件Listener.ora，日志文件listener.log，控制台LSNRCTL.EXE，默认端口1521、1526。）

**OracleServicexx（xx表示实例名称）**

数据库服务(数据库实例)，是Oracle核心服务该服务，是数据库启动的基础， 只有该服务启动，Oracle数据库才能正常启动。(必须启动)

（数据库服务，这个服务会自动地启动和停止数据库。如果安装了一个数据库，它的缺省启动类型为自动。服务进程为ORACLE.EXE，参数文件initSID.ora，日志文件SIDALRT.log，控制台SVRMGRL.EXE、SQLPLUS.EXE。）

**对新手来说，要是只用Oracle自带的sql*plus的话，只要启动OracleServiceORCL即可，要是使用PL/SQL Developer等第三方工具的话，OracleOraDb11g_home1TNSListener服务也要开启。**OracleDBConsoleorcl是进入基于web的EM必须开启的，其余服务很少用。注：ORCL是数据库实例名，默认的数据库是ORCL，你可以创建其他的，即OracleService+数据库名。

![1561454407647](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561454407647.png)

![1561454432842](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561454432842.png)

![1561454438851](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561454438851.png)

注：SID - 数据库标识

​    HOME_NAME - Oracle Home名称，如OraHome92、OraHome81

（1）OracleServiceSID                        

数据库服务，这个服务会自动地启动和停止数据库。如果安装了一个数据库，它的缺省启动类型为自动。服务进程为ORACLE.EXE，参数文件initSID.ora，日志文件SIDALRT.log，控制台SVRMGRL.EXE、SQLPLUS.EXE。

（2）OracleHOME_NAMETNSListener

监听器服务，服务只有在数据库需要远程访问时才需要（无论是通过另外一台主机还是在本地通过 SQL*Net 网络协议都属于远程访问），不用这个服务就可以访问本地数据库，它的缺省启动类型为自动。服务进程为TNSLSNR.EXE，参数文件Listener.ora，日志文件listener.log，控制台LSNRCTL.EXE，默认端口1521、1526。

（3）OracleHOME_NAMEAgent

OEM代理服务，接收和响应来自OEM控制台的任务和事件请求，只有使用OEM管理数据库时才需要，它的缺省启动类型为自动。服务进程为DBSNMP.EXE，参数文件snmp_rw.ora，日志文件nmi.log，控制台LSNRCTL.EXE，默认端口1748。

（4）OracleHOME_NAMEClientCache        

名字缓存服务，服务缓存用于连接远程数据库的Oracle Names 数据。它的缺省启动类型是手动。然而，除非有一台Oracle Names 服务器，否则没有必要运行这个服务。服务进程为ONRSD.EXE，参数文件NAMES.ORA，日志文件ONRSD.LOG，控制台NAMESCTL.EXE。

（5）OracleHOME_NAMECMAdmin                        

连接管理服务，是构建Connection Manager服务器所用，只有服务器作为Connection Manager才需要，它的缺省启动类型是手动。服务进程为CMADMIN.EXE，参数文件CMAN.ORA，日志文件CMADM_PID.TRC，控制台CMCTL.EXE，默认端口1830。

（6）OracleHOME_NAMECMan                        

连接网关服务，是构建Connection Manager服务器所用，只有服务器作为Connection Manager才需要，它的缺省启动类型是手动。服务进程为CMGW.EXE，参数文件CMAN.ORA，日志文件CMAN_PID.TRC，控制台CMCTL.EXE，默认端口1630。

（7）OracleHOME_NAMEDataGatherer

性能包数据采集服务，除非使用Oracle Capacity Planner 和 Oracle Performance Manager，否则不需要启动，它的缺省启动类型是手动。服务进程为VPPDC.EXE，日志文件alert_dg.log，控制台vppcntl.exe。

（8）OracleHOME_NAMEHTTPServer

Oracle提供的WEB服务器，一般情况下我们只用它来访问Oracle Apache 目录下的Web 页面，比如说JSP 或者modplsql 页面。除非你使用它作为你的HTTP服务，否则不需要启动（若启动它会接管IIS的服务），它的缺省启动类型是手动。服务进程为APACHE.EXE，参数文件httpd.conf，默认端口80。

（9）OracleHOME_NAMEPagingServer

通过一个使用调制解调器的数字传呼机或者电子邮件发出警告（没试过），它的缺省启动类型是手动。服务进程PAGNTSRV.EXE，日志文件paging.log。

（10）OracleHOME_NAMENames

Oracle Names服务，只有服务器作为Names Server才需要，它的缺省启动类型是手动。服务进程NAMES.EXE，参数文件NAMES.ORA，日志文件NAMES.LOG，控制台NAMESCTL.EXE，默认端口1575。

（11）OracleSNMPPeerMasterAgent

SNMP服务代理，用于支持SNMP的网管软件对服务器的管理，除非你使用网管工具监控数据库的情况，否则不需要启动，它的缺省启动类型是手动。服务进程为AGNTSVC.EXE，参数文件MASTER.CFG，默认端口161。

（12）OracleSNMPPeerEncapsulater

SNMP协议封装服务，用于SNMP协议转换，除非你使用一个不兼容的SNMP代理服务，否则不需要启动，它的缺省启动类型是手动。服务进程为ENCSVC.EXE，参数文件ENCAPS.CFG，默认端口1161。

（13）OracleHOME_NAMEManagementServer

OEM管理服务，使用OEM时需要，它的缺省启动类型是手动。服务进程为OMSNTSVR.EXE，日志文件oms.nohup。

一般启动OracleServiceSID和OracleHOME_NAMETNSListener就行了。

------

# **第1章 走进oracle**

### **1.连接到服务器的命令：**![1561454517678](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561454517678.png)

![1561454523524](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561454523524.png)

**startup open:启动oracle必须是sys用户**

**oracle服务关闭用命令：shutdown immediate**

**在一个数据库中，不同的项目由不同的用户访问，每一个用户拥有自身创建的数据库对象，因此用户的概念在Oracle中非常重要。**



**使用命令行登录的用户名：sys as sysdba**



### **2.创建用户：**![1561454535186](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561454535186.png)

锁定的用户无法正常的登录进行数据库操作。



### **3.数据库角色的概念**：

![1561454546364](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561454546364.png)

### **4.授权：**![1561454557054](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561454557054.png)

### **5.其他操作：**

![1561454568832](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561454568832.png)

## **本章总结**

![1561454579354](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561454579354.png)

# **第二章 SQL操作和查询**



## **1.oracle sql语句由如下命令组成：**

![1561454606572](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561454606572.png)

![1561454610523](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561454610523.png)

![1561454614672](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561454614672.png)

对于日期类型，可以使用sysdate内置函数可以获取当前的系统日期和时间，返回DATE类型，用systimestamp函数可以返回当前日期、时间和时区。

![1561454623424](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561454623424.png)

## **3.创建表和约束：**

![1561454640236](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561454640236.png)

![1561454651744](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561454651744.png)

添加一个外键约束定义：

![1561454665603](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561454665603.png)

## **4.数据操纵语言（DML）**：

用于对数据库的表中数据进行添加、修改、删除和SELECT…For UPDATE(后面专门学习该查询)操作。

### **1.简单查询：**

![img](file:///C:/Users/ADMINI~1/AppData/Local/Temp/enhtmlclip/Image(15).png)![img](data:image/png;base64,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)

\1. *表示表中的所有列。

\2. 列名可以选择若干个表中的列名，各个列表中间用逗号分隔。

\3. 表达式可以是列名、函数、常数等组成的表达式。

\4. WHERE子句是查询的条件。

\5. ORDER BY 要求在查询的结果中排序，默认是升序。



把查询到的结果统计到一张新表：

![1561454675156](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561454675156.png)

### **2.数据插入：**

![1561454686258](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561454686258.png)

\1. 列名可以省略。当省略列名时，默认是表中的所有列名，列名顺序为表定义中列的先后顺序。

\2. 值的数量和顺序要与列名的数量和顺序一致。值的类型与列名的类型一致。



**代码演示：INSERT向表中插入一个结果集**

![1561454694372](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561454694372.png)

### **3.更新数据：**

![1561454801124](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561454801124.png)

**代码演示：UPDATE操作**

![1561454813909](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561454813909.png)

### **4.删除数据**：

![1561454822275](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561454822275.png)

**代码演示：DELETE操作**

![1561454830571](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561454830571.png)

**语法结构:TEUNCATE**:把表中的所有数据一次性删除

```oracle
TRUNCATE TABLE 表名
```

TRUNCATE和DELETE都能把表中的数据全部删除，他们的区别是：
1. TRUNCATE是DDL命令，删除的数据不能恢复；DELETE命令是DML命令，删除后的数据可以通过日志文件恢复。
2. 如果一个表中数据记录很多，TRUNCATE相对DELETE速度快。

###5.操作符

#### 字符串连接操作符||:

![1561455647207](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561455647207.png)

![1561455655157](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561455655157.png)

### 6.高级查询

#### 消除重复行：

![1561455704498](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561455704498.png)

#### NULL操作：

如果某条记录中缺少数据值，就是空值,不是0或空格

在查询条件中NULL值用IS NULL作条件，非NULL值用NOT IS NULL做条件。

#### IN操作：

![1561456469946](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561456469946.png)

等于

![1561456482339](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561456482339.png)

#### BETWEEN...AND...：

![1561456723028](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561456723028.png)

等于

![1561456730465](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561456730465.png)

#### LIKE模糊查询：

%：表示零个或者多个任意字符。
 _：代表一个任意字符。

语法是：LIKE '字符串'[ESCAPE '字符']。匹配的字符串中，ESCAPE后面的“字符”作为转义字符。

#### 集合运算：

INTERSECT(交集)，返回两个查询共有的记录。
UNION ALL(并集)，返回各个查询的所有记录，包括重复记录。
UNION(并集)，返回各个查询的所有记录，不包括重复记录。
MINUS(补集)，返回第一个查询检索出的记录减去第二个查询检索出的记录之后剩余的记录。

查询出dept表中哪个部门下没有员工：

![1561457075981](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561457075981.png)

#### 连接查询：

##### 内连接：

![1561457513944](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561457513944.png)

SQL/92标准使用**JOIN关键字：**INNER可以省略

![1561520304550](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561520304550.png)

##### 外连接：

Emp表用外键deptno引用Dept表中的deptno，在Dept表中如果有某些部门没有员工，那么用内联接，没有员工的部门将无法显示，因此必须以Dept表为基准的外联接。

![1561457552021](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561457552021.png)

![1561466196028](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561466196028.png)

SQL/92标准使用**JOIN关键字：**INNER可以省略

![1561520372706](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561520372706.png)

### 本章总结

![1561466162202](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561466162202.png)

# 第3章 子查询和常用函数

## 1.子查询

子查询值内部的SELECT语句结果可以作为外部条件子句的一部分，类型有：

1. 单行子查询：不向外部返回结果，或者只返回一行结果。
2. 多行子查询：向外部返回零行、一行或者多行结果。

**案例1**：查询出销售部（SALES）下面的员工姓名，工作，工资。

![1561466669925](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561466669925.png)

#### **ANY子查询：**

**案例2**：查询出Emp表中比任意一个销售员(“SALESMAN”)工资低的员工姓名、工作、工资。

![1561466825799](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561466825799.png)

#### ALL子查询

**案例3**：查询出比所有销售员的工资都高的员工姓名，工作，工资。

![1561466910990](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561466910990.png)

## 2.伪列

在实际表中还有一些附加的列，称为伪列。但是在表中并不存储，只能查询，不能增删改

#### ROWID：

​		表中的每一行在数据文件中都有一个物理地址，ROWID伪列返回的就是该行的物理地址。使用ROWID可以快速的定位表中的某一行。ROWID值可以唯一的标识表中的一行。由于ROWID返回的是该行的物理地址，因此使用ROWID可以显示行是如何存储的。

![1561467341315](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561467341315.png)

#### ROWNUM：

ROWNUM为结果集中每一行标识一个行号，第一行返回1，第二行返回2，以此类推。通过ROWNUM伪列可以限制查询结果集中返回的行数。

![1561467607001](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561467607001.png)

**案例5**：查询出工资最高的前5名员工的姓名、工资和工资。 

![1561467772659](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561467772659.png)

**案例6**：查询出表EMP中第5条到第10条之间的记录。（分页）

![1561467829382](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561467829382.png)

![1561467889008](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561467889008.png)

## 3.Oracle函数

1. 单行函数：返回一个输出结果

2. 聚合函数：聚合函数同时可以对多行数据进行操作，并返回一个结果。比如SUM(x)返回结果集中x列的总合。

#### 字符函数：

![1561468102821](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561468102821.png)

**示例：**

![1561468185193](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561468185193.png)

#### 数字函数：

![1561468500763](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561468500763.png)

![1561468507237](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561468507237.png)

#### 日期函数：

1. ADD_MONTHS(d,n)，在某一个日期d上，加上指定的月数n，返回计算后的新日期。

2. LAST_DAY(d)，返回指定日期当月的最后一天。

3. ROUND(d[,fmt])，返回一个以fmt为格式的四舍五入日期值，d是日期，fmt是格式模型。默认fmt为DDD，即月中的某一天。
 如果fmt为“YEAR”则舍入到某年的1月1日，即前半年舍去，后半年作为下一年。
 如果fmt为“MONTH”则舍入到某月的1日，即前月舍去，后半月作为下一月。
 默认为“DDD”，即月中的某一天，最靠近的天，前半天舍去，后半天作为第二天。
 如果fmt为“DAY”则舍入到最近的周的周日，即上半周舍去，下半周作为下一周周日。

![1561509218077](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561509218077.png)

4. EXTRACT(fmt FROM d)，提取日期中的特定部分。

![1561509305516](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561509305516.png)

#### 转换函数：

从一种数据类型转换到另一种数据类型。

1. TO_CHAR(d|n[,fmt])：把日期和数字转换为制定格式的字符串。fmt是格式化字符串

![1561509391769](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561509391769.png)

![1561509507997](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561509507997.png)

**数字的格式化字符：**

![1561509521120](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561509521120.png)

![1561509924460](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561509924460.png)

![1561509947297](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561509947297.png)

2. TO_DATE(x [,fmt])
把一个字符串以fmt格式转换为一个日期类型，前面已经学习过。

3. TO_NUMBER(x[,fmt])
把一个字符串以fmt格式转换为一个数字。fmt格式字符参考表3。

#### 其他单行函数：

1. NVL(x,value)
如果x为空，返回value，否则返回x。

**案例7**：对工资是2000元以下的员工，如果没有发奖金，每人奖金100元。

![1561510084920](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561510084920.png)

2. NVL2(x,value1,value2)
如果x非空，返回value1，否则返回value2。

**案例8**：对EMP表中工资为2000元以下的员工，如果没有奖金，则奖金为200元，如果有奖金，则在原来的奖金基础上加100元。

![1561510135418](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561510135418.png)

#### 聚合函数：

聚合函数同时对一组数据进行操作，返回一行结果，比如计算一组数据的总和，平均值等。

![1561510756172](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561510756172.png)

**案例9**：求本月所有员工的基本工资总和。

![1561510788078](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561510788078.png)

**案例10**：求不同部门的平均工资。

![1561510808525](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561510808525.png)

### 本章总结

![1561511180470](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561511180470.png)

# 第4章 表空间、数据库对象

## 1.Oracle数据库对象

前面已经接触过的数据库对象有表、用户等。现在还有：

 同义词：就是给数据库对象一个别名。
 序列：Oracle中实现增长的对象。
 视图：预定义的查询，作为表一样的查询使用，是一张虚拟表。
 索引：对数据库表中的某些列进行排序，便于提高查询效率。

## 2.同义词

​		同义词（Synonym）是数据库对象的一个别名，Oracle可以为表、视图、序列、过程、函数、程序包等指定一个别名。同义词有两种类型：
 私有同义词：拥有CREATE SYNONYM权限的用户（包括非管理员用户）即可创建私有同义词，创建的私有同义词只能由当前用户使用。
 公有同义词：系统管理员可以创建公有同义词，公有同义词可以被所有用户访问。

**创建同义词：**

![1561511596466](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561511596466.png)

**解析：**

① CREATE [OR REPLACE：]表示在创建同义词时，如果该同义词已经存在，那么就用新创建的同义词代替旧同义词。
② PULBIC：创建公有同义词时使用的关键字，一般情况下不需要创建公有同义词。
③ Oracle中一个用户可以创建表、视图等多种数据库对象，一个用户和该用户下的所有数据库对象的集合称为Schema（中文称为模式或者方案），用户名就是Schema名。一个数据库对象的全称是：用户名.对象名，即schema.object_name。

**示例：System用户访问Scott用户的Emp表**

![1561511759007](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561511759007.png)

**案例1**：创建一个用户XiaoMei，该用户拥有CONNECT角色和RESOURCE角色。为SCOTT用户的EMP表创建同义词，并通过同义词访问该EMP表。

![1561511820853](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561511820853.png)

![1561511835515](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561511835515.png)

![1561511849624](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561511849624.png)

**代码解析：**

① 在管理员用户下创建用户XiaoMei，对用户XiaoMei授予CONNECT和RESOURCE角色。为了XiaoMei能够创建序列，必须授予系统权限：CREATE SYNONYM。
② 在XiaoMei用户下，为SCOTT.EMP创建私有同义词MyEmp，同义词MyEmp只能在XiaoMei用户下使用。访问MyEmp就是访问SCOTT.EMP对象。
③ 访问MyEmp对象出错：对象不存在。因为XiaoMei如果访问MyEmp，就相当于访问SCOTT.EMP对象，那么SCOTT用户必须对XiaoMei授予相应的权限。
④ SCOTT用户下，把EMP表的所有权限（增删改查）授予XiaoMei。
⑤ 对MyEmp执行查询操作。MyEmp就可以像在本地的表一样使用。

**删除同义词：**

![1561512858856](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561512858856.png)

## 3.序列

序列(Sequence)是用来生成连续的整数数据的对象。序列常常用来作为主键中增长列，序列中的可以升序生成，也可以降序生成。

**创建序列：**

![1561512932362](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561512932362.png)

① START WITH：从某一个整数开始，升序默认值是1，降序默认值是-1。
② INCREMENT BY：增长数。如果是正数则升序生成，如果是负数则降序生成。升序默认值是1，降序默认值是-1。
③ MAXVALUE：指最大值。
④ NOMAXVALUE：这是最大值的默认选项，升序的最大值是：1027，降序默认值是-1。
⑤ MINVALUE：指最小值。
⑥ NOMINVALUE：这是默认值选项，升序默认值是1，降序默认值是-1026。
⑦ CYCLE：表示如果升序达到最大值后，从最小值重新开始；如果是降序序列，达到最小值后，从最大值重新开始。
⑧ NOCYCLE：表示不重新开始，序列升序达到最大值、降序达到最小值后就报错。默认NOCYCLE。
⑨ CACHE：使用CACHE选项时，该序列会根据序列规则预生成一组序列号。保留在内存中，当使用下一个序列号时，可以更快的响应。当内存中的序列号用完时，系统再生成一组新的序列号，并保存在缓存中，这样可以提高生成序列号的效率。Oracle默认会生产20个序列号。
⑩ NOCACHE：不预先在内存中生成序列号。

**案例2**：创建一个从1开始，默认最大值，每次增长1的序列，要求NOCYCLE，缓存中有30个预先分配好的序列号。

![1561514777898](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561514777898.png)

使用DROP SEQUENCE命令可以删除一个序列对象。

序列的修改和删除：

![1561515055787](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561515055787.png)

## 4.视图

视图（View）实际上是一张或者多张表上的预定义查询，这些表称为基表。从视图中查询信息与从表中查询信息的方法完全相同。只需要简单的SELECT…FROM即可。

**视图具有以下优点：**

1. 可以限制用户只能通过视图检索数据。这样就可以对最终用户屏蔽建表时底层的基表。
2. 可以将复杂的查询保存为视图。可以对最终用户屏蔽一定的复杂性。
3. 限制某个视图只能访问基表中的部分列或者部分行的特定数据。这样可以实现一定的安全性。
4. 从多张基表中按一定的业务逻辑抽出用户关心的部分，形成一张虚拟表。

**创建视图：**

![1561515349781](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561515349781.png)

**解析：**

1. OR REPLACE：如果视图已经存在，则替换旧视图。
2. FORCE：即使基表不存在，也可以创建该视图，但是该视图不能正常使用，当基表创建成功后，视图才能正常使用。
3. NOFORCE：如果基表不存在，无法创建视图，该项是默认选项。
4. WITH READ ONLY：默认可以通过视图对基表执行增删改操作，但是有很多在基表上的限制（比如：基表中某列不能为空，但是该列没有出现在视图中，则不能通过视图执行insert操作），WITH READ ONLY说明视图是只读视图，不能通过该视图进行增删改操作。现实开发中，基本上不通过视图对表中的数据进行增删改操作。

**案例3**：基于EMP表和DEPT表创建视图

![1561515583984](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561515583984.png)

## 5.索引

索引类似目录，就是对某些特定列中的数据排序，生成独立的索引表

如果表中的某些字段经常被查询并作为查询的条件出现时，就应该考虑为该列创建索引。基本的准则是：当任何单个查询要检索的行少于或者等于整个表行数的10%时，索引就非常有用。Oracle数据库会为表的主键和包含唯一约束的列自动创建索引，此索引对增删改时会有负面影响。

**创建索引：**

![1561515775526](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561515775526.png)

**解析：**

1. UNIQUE:指定索引列上的值必须是唯一的。称为唯一索引。
2. index_name：指定索引名。
3. tabl_name：指定要为哪个表创建索引。
4. column_name：指定要对哪个列创建索引。我们也可以对多列创建索引；这种索引称为组合索引。

**案例4：**为EMP表的ENAME列创建创建唯一索引，为EMP表的工资列创建普通索引，把JOB列先变为小写再创建索引。

![1561515837444](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561515837444.png)

① 为SCOTT.EMP表的ENAME列创建唯一索引。
② 为SCOTT.EMP表的SAL列创建索引。
③ 在查询中可能经常使用job的小写作为条件的表达式，因此创建索引时，可以先对JOB列中的所有值转换为小写后创建索引，而这时需要使用lower函数，这种索引称为基于函数的索引。

## 6.表空间

![1561536281251](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561536281251.png)

Oracle中所有的数据（包括系统数据），全部保存在表空间中，常见的表空间有：
 系统表空间：存放系统数据，系统表空间在数据库创建时创建。表空间名称为SYSTEM。存放数据字典和视图以及数据库结构等重要系统数据信息，在运行时如果SYSTEM空间不足，对数据库影响会比较大，虽然在系统运行过程中可以通过命令扩充空间，但还是会影响数据库的性能，因此有必要在创建数据库时适当的把数据文件设置大一些。
 TMEP表空间：临时表空间，安装数据库时创建，可以在运行时通过命令增大临时表空间。临时表空间的重要作用是数据排序。比如当用户执行了诸如Order by等命令后，服务器需要对所选取数据进行排序，如果数据很大，内存的排序区可能装不下太大数据，就需要把一些中间的排序结果写在硬盘的临时表空间中。
 用户表自定义空间：用户可以通过CREATE TABLESPACE命令创建表空间。

**创建表空间：**

![1561536498075](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561536498075.png)

**解析：**

1. 文件名包括完整路径和文件名，每个数据文件定义了文件的初始大小，初始大小一般以“M”为单位。一个表空间中可以有多个数据文件。
2. EXTENT MANAGEMENT LOCAL指明表空间类型是：本地管理表空间。本地管理表空间要求Oracle中的数据分区（Extent）大小统一。
3. UNIFORM SIZE：指定每个分区的统一大小。

**案例5**：创建一个表空间，包含两个数据文件大小分别是10MB，5MB，要求extent的大小统一为1M。

![1561536594091](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561536594091.png)

**扩充表空间：**

![1561536622166](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561536622166.png)

**为某一用户指定默认表空间：**

![1561536657459](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561536657459.png)

**为表指定表空间：**

![1561536692135](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561536692135.png)

**为索引指定表空间：**

![1561536720591](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561536720591.png)

### 本章总结

 Oracle数据库对象都是使用CREATE命令创建的。
 同义词就是数据库对象的一个别名。同义词的类型有公有同义词和私有同义词。只有管理员可以创建共有同义词。创建同义词的命令是：CREATE SYNONYM。
 序列能够产生一个连续不重复的整数。经常作为数据库的主键生成器。创建序列的命令是CREATE SEQUENCE。
 序列的访问使用两个“伪列”，CURRVAL表示序列的当前值，NEXTVAL表示序列的下一个值。
 视图就是一个预处理的查询语句，可以从若干表中过滤数据。
 索引就是在查询中经常使用的列进行排序。常见的索引有：普通索引、唯一序列、组合索引以及基于函数的索引。此外还有位图索引、反向键索引等。
 表空间是数据库的一个逻辑概念，表空间由若干个数据文件组成。为数据库对象和数据提供统一的空间管理。



# 第5章 PL/SQL程序设计

## 1.简介

oracle PL/SQL语言（Procedural Language/SQL）是结合了结构化查询与Oracle自身过程控制为一体的强大语言，PL/SQL不但支持更多的数据类型，拥有自身的变量声明、赋值语句，而且还有条件、循环等流程控制语句。过程控制结构与SQL数据处理能力无缝的结合形成了强大的编程语言，可以创建过程和函数以及程序包。

![1561536897520](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561536897520.png)

**PL/SQL的优点:**

 支持SQL 支持面向对象编程 更好的性能 可移植性 安全性

## 2.PL/SQL块

每个逻辑块分为三个部分，语法是：

![1561537053309](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561537053309.png)

① 声明部分：声明部分包含了变量和常量的定义。这个部分由关键字DECLARE开始，如果不声明变量或者常量，可以省略这部分。
② 执行部分：执行部分是 PL/SQL块的指令部分，由关键字BEGIN开始，关键字END结尾。所有的可执行PL/SQL语句都放在这一部分，该部分执行命令并操作变量。其他的PL/SQL块可以作为子块嵌套在该部分。PL/SQL块的执行部分是必选的。注意END关键字后面用分号结尾。
③ 异常处理部分：该部分是可选的，该部分用EXCEPTION关键字把可执行部分分成两个小部分，之前的程序是正常运行的程序，一旦出现异常就跳转到异常部分执行。

**PL/SQL块中的每一条语句都必须以分号结束**

![1561537285298](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561537285298.png)

### 变量声明：

**语法：**变量名 数据类型[ :=初始值]，数据类型如果需要长度，可以用括号指明长度，比如：varchar2(20)。

**声明变量：**

![1561537447521](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561537447521.png)

① 声明一个变量sname，初始化值是“jerry”。字符串用单引号，如果字符串中出现单引号可以使用两个单引号（’’）来表示，即<u>单引号同时也具有转义的作用</u>。
② 对变量sname重新赋值，赋值运算符是“:=”。
③ dbms_output.put_line是输出语句，可以把一个变量的值输出，在SQL*Plus中输出数据时，可能没有结果显示，可以使用命令：set serveroutput on设置输出到SQL*Plus控制台上。

**使用SELECT...INTO从查询的数据对变量赋值：**

![1561537676247](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561537676247.png)

① 变量初始化时，可以使用DEFAULT关键字对变量进行初始化。
② 使用select…into语句对变量sname赋值，要求查询的结果必须是一行，不能是多行或者没有记录。

### 声明常量：

常量在声明时赋予初值，并且在运行时不允许重新赋值。使用CONSTANT关键字声明常量。

**声明常量：**

![1561538169429](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561538169429.png)

① 声明常量时使用关键字CONSTANT，常量初值可以使用赋值运算符（:=）赋值，也可以使用DEFAULT关键字赋值。

**宿主变量**：该变量在整个会话过程中均起作用，宿主变量在PL/SQL引用时要用“:变量名”引用

![1561538335899](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561538335899.png)

① 可以使用var声明宿主变量。
② PL/SQL中访问宿主变量时要在变量前加“:”。
③ 在SQL*Plus中，使用print可以输出变量中的结果。

## 3.PL/SQL数据类型

### 标量数据类型：

![1561538445091](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561538445091.png)

![1561538454438](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561538454438.png)

### 属性数据类型：

当声明一个变量的值是数据库中的一行或者是数据库中某列时，可以直接使用属性类型来声明。Oracle中存在两种属性类型：**%TYPE和%ROWTYPE**

![1561538509846](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561538509846.png)

① 声明一个myemp对象，该对象表示EMP表中的一行。
② 从EMP表中查询一条记录放入myemp对象中。
③ 访问该对象的属性可以使用“.”。

**%TYPE以及应用：**
引用某个变量或者数据库的**列**的类型作为某变量的数据类型。

![1561538600586](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561538600586.png)

① 定义变量sal为emp表中sal列的类型。
② 定义totalsal是变量mysal的类型。

## 4.PL/SQL条件控制和循环控制

### 条件控制：

PL/SQL中关于条件控制的关键字有**IF-THEN、IF-THEN-ELSE、IF-THEN-ELSIF和多分枝条件CASE**。

**IF语法：**

![1561541556577](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561541556577.png)

![1561541634142](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561541634142.png)

![1561541660272](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561541660272.png)

**CASE语法：**

![1561541700995](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561541700995.png)

① & grade表示在运行时由键盘输入字符串到grade变量中。
② v_grade分别于WHEN后面的值匹配，如果成功就执行WHEN后的程序序列。

① CASE语句可以返回一个结果给变量p_grade

### 循环结构:

**LOOP循环语法：**

![1561541880037](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561541880037.png)

可以使用EXIT或者[EXIT WHEN 条件]的形式终止循环。否则该循环就是死循环。

**WHILE循环语法：**

![1561542005596](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561542005596.png)

**FOR循环语法：**

![1561542136911](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561542136911.png)

### 顺序结构：

**GOTO语句：**GOTO语句将无条件的跳转到标签指定的语句去执行。标签是用双尖括号括起来的标示符，在PL/SQL块中必须具有唯一的名称，标签后必须紧跟可执行语句或者PL/SQL块。GOTO不能跳转到IF语句、CASE语句、LOOP语句、或者子块中。

**NULL语句：**NULL语句什么都不做，只是将控制权转到下一行语句。NULL语句是可执行语句。NULL语句在IF或者其他语句语法要求至少需要一条可执行语句，但又不需要具体操作的地方。比如GOTO的目标地方不需要执行任何语句时。

## 5.PL/SQL中动态执行SQL语句

在PL/SQL程序开发中，可以使用DML语句和事务控制语句，但是还有很多语句（比如DDL语句）不能直接在PL/SQL中执行。这些语句可以使用动态SQL来实现。 <u>PL/SQL块先编译然后再执行</u>，动态SQL语句在编译时不能确定，只有在程序执行时把SQL语句作为字符串的形式由动态SQL命令来执行。在编译阶段SQL语句作为字符串存在，程序不会对字符串中的内容进行编译，在运行阶段再对字符串中的SQL语句进行编译和执行，动态SQL的语法是：

![1561544728282](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561544728282.png)

**示例：**

![1561544756206](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561544756206.png)

① 动态执行一个完整的SQL语句。
② SQL语句中存在3个参数分别标识为：[:1、:2、:3]，因此需要用USING关键字对三
个参数分别赋值。
③ 对动态查询语句可以使用INTO子句把查询的结果保存到一个变量中，要求该结果只能是单行。
④ 在Oracle的insert，update，delete语句都可以使用RETURNING子句把操作影响的行中的数据返回，对SQL语句中存在RETURNING子句时，在动态执行时可以使用RETURNING INTO来接收。
⑤ 动态执行参数中可以是：[:数字]也可以是[:字符串]。

## 6.PL/SQL的异常处理

### 预定义异常：

![1561544856706](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561544856706.png)

**语法：**

![1561544877709](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561544877709.png)

### 自定义异常：

 异常定义：在PL/SQL块的声明部分采用EXCEPTION关键字声明异常，定义方法与定义变量相同。比如声明一个myexception异常方法是：
											myexception EXCEPTION；
 异常引发：在程序可执行区域，使用RAISE关键字进行引发。比如引发myexception方法是：
											RAISE myexception;

**示例：**

![1561544981220](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561544981220.png)

① 用EXCEPTION定义一个异常变量myexp
② 在一定条件下用RAISE引发异常myexp
③ 在异常处理部分，捕获异常，如果不处理异常，该异常就抛给程序执行者。

### 引发应用程序异常：

**示例：**

![1561545539625](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561545539625.png)

① 把异常名称null_salary与异常码-20101关联，该语句由于是预编译语句，必须放在声明部分。也就是说-20101的异常名称就是null_salary。
② 嵌套PL/SQL语句块
③ 在内部PL/SQL语句块中引发应用系统异常-20101。
④ 在外部的PL/SQL语句块中就可以用异常名null_salary进行捕获。

### 本章总结

 PL/SQL是一种块结构的语言，它将一组语句放在一个块中，一次性发送给服务器，PL/SQL引擎把接收到PL/SQL语句块中的内容进行分析，把其中的过程控制语句由PL/SQL引擎自身去执行，把PL/SQL语句块中的SQL语句交给服务器的SQL语句执行器执行。
 PL/SQL的数据类型包括标量数据类型，引用数据类型和存储文本、图像、视频、声音等非结构化得大数据类型（LOB数据类型）等。
 Oracle中存在两种属性类型：%TYPE和%ROWTYPE。
 PL/SQL程序可通过控制结构来控制命令执行的流程。PL/SQL中提供三种程序结构：顺序结构、条件结构和循环结构。
 在PL/SQL程序开发中，可以使用DML语句和事务控制语句，还可以动态执行SQL语句，动态执行SQL语句的命令是：EXECUTE IMMEDIATE。
 在程序运行时出现的错误，称为异常。发生异常后，语句将停止执行，PL/SQL引擎立即将控制权转到PL/SQL块的异常处理部分。PL/SQL中任何异常出现时，每一个异常都对应一个异常码和异常信息。

# 第6章 数据库的导入导出