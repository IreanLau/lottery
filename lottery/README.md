调用php接口 获取http://f.apiplus.cn/hljssc.json(开采网站)的json数据
json数据集保存在result.txt文本中 jsonObj => buffer
fd完成读取result.txt buffer->string->json::value
until对象读取
持久化到redis
使用json库将数据解析
本地数据对象做持久话



