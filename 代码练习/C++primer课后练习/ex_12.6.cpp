#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

vector<int>*
dynamic_vector_generator();

void
dynamic_vector_processor(vector<int>* ptr_v);

void 
dynamic_vector_printer(vector<int>* ptr_v);

//ÖÇÄÜÖ¸Õë
void
dunamic_vector_processor_ai(shared_ptr<vector<int> > sptr_vi);

void 
dynamic_vector_printer_ai(shared_ptr<vector<int> > sptr_vi); 

int main(){
	vector<int>* ptr_vi=dynamic_vector_generator();
	dynamic_vector_processor(ptr_vi);
	dynamic_vector_printer(ptr_vi);
	//Íü¼ÇÉ¾³ý
	delete ptr_vi; 
	return 0;
}

vector<int>* dynamic_vector_generator(){
	auto ptr_v=new vector<int>();
	return ptr_v;
}

void dynamic_vector_processor(vector<int>* ptr_v){
		int i;
	cout<<"you enter:"<<endl;
	while(cin>>i&&i!=999){
		ptr_v->push_back(i);
	}
}

void dynamic_vector_printer(vector<int>* ptr_v){
	for(const auto &e:*ptr_v){
		cout<<e<<" ";
	}
	cout<<"\n";
}
