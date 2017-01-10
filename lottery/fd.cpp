#include<string.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<json/json.h>
#include<hiredis/hiredis.h>
#include<vector>
#include<list>
#include"common/element.h"
#include "redisclient.h"
#include "anet.h" 

#include <iostream>  
#include <boost/date_time.hpp>  
using namespace boost;  
using namespace std;  
static size_t _count = 0;
const string RedisDSName = "lottery";

//redis连接函数
shared_ptr<redis::client> connect_client();

int main(int argc,char* argv[])
{
	Json::Reader reader;
	Json::FastWriter writer;
	Json::Value value;
	shared_ptr<redis::client> c;
	c = connect_client();
	int fd = open("./result.txt",O_CREAT|O_RDWR,0755);
	FILE *fp = fopen("./result.txt","r+b"); 
	if(fd<0)
	{
		perror("open");
		exit(1);
	}

#ifdef _DEBUG_
	printf("fd:> %d\n",fd);
#endif

	char buf[1024];
	memset(buf,0,sizeof(buf));

	ssize_t ret;
	ret = fread(buf,sizeof(buf),1,fp);
	close(fd);
//	if(ret==0)
//	{
//		cout<<"check you networking...."<<endl;
//		return 0;
//	}
	
	string str(buf);	
	
	if(reader.parse(str,value))	
	{
		Json::Value msg = value["data"];
		int num = value["rows"].asInt();

		vector<element> ele_vec;	
		for(int i=0;i<num;++i)
		{
			string strByJson = writer.write(msg[i]);
			element ele;
			ele.str_to_val(strByJson);
			if(ele.getStringMsg().size() != 0)
				cout<<ele.getStringMsg()<<endl;
			else 
				cout<<"toString is NULL"<<endl;

			//缓存 使用redis Cpp支持库 boost支持库
			//itoa建立下标
			ostringstream  ostr;
			ostr << i ;
			string index(ostr.str());
			//缓存注入数据
			c->hset(RedisDSName,index,ele.getStringMsg());

			ele_vec.push_back(ele);

		}

//		cout<<"~~~~~~~~~~SIZE~~~~~~"<<ele_vec.size()<<endl;
//		for(int i=0;i<ele_vec.size();++i)	
//		{
//			cout<<ele_vec[i].getStringMsg()<<endl;
//		}
	}
	
//	if(_count+=ele_vec.size() = 30)
//	{
//		//_count到达阀值 
//		//做异步持久话处理 将redis的数据导入到mysql
//		//_count清零
//		_count = 0;
//	}

	else
	{
		cout<<"not have date,pelase check you networking...."<<endl;
	}
	return 0;
}


//shared_ptr<redis::client> connect_client()
//{
//	const char* c_host = getenv("REDIS_HOST");
//	string host = "localhost";
//	if(c_host)
//		host = c_host;
//
//	return boost::shared_ptr<redis::client>(new redis::client(host));
//}
//
