#include <iostream>
using namespace std;

//为vector类重载流插入运算符和提取运算符 
class vector
{ 
public :
	vector( int size =1 ) ;       
	~vector() ;
	int & operator[]( int i ) ;
	friend ostream & operator << ( ostream & output , vector & ) ;
	friend istream & operator >> ( istream & input, vector & ) ;
private :  
	int * v ;     
	int len ;
};

vector::vector( int size ) 
{ 
	if (size <= 0 || size > 100 )
	{ 
		cout << "The size of " << size << " is null !\n" ; abort() ;  
	}
	v = new int[ size ] ;  len = size ;
}

vector :: ~vector() 
{ 
	delete[] v ;  
	len = 0 ; 
}

int &vector::operator[]( int i ) 		
{ 
	if( i >=0 && i < len )  return v[ i ] ;
	cout << "The subscript " << i << " is outside !\n" ;  abort() ;
}
ostream & operator << ( ostream & output, vector & ary )
{ 
	for(int i = 0 ; i < ary.len ; i ++ )  
		output << ary[ i ] << "  " ;
	output << endl ;
	return output ;
}
istream & operator >> ( istream & input, vector & ary )	
{ 
	for( int i = 0 ; i < ary.len ; i ++ )  
		input >> ary[ i ] ;
	return  input ;
}

int main()
{ 
	int k ;
	cout << "Input the length of vector A :\n" ;     
	cin >> k ;
	vector A( k ) ;
	cout << "Input the elements of vector A :\n" ;     
	cin >> A ;
	cout << "Output the elements of vector A :\n" ;
	cout << A ;
	system("pause");
	return 0;
}

