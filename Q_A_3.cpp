Q: input value, find the smallest double base palindrome(2<=base<=10), the double-base palindrome should be large than the value


A: C++ code

#include <string>
#include <iostream>
#include <fstream>

#include <assert.h>


using namespace std;


#define  MAX_LINE_SIZE  1024

#define  INVALID_INPUT_RETURN  \
    cout<<"Invalid input"<<endl; \
	return -1; 

const char* itoc[10] = 
{
	"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"
};

string GetValueOnBase(int value, int base)
{
    assert(base>=2);
	assert(base<=10);
	assert(value>0);

	std::string  str;  
	
	do {
		int k = value%base;		
		str = string(itoc[k]) + str;		
		value = value/base;
	} while (value > 0 );

	return str;
}

bool CheckPalindrome(string & str)
{
	const char * p = str.c_str();
	int size = str.size();

	int i=0;
	for( i=0;i<size/2;i++ ){
		if( p[i] != p[size-i-1] ){
			return false;
		}
	}
	return true;
}

bool CheckValidDoubleBasePalidrome(int value)
{
	int base = 2;
    int count = 0;
	for( ; base <=10; base ++ ){
		if( CheckPalindrome(GetValueOnBase(value, base)) ){
			count ++;
		}

		if( count >= 2 ){
			return true;
		}
	}

	return false;
}


int main(int argc, char ** argv)
{
    if( argc != 3 ){
        INVALID_INPUT_RETURN;
	}

	ifstream fin(argv[1]);
	ofstream fout(argv[2]);
	string   line;
	bool     bOut;

	if( (!fin.is_open()) || (!fout.is_open()) ){
		INVALID_INPUT_RETURN;
	}

	while( !fin.eof() ){
		::getline(fin, line);

		if( !validate(line) ){
			continue;
		}

		int k = atoi(line.c_str());

		while( k < 0x7fffffff ){
			if( CheckValidDoubleBasePalidrome(++k) ){
				bOut = true;
				cout<<line<<","<<k<<endl;

				fout<<line<<","<<k<<endl;

				break;
			}
		}		
	}

	return 0;
}
