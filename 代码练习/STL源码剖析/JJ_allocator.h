//���һ���򵥵Ŀռ�������
#ifndef __JJALLOC__
#define __JJALLOC__
#include <new> //for placement new
#include <cstddef>//for ptrdiff_t,size_t 
/*���������͵Ĳ�����������Ǹ��Ե���;��size_t ��������ָ�����鳤��,
��������һ������;ptrdiff_t ������Ӧ��֤���Դ��ͬһ����������ָ��֮��Ĳ��,
���п����Ǹ�����*/
#include <cstdlib>//for exit()
#include <climits> //for UINT_MAX <climits>����ķ��ų����ļ���ֵ
#include <iostream> 

namespace JJ{
	
	template <class T>
	inline T* _allocate(ptrdiff_t size,T*){
		set_new_handler(0);//�����ڴ�ռ�ʧ��ʱ�������κκ���
		T* tmp=(T*)(::operator new((size_t)(size*sizeof(T))));
		if(tmp==0){
			cerr<<"out of memory"<<endl;
			exit(1);//ֻҪ���ֲ���0���Ƿ������˳� 
		}
		return tmp; 
	}
	
	template <class T>
	inline void _deallocate(T* buffer){
		::operator delete(buffer);
	}
	
	template <class T1,class T2>
	inline void _construct(T1* p,const T2& value){
		new(p) T1(value);//���place new,��ָ��p��ָ����ڴ�ռ䴴��һ������ΪT1�Ķ���
		//���õĹ��캯������һ������Ϊconst T2&���������������ͣ��Ĳ���
		//��T1���͵�ָ��p��T2���͵�value���г�ʼ��
	}
	
	template <class T>
	inline void _destroy(T* ptr){
		ptr->~T();
	} 
	
	template <class T>
	class allocator{
	public:
		typedef T valye_type;
		typedef T* pointer;			//ָ��T���͵�ָ�� 
		typedef const T* const_pointer;
		typedef T& reference;		//T������ 
		typedef const T& const_reference;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;
		
		//���°�����u�ķ����� rebind allocator of type U
		template <class U>
		struct rebind{
			typedef allocator<U> other;
		};
		
		//hint used for locality ���ھֲ��Ե���ʾ
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
		
		//������ת��Ϊָ�� 
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
