#调用php接口 获取http://f.apiplus.cn/hljssc.json(开采网站)的json数据
#json数据集保存在result.txt文本中 jsonObj => buffer
#fd完成读取result.txt buffer->string->json::value
#until对象读取
#持久化到redis
#使用json库将数据解析
#本地数据对象做持久话

#数据表结构
Create Table: CREATE TABLE `lottery` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `province` varchar(20) NOT NULL,
  `msg` varchar(80) NOT NULL,
  `createTime` timestamp NULL DEFAULT CURRENT_TIMESTAMP COMMENT '创建时间',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=latin1


#/home/lau/project/Irean/redis-mysql/test.cpp 测试将数据从redis注入mysql成功 等待调用

# find . -name "*" | xargs grep '^.' | wc -l 查看当前目录下的总行数
