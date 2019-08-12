/*chunk_alloc()�������ڴ������ռ䣬����endfree-startfree�ж��ڴ����ʣ��Ŀռ�

*���ʣ��ռ����
	ֱ�ӵ���20�����鷵�ظ�free-list
*���ʣ��ռ䲻�����ṩ20�����飬���㹻��Ӧ����1������
	�����ⲻ��20������Ŀռ�
*���ʣ��ռ���һ�����鶼�޷���Ӧ
	����malloc()��heap�з����ڴ棨��СΪ��������2��������һ�����ŷ���������Ӷ�Խ��Խ��ĸ���������Ϊ�ڴ��ע���µĿ��ÿռ䣨��ϸ���Ӽ���ͼ��
	���malloc()��ȡʧ�ܣ�chunk_alloc()���Ĵ�Ѱ�����ޡ�����δ���������㹻�󡰵�free-list���ҵ��˾��ڳ�һ�齻��
	�����һ����δ�ɹ�����ô�͵��õ�һ������������һ����������out-of-memory������ƣ������л����ͷ��������ڴ������˴�ʹ�á�������ԣ��ͳɹ��������׳�bad_alloc�쳣*/
	
	//����size�Ѿ��ǵ��ϵ���8�ı���
	//ע�����nobjs�Ǵ�����
template <bool threads,int inst>
char* _default_alloc_template<threads,inst>::chunk_alloc(size_t size,int& nobjs){
	char* result;
	size_t total_types=size*nobjs;
	size_t bytes_left=end_free-start_free;//�ڴ��ʣ��ռ�
	
	if(bytes_left>=total_bytes){
		//�ڴ��ʣ��ռ���ȫ����������
		result=start_free;
		start_free+=total_bytes;
		return (result); 
	} 
	else if(bytes_left>=size){
		//�ڴ��ʣ��ռ䲻����ȫ����������
		//�����㹻��Ӧһ�����ϵ����� 
		nobjs=bytes_left/size;
		total_bytes=size*nobjs;
		result=start_free;
		start_free+=total_bytes;
		return (result); 
	}
	else{
		//�ڴ��ʣ��ռ���һ������Ĵ�С���޷��ṩ
		size_t bytes_to_get=2*total_bytes+ROUND_UP(heap_size>>4); 
		//�����������ڴ�صĲ�����ͷ�������ü�ֵ
		if(bytes_left>0){
			//�ڴ�ػ���һЩ��ͷ��������ʵ���free list
			//����Ѱ���ʵ���free list
			obj *volatile * my_free_list=free_list+FREELIST_INDEX(bytes_left); 
			//����free_list,���ڴ�صĲ���ռ����
			((obj *)start_free)->free_list_link=*my_free_list;
			*my_free_list=(obj*)start_free; 
		} 
		
		//����heap�ռ䣬���������ڴ��
		start_free=(char*)malloc(bytes_to_get); 
		if(0==start_free){
			//heap�ռ䲻��,malloc()ʧ��
			int i;
			obj * volatile * my_free_list,*p;
			//������Ѱ�ʵ���free_list
			//��ν�ʵ���ָ����δ�����飬�������㹻��ֵfree_list
			for(i=size;i<=__MAX_BYTES;i+=__ALIGN) {
				my_free_list=free_list+FREELIST_INDEX(i);
				p=*my_free_list;
				if(0!=p){
					//free_list����δ������,����free list���ͷų�δ������ 
					*my_free_ist=p->free_list_link;
					start_free=(char*)p;
					end_free=start_free+i;
					//�ݹ�����Լ���Ϊ������nobjs
					return (chunk_alloc(size,nobjs)); 
				}
			}
			end_free=0;//���ɽ��ˮ����������û���ڴ����
			//���õ�һ��������������out_of_memory�ܷ񾡵���
			start_free=(char*)malloc_alloc::allocate(bytes_to_get); 
		}
		heap_size+=bytes_to_get;
		end_free=start_free+bytes_to_get;
		return (chunk_alloc(size,nobjs));
	}
}

