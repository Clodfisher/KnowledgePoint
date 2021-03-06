# KnowledgePoint
To work and study knowledge needed to carry out the preparation of the sample。    
***
*说明*：    
此仓库，主要用于自己工作于学习中对于设计到的知识点，来编写一些小的demo，进行正确性测试，从而更好的辅助自己的学习和工作。以下将对每个demo以目录的形式进行简单的说明，对于demo的使用背景和涉及到的具体知识点说明，参考相应的README和代码注释。对于目录结构的建立可能根据demo涉及到的知识点分类设计。        

**目录结构**   
-*STL*-----:主要用于stl模板的样例测试    
|-[hashmapKey64](https://github.com/Clodfisher/KnowledgePoint/tree/master/STL/hashmapKey64):用于对hashmap容器进行扩增，使其能够支持key为int64和string类型        
 
-*Time*-----:主要用于关于时间的样例测试       
|-[GetTime.cpp](https://github.com/Clodfisher/KnowledgePoint/blob/master/Time/GetTime.cpp):用于对linux中的本地时间的秒、微妙、时区取得以及转换打印操作    

-*NetDevice*-----:主要用于网络设备样例测试           
|-[ioctl.c](https://github.com/Clodfisher/KnowledgePoint/blob/master/NetDevice/ioctl.c):根据指定的网卡名，通过ioctl获取此网卡设备的IP地址、广播地址、掩码地址、MAC地址    
|-[getifaddres.c](https://github.com/Clodfisher/KnowledgePoint/blob/master/NetDevice/getifaddres.c):通过getifaddres用于获取主机中的所有网卡名和网卡ip，以及通过网卡名取得网卡的唯一标识    
|-[getifaddres1.c](https://github.com/Clodfisher/KnowledgePoint/blob/master/NetDevice/getifaddres1.c):采用getifaddres取得linux设备网卡中的一些信息    


-*CBase*-----:主要用于测试C语言的基本语法    
|-[PointVsArr/PointVsArr.c](https://github.com/Clodfisher/KnowledgePoint/tree/master/CBase/PointVsArr):用于测试，数组指针与数组名之间的关系     
|-[define.cpp](https://github.com/Clodfisher/KnowledgePoint/blob/master/CBase/define.cpp):用于测试字符从的连接性，以及指编译器能够识别的最小语法单元（子串的连接），知识点参见[c语言宏定义的连接符##和#转字符串](http://blog.csdn.net/faithmy509/article/details/3914026)   

-*File*-----:主要用于测试对配置文件的读取操作        
|-[IpMac](https://github.com/Clodfisher/KnowledgePoint/tree/master/File/IpMac):用于测试，通过读取配置文件，实现对静态ARP数据的读取，获得IP与MAC的对应关系    
|-[CreatDirs](https://github.com/Clodfisher/KnowledgePoint/blob/master/File/CreatDirs/CreateDirs.cpp):用于测试，创建级联的多级子目录程序     

-*ParseArg*-----:主要用于对程序参数进行解析，方便配置以及调试等               
|-[parse.cpp](https://github.com/Clodfisher/KnowledgePoint/blob/master/ParseArg/parse.cpp):用于测试，本程序用于对参数进行解析，对于此函数的详细解释，可参照*《Linux 高级程序设计中文第三版》*杨宗德 P64                   
      
-*module*-----:主要用于产品开发中对于模块化的思考和设计                   
|-[jmp_buf.cpp](https://github.com/Clodfisher/KnowledgePoint/blob/master/module/jmp_buf.cpp):用于测试，跨函数跳转（长跳转）：场景则常见于多进程的模块化处理系统中，用于回到特定（初始）状态。    

-*Shell*-----:主要用于测试开发中一些脚本的应用            
|-[S96lspci](https://github.com/Clodfisher/KnowledgePoint/tree/master/Shell/S96lspci):用于测试，开机启动时，是否所有的网卡都挂在正确，若没有自动进行IP设置，脚本用于放置/etc/init.d/目录下                          
      





