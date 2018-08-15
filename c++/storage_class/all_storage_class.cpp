#include <iostream>
#include <stdio.h>
using namespace std;

static int stream_size;
int main(int argc, char const *argv[])
{
	int streams = 2;
	int& stream_le = streams;
	{
		if (stream_size == 0 ) {
			cout << "stream size is empty  \n" ;
			stream_size = 23;
		}
		register int stream_length = 56;
		stream_le = stream_length;
	}

	cout << streams << " " << stream_size << " "  << stream_le << '\n';

	int capSize;
	auto char * capColor;
	register int capStockCount;
	static int price;
	// mutable int isMaleCap;
	cout << " 1------------------------------------- " << '\n';
	cout << capSize << " "  << capColor << " " << capStockCount << " " << price << '\n';
	cout << " 2------------------------------------- " << '\n';
 	

 	printf("capSize \t\t: %d\n", capSize);
	printf("capColor \t\t: %s\n",capColor);
	printf("capStockCount \t\t: %d\n",capStockCount);
	printf("price \t\t: %d \n", price );
	// printf("isMaleCap : %d \n",isMaleCap);

	capSize = 30;
	capColor = "blue";
	capStockCount = 12 * 5;
	price = 100;
	// isMaleCap = 1;
	cout << " 3------------------------------------- " << '\n';
	cout << capSize << " "  << capColor << " " << capStockCount << " " << price << '\n';
	cout << " ------------------------------------- " << '\n';

	printf("capSize \t\t: %d\n", capSize);
	printf("capColor \t\t: %s\n",capColor);
	printf("capStockCount \t\t: %d\n",capStockCount);
	printf("price \t\t: %d \n", price );


	return 0;
	
}

