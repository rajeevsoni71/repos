#include <iostream>
#include <string>
#include <type_traits>

// it can be used in both template and without template function

//They cannot be used as global scope means they can only be used inside a function

template<typename T>
void print(const T& value) {
	if constexpr (std::is_pointer_v<T> == true) {
		std::cout << "Pointer: " << *value << std::endl;
	}
	else if constexpr (std::is_array_v<T> == true)
	{
		std::cout << "Array: ";
		for (const auto& elements : value)
			std::cout << elements << " ";
		std::cout << std::endl;
	}
	else {
		std::cout << "Integral: " <<value << std::endl;
	}
}

template<typename t>
std::string TOString(t value) {
	if constexpr (std::is_arithmetic_v<t> == true) {
		return std::to_string(value);
	}
	else {
		return std::string{value};
	}
}

//check with non template function
void checkMode() {
	if constexpr (sizeof(void*) == 4) {
		std::cout << "32 bit Mode " << std::endl;
	}
	else if  constexpr (sizeof(void*) == 8) {
		std::cout << "64 bit Mode " << std::endl;
	}
	else {
		std::cout << "Unknown Mode " <<std::endl;
	}
}


int main() {
	int a{ 90 };
	print(&a);
	print(a);
	int arr[] {1,2,3,4,5};
	print(arr); // with out constexpr in if only this will build and run as arr can be pointer and array both

	auto s= TOString(a);
	print(s);

	checkMode();
	return 0;
}

/*
* if you use constexpr then the compiler wouldn't generate
* code for the statement which doesn't statisfy the condition
* EXAMPLE:
check with non template function
void checkMode() {
008825A0  push        ebp  
008825A1  mov         ebp,esp  
008825A3  sub         esp,0C4h  
008825A9  push        ebx  
008825AA  push        esi  
008825AB  push        edi  
008825AC  lea         edi,[ebp-0C4h]  
008825B2  mov         ecx,31h  
008825B7  mov         eax,0CCCCCCCCh  
008825BC  rep stos    dword ptr es:[edi]  
008825BE  mov         ecx,offset _E41A3387_Source@cpp (089602Bh)  
008825C3  call        @__CheckForDebuggerJustMyCode@4 (08813CFh)  
	if constexpr (sizeof(void*) == 4) {
		std::cout << "32 bit Mode " << std::endl;
008825C8  push        offset string "32 bit Mode " (088FC18h)  
008825CD  mov         eax,dword ptr [__imp_std::cout (08940E4h)]  
008825D2  push        eax  
008825D3  call        std::operator<<<std::char_traits<char> > (08812F8h)  
008825D8  add         esp,8  
008825DB  mov         dword ptr [ebp-0C4h],eax  
008825E1  mov         esi,esp  
008825E3  push        offset std::endl<char,std::char_traits<char> > (0881424h)  
008825E8  mov         ecx,dword ptr [ebp-0C4h]  
008825EE  call        dword ptr [__imp_std::basic_ostream<char,std::char_traits<char> >::operator<< (08940A4h)]  
008825F4  cmp         esi,esp  
008825F6  call        __RTC_CheckEsp (08813DEh)  
	}
	else if constexpr (sizeof(void*) == 8) {
		std::cout << "64 bit Mode " << std::endl;
	}
	else {
		std::cout << "Unknown Mode " <<std::endl;
	}
}
*/

/*
* But if you remove the constexpr then compiler will generate the code for each statement
* EXAMPLE:
//check with non template function
void checkMode() {
003B25A0  push        ebp
003B25A1  mov         ebp,esp
003B25A3  sub         esp,0C4h
003B25A9  push        ebx
003B25AA  push        esi
003B25AB  push        edi
003B25AC  lea         edi,[ebp-0C4h]
003B25B2  mov         ecx,31h
003B25B7  mov         eax,0CCCCCCCCh
003B25BC  rep stos    dword ptr es:[edi]
003B25BE  mov         ecx,offset _E41A3387_Source@cpp (03C602Bh)
003B25C3  call        @__CheckForDebuggerJustMyCode@4 (03B13CFh)
	if (sizeof(void*) == 4) {
003B25C8  mov         eax,1
003B25CD  test        eax,eax
003B25CF  je          checkMode+66h (03B2606h)
		std::cout << "32 bit Mode " << std::endl;
003B25D1  push        offset string "32 bit Mode " (03BFC18h)
003B25D6  mov         eax,dword ptr [__imp_std::cout (03C40E4h)]
003B25DB  push        eax
003B25DC  call        std::operator<<<std::char_traits<char> > (03B12F8h)
003B25E1  add         esp,8
003B25E4  mov         dword ptr [ebp-0C4h],eax
003B25EA  mov         esi,esp
003B25EC  push        offset std::endl<char,std::char_traits<char> > (03B1424h)
003B25F1  mov         ecx,dword ptr [ebp-0C4h]
003B25F7  call        dword ptr [__imp_std::basic_ostream<char,std::char_traits<char> >::operator<< (03C40A4h)]
003B25FD  cmp         esi,esp
003B25FF  call        __RTC_CheckEsp (03B13DEh)
	}
003B2604  jmp         checkMode+0D2h (03B2672h)
	else if  (sizeof(void*) == 8) {
003B2606  xor         eax,eax
003B2608  je          checkMode+9Fh (03B263Fh)
		std::cout << "64 bit Mode " << std::endl;
003B260A  push        offset string "Pointer: " (03BFDD8h)
003B260F  mov         eax,dword ptr [__imp_std::cout (03C40E4h)]
003B2614  push        eax
003B2615  call        std::operator<<<std::char_traits<char> > (03B12F8h)
003B261A  add         esp,8
003B261D  mov         dword ptr [ebp-0C4h],eax
003B2623  mov         esi,esp
003B2625  push        offset std::endl<char,std::char_traits<char> > (03B1424h)
003B262A  mov         ecx,dword ptr [ebp-0C4h]
003B2630  call        dword ptr [__imp_std::basic_ostream<char,std::char_traits<char> >::operator<< (03C40A4h)]
003B2636  cmp         esi,esp
003B2638  call        __RTC_CheckEsp (03B13DEh)
	}
003B263D  jmp         checkMode+0D2h (03B2672h)
	else {
		std::cout << "Unknown Mode " <<std::endl;
003B263F  push        offset string "Integral: " (03BFD00h)
003B2644  mov         eax,dword ptr [__imp_std::cout (03C40E4h)]
003B2649  push        eax
003B264A  call        std::operator<<<std::char_traits<char> > (03B12F8h)
003B264F  add         esp,8
003B2652  mov         dword ptr [ebp-0C4h],eax
003B2658  mov         esi,esp
003B265A  push        offset std::endl<char,std::char_traits<char> > (03B1424h)
003B265F  mov         ecx,dword ptr [ebp-0C4h]
003B2665  call        dword ptr [__imp_std::basic_ostream<char,std::char_traits<char> >::operator<< (03C40A4h)]
003B266B  cmp         esi,esp
003B266D  call        __RTC_CheckEsp (03B13DEh)
	}
}
*/