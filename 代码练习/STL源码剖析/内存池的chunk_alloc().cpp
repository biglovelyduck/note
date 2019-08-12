/*chunk_alloc()函数从内存池申请空间，根据endfree-startfree判断内存池中剩余的空间

*如果剩余空间充足
	直接调出20个区块返回给free-list
*如果剩余空间不足以提供20个区块，但足够供应至少1个区块
	拨出这不足20个区块的空间
*如果剩余空间连一个区块都无法供应
	利用malloc()从heap中分配内存（大小为需求量的2倍，加上一个随着分配次数增加而越来越大的附加量），为内存池注入新的可用空间（详细例子见下图）
	如果malloc()获取失败，chunk_alloc()就四处寻找有无”尚有未用且区块足够大“的free-list。找到了就挖出一块交出
	如果上一步仍未成功，那么就调用第一级分配器，第一级分配器有out-of-memory处理机制，或许有机会释放其它的内存拿来此处使用。如果可以，就成功，否则抛出bad_alloc异常*/
	
	//假设size已经是当上调至8的倍数
	//注意参数nobjs是传引用
template <bool threads,int inst>
char* _default_alloc_template<threads,inst>::chunk_alloc(size_t size,int& nobjs){
	char* result;
	size_t total_types=size*nobjs;
	size_t bytes_left=end_free-start_free;//内存池剩余空间
	
	if(bytes_left>=total_bytes){
		//内存池剩余空间完全满足需求量
		result=start_free;
		start_free+=total_bytes;
		return (result); 
	} 
	else if(bytes_left>=size){
		//内存池剩余空间不能完全满足需求量
		//但是足够供应一个以上的区块 
		nobjs=bytes_left/size;
		total_bytes=size*nobjs;
		result=start_free;
		start_free+=total_bytes;
		return (result); 
	}
	else{
		//内存池剩余空间连一个区块的大小都无法提供
		size_t bytes_to_get=2*total_bytes+ROUND_UP(heap_size>>4); 
		//以下试着让内存池的参与零头还有利用价值
		if(bytes_left>0){
			//内存池还有一些零头，先配给适当的free list
			//首先寻找适当的free list
			obj *volatile * my_free_list=free_list+FREELIST_INDEX(bytes_left); 
			//调整free_list,将内存池的参与空间编入
			((obj *)start_free)->free_list_link=*my_free_list;
			*my_free_list=(obj*)start_free; 
		} 
		
		//配置heap空间，用来补充内存池
		start_free=(char*)malloc(bytes_to_get); 
		if(0==start_free){
			//heap空间不足,malloc()失败
			int i;
			obj * volatile * my_free_list,*p;
			//以下搜寻适当的free_list
			//所谓适当是指尚有未用区块，且区块足够大值free_list
			for(i=size;i<=__MAX_BYTES;i+=__ALIGN) {
				my_free_list=free_list+FREELIST_INDEX(i);
				p=*my_free_list;
				if(0!=p){
					//free_list尚有未用区块,调整free list以释放出未用区块 
					*my_free_ist=p->free_list_link;
					start_free=(char*)p;
					end_free=start_free+i;
					//递归调用自己，为了修正nobjs
					return (chunk_alloc(size,nobjs)); 
				}
			}
			end_free=0;//如果山穷水尽，到处都没有内存可用
			//调用第一级配置器，看看out_of_memory能否尽点力
			start_free=(char*)malloc_alloc::allocate(bytes_to_get); 
		}
		heap_size+=bytes_to_get;
		end_free=start_free+bytes_to_get;
		return (chunk_alloc(size,nobjs));
	}
}

