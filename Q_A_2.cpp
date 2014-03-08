Q:  Give Cantor table and index,  output the content of the index in the Cantor table.


C++ Code

void GetCantorPos(int idx, int & x, int & y)
{
	int i = 1;
	static const int step[4][2] = {
		{ 1, 0 }, 
		{ -1, 1 },
		{ 0, 1 },
		{ 1, -1 }
	};
	int direct = 0;

	x = y = 0;

	while ( i<idx  ) {
		if( (x + step[direct][0] >= 0) && 
			(y + step[direct][1] >= 0 ) ){
			x += step[direct][0];
			y += step[direct][1];
			++i;

			if( (direct == 0) || (direct == 2) ){
				direct = (direct + 1) & 0x3;
			}
		} else {
			direct = (direct + 1) & 0x3;
		}
	}
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

		int idx = atoi(line.c_str());
		int x = 0, y = 0;
		if( idx < 0 ){
			continue;
		}

        GetCantorPos(idx, x, y);

		cout<<"x = "<<x<<", y = "<<y<<endl;

		fout<<idx<<","<<(x+1)<<"/"<<(y+1)<<endl;

		bOut = true;
	}
}

output:

3,1/2
14,4/2
7,4/1
12345,99/59