#include<stdio.h>
#include<string>
#include <iostream>
main() {
std::string fs_mgr_flags = "wait,verify";
std::string verify_1 = ",verify";
std::string verify_2 = "verify,";

size_t pos = fs_mgr_flags.find(verify_1);
std::cout << " pos : " << pos << std::endl;

if ( pos != std::string::npos ) {
   std::cout << " eraseing ...1 " << std::endl;
   fs_mgr_flags.erase(pos,verify_1.length());
}

pos = fs_mgr_flags.find(verify_2);
std::cout << " pos : " << pos << std::endl;

if ( pos != std::string::npos ) {
   std::cout << " eraseing ...2 " << std::endl;
   fs_mgr_flags.erase(pos,verify_2.length());
}

std::cout << " final string : " << fs_mgr_flags << std::endl;
}
