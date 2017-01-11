#ifndef _ELEMENT_H_
#define _ELEMENT_H_


#include<iostream>
#include"my_json.h"
using namespace std;

class element{
	public:
		element(){}
		~element(){}

		int val_to_str(std::string &_out);
		int str_to_val(std::string &_in);
		
		const string& get_expect(){return this->expect;}
		const string& get_opencode (){return this->opencode;};
		const string& get_opentime (){return this->opentime;};
		const string& get_opentimestamp (){return this->opentimestamp;};
	
		void set_expect (const string& _expect )
		{this->expect = _expect;};
		void set_opencode (const string&  _opencode)
		{this->opencode = _opencode;};
		void set_opentime (const string& _opentime)
		{this->opentime = _opentime;};
		void set_opentimestamp(const string& _opentimestamp)
		{this->opentimestamp = _opentimestamp;};
		
		string& toString();

		string& getStringMsg();
	private:
		my_json json_bit;	
	
		string	expect;			//开奖期数
		string	opencode;		//开奖号码
		string	opentime;		//日期
		string	opentimestamp;	//时间戳
		
		//相当与java的toString方法 存储需要的值
		string stringMsg;
};

int element::val_to_str(std::string &_out)
{
	Json::Value _val;
	_val["expect"]		  = this->expect;
	_val["opencode"]      = this->opencode;
	_val["opentime"]	  = this->opentime;
	_val["opentimestamp"] = this->opentimestamp;
	json_bit.serialize(_val, _out);
}

int element::str_to_val(std::string &_in)
{
	Json::Value _val;
	json_bit.deserialize(_in, _val);
	this->expect		= _val["expect"].asString();
	this->opencode		= _val["opencode"].asString();
	this->opentime		= _val["opentime"].asString();
//	this->opentimestamp = _val["opentimestamp"].asString();
}


string& element::getStringMsg()
{
//	this->stringMsg="开彩期号:";
//	stringMsg+=this->expect;
//	stringMsg+=" 开彩号码:";
//	stringMsg+=this->opencode;
//	stringMsg+=" 开彩日期:";
//	stringMsg+=this->opentime;
//
	this->stringMsg="";
	stringMsg+=this->expect;
	stringMsg+=" ";
	stringMsg+=this->opencode;
	stringMsg+=" ";
	stringMsg+=this->opentime;
	
	return this->stringMsg;
}
#endif
