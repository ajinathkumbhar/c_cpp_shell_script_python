#include <iostream>
#include <string.h>

class FlashScript {
private:
	const char * partition_name;
	int partition_size;
	const char * flag;
public:
	FlashScript() {
		std::cout << "default constructor" << '\n';
		this->partition_size = 0;
		this->partition_name = NULL;
		this->flag = 0x00;
	}
	FlashScript(const FlashScript& flashObj) {
		this->partition_name = flashObj.partition_name;
		std::cout << " copy constructor called " << '\n';
	}
	FlashScript& operator=(const FlashScript& flashObj) {
		std::cout << "operator = overload called " << '\n';
 	}
 	
};

int main(int argc, char const *argv[])
{
	FlashScript emmc_flash;
	FlashScript nor_flash = emmc_flash;
	FlashScript nand_flash ;

	nand_flash = nor_flash;
	return 0;
}

