#include <cstdio>
#include <set>
using namespace std;
bool contains0_9(int x){
	set<int> s;
	while(x){
		s.insert(x%10);
		x=x/10; 
	}
	if(s.size()==10) return true;
	return false;
}
int main(){
	int i;
	for(i=100000;i>=3000;i--){
		if(contains0_9(i*i)) break;
	}
	printf("%d",i*i);
} 
