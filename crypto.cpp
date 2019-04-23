#include <iostream>


using namespace std;

size_t Get_Str_Size (char *str) {
	size_t char_counter = 0;
	while (*str++) {
		char_counter++;
	}
	return char_counter;
}

int main () {
	char string_array[100];

	cin >> string_array;
	const size_t char_counter = Get_Str_Size(string_array);

	cout<<"size "<<char_counter<<endl;
	
	char table[char_counter];
	size_t column_quantity = 0;
	
	(char_counter % 2) ? column_quantity = char_counter / 3 : column_quantity = char_counter / 2; 
	cout<<"columns  "<<column_quantity<<endl;
	
	char *p_string_array = begin(string_array);
	char *table_start = table;
	char *table_end = table + char_counter;
	auto i = 0;
	while (*p_string_array) {
		table_start = (table + i);
		while (table_start < table_end) {
			*(table_start) = *(p_string_array++);
			table_start += column_quantity;
		}
		i++;
	}
	*table_end = '\0';



cout<<endl<<table<<endl;

char enc_table[char_counter];
char *p_enc_table = enc_table;
*(p_enc_table + char_counter) = '\0';	

	table_start = table;
	table_end = table + char_counter;
	

i = 0;
while ( i != column_quantity) {
	cout<<i<<endl;
		table_start = (table + i);
		while (table_start < table_end) {
			*(p_enc_table++) = *(table_start);
			table_start += column_quantity;
		}
		i++;
}

	

cout<<endl<<enc_table<<endl;		
	return 0;
}
