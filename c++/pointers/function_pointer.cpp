#include<stdio.h>
#ifndef OTP_SIZE
#define OTP_SIZE 12
#endif

void dump_otp(const char **otp) {
	int otpIdx = 0;
	while(otpIdx < 12) {
		printf("%s\n",otp[otpIdx++]);
	}	

}

int main(int argc, char * argv[]){
	void (*otp_data_print)(const char ** data);
	const char * otp_data[] = {
		"QWE","123","asdf","@#$",
		"1WE","q23","asKf","@E$",
		"2WE","s23","adUf","@D$"
	};
	
	otp_data_print = dump_otp;
	printf("------------- OTP data start----------------\n");
	otp_data_print(otp_data);
	printf("------------- OTP data end ----------------\n");

return 0;
}

// char * (*getModelNumber)(int board);
