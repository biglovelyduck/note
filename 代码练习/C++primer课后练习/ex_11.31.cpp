
#include <map>
#include <string>
#include <iostream>
using namespace std;
int main(){
	multimap<string,string> authors{
		{"alan", "DMA"},
        {"pezy", "LeetCode"},
        {"alan", "CLRS"},
        {"wang", "FTP"},
        {"pezy", "CP5"},
        {"wang", "lllll"}
	};//alan��pezy���������� 
	string author = "pezy";
    string work = "CP5";
    auto found=authors.find(author);//��map�ĵ����� 
	auto count=authors.count(author);
	while(count){
		if(found->second==work){
			authors.erase(found);//���ݵ�����ɾ��λ��
			break; 
		}
		++found;//��������һ 
		--count;
	}
	if(found!=authors.end())
		cout<<found->second<<endl;
	for(const auto &author:authors){
		cout<<author.first<<" "<<author.second<<endl;
	}
	return 0;
} 
/*
#include <map>
#include <string>
#include <iostream>

using std::string;

int main()
{
    std::multimap<string, string> authors{
        {"alan", "DMA"},
        {"pezy", "LeetCode"},
        {"alan", "CLRS"},
        {"wang", "FTP"},
        {"pezy", "CP5"},
        {"wang", "CPP-Concurrency"}
    };
    // want to delete an element that author is [Alan], work is [112].
    string author = "pezy";
    string work = "CP5";
    
    auto found = authors.find(author);
    auto count = authors.count(author);
    while (count) {
        if (found->second == work) {
            authors.erase(found);
            break;   
        }
        ++found;
        --count;
    }
    
    for (const auto &author : authors)
        std::cout << author.first << " " << author.second << std::endl;
}*/
