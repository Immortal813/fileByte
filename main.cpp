#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>


int main() {

	std::ifstream file( "p.png", std::ios::binary );
	std::fstream inp;
	inp.open( "t.txt" );

	if ( !file.is_open() ) {

		std::cout << "Error open file!\n";

	}

	char cur_byte;
	//char pre_byte;

	int count = 0;

	//bool flag_start = true;
	bool flag_start = false;
	//bool flag_f1 = false;

	std::vector<char> posled;
	std::vector<std::vector<char>> seq_arr;
	int ggg = 0;

	std::string str_file;


	while ( file.get( cur_byte ) ) {
		ggg++;
		str_file.push_back( cur_byte );
		// Если предыдущая последовательность уже была завершена, 
		// начинаем новую, иначе игнорируем "f1"
		if ( cur_byte == '\xF1' ) {

			//posled.push_back( cur_byte );
			// Очищаем текущую последовательность и начинаем новую
			if ( flag_start == true ) {

				posled.clear();
				// Устанавливаем флаг, что новая последовательность начата

			}

			posled.clear();
			posled.push_back( cur_byte );
			flag_start = true;


		}
		// Если последовательность не пустая
		else if ( flag_start == true ) {
			// Добавляем новый элемент
			posled.push_back( cur_byte );
			// Проверяем, заканчивается ли текущая последовательность на "01"
			if ( cur_byte == '\x01' ) {
				// Подсчет количества полседовательностей
				count++;
				// Запихиваем в вектор последовательностей
				//posled.push_back( cur_byte );
				seq_arr.push_back( posled );
				// Очищаем буфер
				posled.clear();
				// Последовательность завершена
				flag_start = false;

			}

		}

	}


	/*
	while ( file.get(cur_byte) ) {
		ggg++;
		// Если предыдущая последовательность уже была завершена,
		// начинаем новую, иначе игнорируем "f1"
		if ( cur_byte == '\xF1' ) {
			// Очищаем текущую последовательность и начинаем новую
			if ( flag_start == true ) {

				posled.clear();
				posled.push_back( cur_byte );
				// Устанавливаем флаг, что новая последовательность начата
				flag_start = false;

			}

		}
		// Если последовательность не пустая
		else if ( !posled.empty() ) {
			// Добавляем новый элемент
			posled.push_back( cur_byte );
			// Проверяем, заканчивается ли текущая последовательность на "01"
			if ( cur_byte == '\x01' ) {
				// Подсчет количества полседовательностей
				count++;
				// Запихиваем в вектор последовательностей
				seq_arr.push_back( posled );
				// Очищаем буфер
				posled.clear();
				// Последовательность завершена
				flag_start = true;

			}

		}

	}
	*/

	std::cout << "ALL: " << ggg << std::endl;
	std::cout << "Colvo: " << count << std::endl;
	std::cout << "Vector size: " << seq_arr.size() << std::endl;
	//std::cout << std::setfill( '0' );

	
	
	
	int max_lenght = 0;
	int max_size = 0;
	for ( int i = 0; i < seq_arr.size(); i++ ) {
		
		if ( seq_arr[ i ].size() > max_size ) {

			max_size = seq_arr[ i ].size();
			max_lenght = i;

		}
		for ( int j = 0; j < seq_arr[ i ].size(); j++ ) {

			
			//std::cout << std::hex << std::setw( 2 ) << static_cast<int>( static_cast<unsigned char>( seq_arr[i][j] ) ) << " ";
			inp << std::hex << std::setfill( '0' ) << std::setw( 2 ) << static_cast<int>( static_cast<unsigned char>( seq_arr[ i ][ j ] ) ) << " ";

		}

		inp << std::endl;
		

	}

	std::cout << "Max seq lenght: " << max_lenght + 1 << std::endl;
	std::cout << "Max lenght: " << max_size << std::endl;
	std::cout << "Max seq size(byte): " << seq_arr[ max_lenght ].size() << std::endl;

	/*std::cout << "Max lenght seq: ";
	for ( int i = 0; i < seq_arr[ buf ].size(); i++ ) {

		std::cout << std::hex << std::setfill( '0' ) << std::setw( 2 ) << static_cast<int>( static_cast<unsigned char>( seq_arr[ buf ][ i ] ) ) << " ";

	}*/
	//for ( const auto &vec : seq_arr ) {
	//	for ( int num : vec ) {

	//		std::cout << num << " ";

	//	}

	//	std::cout << std::endl;

	//}

	/*for ( int i = 0; i < seq_arr.size(); i++ ) {

		std::cout << "First sequence: " << seq_arr[ 1 ][ 1 ];

	}*/
	return 0;
}
