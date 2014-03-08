Q: Implement an algorithm to count all valid (eg. properly opened and closed) combinations of N-pairs of parentheses.
	   (max running time is limited) EXAMPLE: input: 3 (eg, 3 pairs of parentheses) output: 4

A: (C++ code)

#include <string>
#include <iostream>
#include <fstream>

#include <assert.h>


using namespace std;


#define  MAX_LINE_SIZE  1024

#define  INVALID_INPUT_RETURN  \
    cout<<"Invalid input"<<endl; \
	return -1; 

bool validate(string str)
{
	if( str.size() <= 0 ){
		return false;
	}
	int size = str.size();
	const char * p = str.c_str();

	for( int i=0;i<size;i++ ){
		if( !isdigit(p[i]) ){
			return false;
		}
	}	

	return true;
}


int GetPattern(int value,  int l, int r, int & pattern)
{
	if( l == r ){
		if( l<value ){
			GetPattern(value, l+1, r, pattern);
		} else {
            ++pattern;
			return 0;
		}
	} else {
		assert(l>r);
		if( l<value ){
			GetPattern(value, l+1, r, pattern);
			GetPattern(value, l, r+1, pattern);
		} else {
			GetPattern(value, l, r+1, pattern);
		}
	}

	return 0;
}


int   GetPattern(int value, int & pattern)
{
    GetPattern(value, 0, 0, pattern);
	return 0;
}

int main(int argc, char ** argv)
{
	if( argc != 3 ){
		cout<<"Invalid input"<<endl;
		return -1;
	}

	ifstream fin(argv[1]);
	ofstream fout(argv[2]);
	string line;

	if( (!fin.is_open()) || (!fout.is_open()) ){
		INVALID_INPUT_RETURN;
	}

	while( !fin.eof() ){
		::getline(fin, line);

		if( !validate(line) ){
			continue;
		}

		int value = atoi(line.c_str());
		int pattern = 0;

		GetPattern(value, pattern);

		fout<<value<<","<<pattern<<endl;
		cout<<value<<","<<pattern<<endl;
	}

	return 0;
}


Output:
3,5
4,14
5,42
6,132
10,16796



