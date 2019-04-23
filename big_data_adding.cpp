#include <iostream>


using namespace std;

size_t Get_Str_Size (char *str) {
	size_t char_counter = 0;
	while (*str++) {
		char_counter++;
	}
	return char_counter;
}

uint16_t Char_To_Dec (char digit) {
	return digit - '0';
}

char Dec_To_Char (uint16_t digit) {
	return digit + '0';
}

uint16_t Summ (const uint16_t &a, const uint16_t &b, uint16_t &summ, uint16_t c) {
	if ((a + b +c) > 9) {
		summ = (a + b + c) - 10;
		return 1;
	}
	else {
		summ = a + b +c;
		return 0;
	}
}

void String_Reversing(char *data) {
	auto *p_Input_String = data;
	auto Symbol_Counter = 0;
	
	Symbol_Counter = Get_Str_Size (data);
	p_Input_String = data;
	auto Temp = *p_Input_String;
	for (auto i = 0; i < Symbol_Counter / 2; ++i) {
		Temp = *(p_Input_String + (Symbol_Counter - 1 - i));//сохран€ем последний символ текущей итерации 
		*(p_Input_String + (Symbol_Counter - 1 - i)) = *(p_Input_String + i);// записываем первый символ вместо последнего в текущей итерации
		*(p_Input_String + i) = Temp; //записываем сохраненный конечный символ в первый текущей итерации
	}
}

void String_Align (char *first_str, char *second_str) {
	size_t first_string_size = Get_Str_Size (first_str);
	char *p_first_string = (first_str);
	size_t second_string_size = Get_Str_Size (second_str);
	char *p_second_string = (second_str);
	
		if (first_string_size > second_string_size) {
		size_t temp_size = first_string_size - 1;
			while (temp_size--) {
		*(p_second_string + second_string_size + temp_size) = '0';
	}
	}
	else if (first_string_size < second_string_size) {
				size_t temp_size = second_string_size - 1;
			while (temp_size--) {
		*(p_first_string + first_string_size + temp_size) = '0';
	}
	}
}

int main () {
	
	char first_string[100];
	char second_string[100];
	char result_string[100];
	char *p_result_string = result_string;
	
	cout << "Enter first item ";
	cin >> first_string;
	cout << "Enter second item ";
	cin >> second_string;
	
	String_Reversing (first_string);
	String_Reversing (second_string);

	char *p_first_string = (first_string);
	char *p_second_string = (second_string);
	
	uint16_t summ = 0;
	uint16_t carry = 0;
	uint16_t first_string_temp = 0;
	uint16_t second_string_temp = 0;

	String_Align (first_string, second_string);

	while (*(p_first_string)) {
		first_string_temp = Char_To_Dec (*p_first_string);
		second_string_temp = Char_To_Dec (*p_second_string);
		carry = Summ (first_string_temp, second_string_temp, summ, carry);
		*(p_result_string++) = Dec_To_Char(summ);
        p_first_string++;
        p_second_string++;
	}

	if (carry) {
		*(p_result_string) = Dec_To_Char(carry);
		*(++p_result_string) = '\0';
	}
	
	else *(p_result_string) = '\0';
	String_Reversing(result_string);
	cout << "Result " << result_string;

	return 0;
}


