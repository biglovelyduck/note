#ifndef _ex_1334_36_37_h_
#define _ex_1334_36_37_h_
#include <string>
#include <set>
using namespace std;
class Folder;
class Message{
	friend void swap(Message &,Message &);//�Զ����swap 
	friend void swap(Folder &,Folder &);
	friend class Folder;
public:
	//���������Ĺ��캯�����ҷ�ֹ��ֵ���� 
	explicit Message(const string &str=""):contents(str){}
	Message(const Message&);//�������캯��
	Message& operator=(const Message&);//������Ϣ�滻Ϊ��������Ϣ 
	~Message();
	
	void save(Folder&);//���µ�folder������set�� 
	void remove(Folder&);
	void print_debug(); 
private:
	string contents;
	set<Folder*> folders;
	
	void add_to_Folders(const Message&);//������Ϣ��ӵ�ָ�����õ�Folder�У�Folder���кܶ���Ϣ
	//�ڴ˶����һ����Ϣ 
	void remove_from_Folders();
	
	void addFldr(Folder *f){
		folders.insert(f);
	}
	void remFldr(Folder *f){
		folders.erase(f);
	} 
};

class Folder{
	friend void swap(Message&,Message&);
	friend void swap(Folder&,Folder&);
	friend class Message;
public:
	Folder()=default;//ʹ��Ĭ�ϵ��޲ι��캯��
	Folder(const Folder&);
	Folder& operator=(const Folder&);
	~Folder(); 
	
	void print_debug();
private:
	set<Message*> msgs;
	
	void add_to_Message(const Folder&);//������Ϣ��ӵ����е�Folder������ 
	void remove_to_Message();//������Ϣ�����е�Folder���Ƴ� 
	
	void addMsg(Message *m){msgs.insert(m);} 
	void remMsg(Message *m){msgs.erase(m);}
};
#endif
