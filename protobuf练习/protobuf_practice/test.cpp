
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include"test.pb.h"
using namespace std;
using namespace myinfo;
using namespace itcast;

int main(int argc, char* argv[])
{
	//序列化
	Person p;
	//初始化对象
	p.set_id(1001);
		//添加一个名字--》申请一块内存
	p.add_name();
		//给添加的新名字设置值
	p.set_name( 0,"luffy");// name是一个数组，此处是把数组的0元素设置为"luffy"
	p.add_name();
	p.set_name(1, "艾斯"); //此处是把数组的1元素设置为"艾斯"
	p.set_sex ("man");
	p.set_age(18);
	p.set_color(MyColor::Blue);
		//设置info变量信息，间接设置
		//1.获取p对象中的info子对象的地址
	Info* in = p.mutable_info();
		//2.通过In指针修改对象中的数据
	in->set_num(666);
	in->set_infomation("航海王");
	//实现序列化
	string output;
	p.SerializeToString(&output);
	cout <<"序列化后的数据： "<< output << endl;

	//反序列化
	Person p1; 
	p1.ParseFromString(output);
	cout << "id:" << p1.id() << endl;
	for (int i = 0; i <p1.name_size(); i++)
	{
		cout<< "name:"<<i <<"->  "<< p1.name(i)<< endl;
	}
	cout<< "sex:" << p1.sex() <<endl<< "age" << p1.age() << endl<<"color:"<<p1.color()<<endl;
		//读取info信息
	Info in1 = p1.info(); //得到p1中的info数据
	cout << "info的num: " << in1.num() << endl << "info的information: " << in1.infomation() << endl;


	system("pause");
	return 0;
}
