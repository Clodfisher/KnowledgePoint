*说明*：    
此程序用来进行配置文件的读取，主要应用于对静态ARP表的获取。    
配置文件格式如下所示：    
IP  MAC    
IP , MAC    
IP ,, MAC    
IP      MAC    
请参考配置文件：[IpMac.conf](https://github.com/Clodfisher/KnowledgePoint/blob/master/File/IpMac/IpMac.conf)    
通过上述配置文件的读取，提取出相应的IP值与MAC的对于关系，别去实现了见MAC字符串转化成char[6]的形式。    

