
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include"test.pb.h"
using namespace std;

int main(int argc, char* argv[])
{
	//���л�
	Person p;
	//��ʼ������
	p.set_id(1001);
		//���һ������--������һ���ڴ�
	p.add_name();
		//����ӵ�����������ֵ
	p.set_name( 0,"luffy");// name��һ�����飬�˴��ǰ������0Ԫ������Ϊ"luffy"
	p.add_name();
	p.set_name(1, "��˹"); //�˴��ǰ������1Ԫ������Ϊ"��˹"
	p.set_sex ("man");
	p.set_age(18);
	p.set_color(MyColor::Blue);
	//ʵ�����л�
	string output;
	p.SerializeToString(&output);
	cout <<"���л�������ݣ� "<< output << endl;

	//�����л�
	Person p1; 
	p1.ParseFromString(output);
	cout << "id:" << p1.id() << endl;
	for (int i = 0; i <p1.name_size(); i++)
	{
		cout<< "name:"<<i <<"->  "<< p1.name(i)<< endl;
	}
	cout<< "sex:" << p1.sex() <<endl<< "age" << p1.age() << endl<<"color:"<<p1.color()<<endl;
	system("pause");
	return 0;
}
