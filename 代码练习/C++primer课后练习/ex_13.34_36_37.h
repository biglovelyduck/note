#ifndef _ex_1334_36_37_h_
#define _ex_1334_36_37_h_
#include <string>
#include <set>
using namespace std;
class Folder;
class Message{
	friend void swap(Message &,Message &);//自定义的swap 
	friend void swap(Folder &,Folder &);
	friend class Folder;
public:
	//单个参数的构造函数并且防止赋值拷贝 
	explicit Message(const string &str=""):contents(str){}
	Message(const Message&);//拷贝构造函数
	Message& operator=(const Message&);//将本消息替换为参数的消息 
	~Message();
	
	void save(Folder&);//将新的folder保存在set中 
	void remove(Folder&);
	void print_debug(); 
private:
	string contents;
	set<Folder*> folders;
	
	void add_to_Folders(const Message&);//将本消息添加到指向引用的Folder中，Folder里有很多消息
	//在此多添加一条消息 
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
	Folder()=default;//使用默认的无参构造函数
	Folder(const Folder&);
	Folder& operator=(const Folder&);
	~Folder(); 
	
	void print_debug();
private:
	set<Message*> msgs;
	
	void add_to_Message(const Folder&);//将本消息添加到所有的Folder集合里 
	void remove_to_Message();//将本消息从所有的Folder中移除 
	
	void addMsg(Message *m){msgs.insert(m);} 
	void remMsg(Message *m){msgs.erase(m);}
};
#endif
