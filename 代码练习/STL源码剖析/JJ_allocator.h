//设计一个简单的空间配置器
#ifndef __JJALLOC__
#define __JJALLOC__
#include <new> //for placement new
#include <cstddef>//for ptrdiff_t,size_t 
/*这两种类型的差别体现了它们各自的用途：size_t 类型用于指明数组长度,
它必须是一个正数;ptrdiff_t 类型则应保证足以存放同一数组中两个指针之间的差距,
它有可能是负数。*/
#include <cstdlib>//for exit()
#include <climits> //for UINT_MAX <climits>定义的符号常量的极限值
#include <iostream> 

namespace JJ{
	
	template <class T>
	inline T* _allocate(ptrdiff_t size,T*){
		set_new_handler(0);//申请内存空间失败时不调用任何函数
		T* tmp=(T*)(::operator new((size_t)(size*sizeof(T))));
		if(tmp==0){
			cerr<<"out of memory"<<endl;
			exit(1);//只要数字不是0就是非正常退出 
		}
		return tmp; 
	}
	
	template <class T>
	inline void _deallocate(T* buffer){
		::operator delete(buffer);
	}
	
	template <class T1,class T2>
	inline void _construct(T1* p,const T2& value){
		new(p) T1(value);//这叫place new,在指针p所指向的内存空间创建一个类型为T1的对象。
		//调用的构造函数接受一个类型为const T2&（或其他兼容类型）的参数
		//对T1类型的指针p用T2类型的value进行初始化
	}
	
	template <class T>
	inline void _destroy(T* ptr){
		ptr->~T();
	} 
	
	template <class T>
	class allocator{
	public:
		typedef T valye_type;
		typedef T* pointer;			//指向T类型的指针 
		typedef const T* const_pointer;
		typedef T& reference;		//T的引用 
		typedef const T& const_reference;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;
		
		//重新绑定类型u的分配器 rebind allocator of type U
		template <class U>
		struct rebind{
			typedef allocator<U> other;
		};
		
		//hint used for locality 用于局部性的提示
		pointer allocate(size_type n,const void* hint=0){
			return _allocate((difference_type)n,(pointer)0);
		} 
		
		void deallocate(pointer p,size_type n){
			_deallocate(p);
		} 
		
		void construct(pointer p,const T& value){
			_construct(p,value);
		}
		
		void destroy(pointer p){
			_destroy(p);
		}
		
		//将引用转换为指针 
		pointer address(reference x){
			return (pointer)&x;
		}
		
		const_pointer const_address(const_reference x){
			return size_type(UINT_MAX/sizeof(T));
		}
	private:
	};
}		//end of namespace JJ 

#endif		
