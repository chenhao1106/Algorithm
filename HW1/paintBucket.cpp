#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

int picture[100000000];
short int mark[100000000] = { 0 };
int main( int argc, char** argv )
{
	int i;
	int temp;
	int w, h;
	int x, y, pos, color;
	ifstream fileIn;
	ofstream fileOut;
	vector< vector< int > > link; 
	queue< int > test;
	vector< int >::iterator p;

	fileIn.open( argv[1], ios::in | ios::binary );
	
	fileIn >> w >> h;

	//picture = new int[w * h];
	//mark = new int[w * h];

	for( i = 0; i < w * h; i++ ){
		fileIn >> hex >> picture[i];
	}

	fileIn.close();
	
	/*for( i = 0; i < w * h; i++ ){
		cout << mark[i] << "\t";
		if( i % w == ( w - 1 ) ){
			cout << "\n";
		}
	}*/

	x = atoi( argv[2] );
	y = atoi( argv[3] );
	pos = y * w + x;
		
	vector< int > changelink;
	
	test.push( pos );
	mark[pos] = 1;
	while( test.size() != 0 ){
		temp = test.front();
		changelink.push_back( temp );
		test.pop();
		if( ( temp - 1 ) % w != w - 1 && picture[temp] == picture[temp - 1] && mark[temp - 1] == 0 ){
			test.push( temp - 1 );
			mark[temp - 1] = 1;
		}
		if( ( temp - w ) > 0 && picture[temp] == picture[temp - w] && mark[temp - w] == 0 ){
			test.push( temp - w );
			mark[temp - w] = 1;
		}			
		if( ( temp + 1 ) % w != 0 && picture[temp] == picture[temp + 1] && mark[temp + 1] == 0 ){
			test.push( temp + 1 );
			mark[temp + 1] = 1;
		}
		if( ( temp + w ) < w * h  && picture[temp] == picture[temp + w] && mark[temp + w] == 0 ){
			test.push( temp + w );
			mark[temp + w] = 1;
		}
	}
	//cout << "Change color DONE\n";

	color = strtol( argv[4], NULL, 16 );
	for( p = changelink.begin(); p != changelink.end(); p++ ){
		picture[*p] = color;
	}

	for( i = 0; i < w * h; i++ ){
		vector< int > templink;
		if( mark[i] <= 1 ){
			test.push( i );
			mark[i] = link.size();
			while( test.size() != 0 ){
				temp = test.front();
				templink.push_back( temp );
				test.pop();

				if( ( temp - 1 ) % w != w - 1 && picture[temp] == picture[temp - 1] && mark[temp - 1] <= 1 ){
					test.push( temp - 1 );
					mark[temp - 1] = 2;
				}
				if( ( temp - w ) > 0 && picture[temp] == picture[temp - w] && mark[temp - w] <= 1 ){
					test.push( temp - w );
					mark[temp - w] = 2;
				}
				if( ( temp + 1 ) % w != 0 && picture[temp] == picture[temp + 1] && mark[temp + 1] <= 1 ){
					test.push( temp + 1 );
					mark[temp + 1] = 2;
				}
				if( ( temp + w ) < w * h  && picture[temp] == picture[temp + w] && mark[temp + w] <= 1 ){
					test.push( temp + w );
					mark[temp + w] = 2;
				}
			}
			link.push_back( templink );
		}
	}

	//cout << "Connected DONE\n";
	fileOut.open( argv[5], ios::out );

	fileOut << dec << w << " " << h << "\n";
	for( i = 0; i < w * h; i++ ){
		fileOut << hex << uppercase << picture[i] << " ";
		if( i % w == w - 1 ){
			fileOut << "\n";
		}
	}

	fileOut << dec << link.size();
	fileOut.close();
}