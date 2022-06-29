#pragma once
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>


namespace EvgeniDudnick {
	public class Data { 

	private:
		const int count = 25;
		short maxElement;
		bool pozitive;
		void znach() {
			int b = 0, c = 0;
			for (int i = 0; i < 25; i++) {
				if (vec[i] > 0){
					b++;
				}
			}
			if (b > 12) {
				pozitive = true;
			}
		}

	protected:
		std::vector<int> vec;
		int userNum, proizvedeniye;
		unsigned seed;

	public:
		bool activeSort;

	private:
		void generateVector() {

			std::srand(seed);

			vec.clear();
			for (short i = 1; i < 13; i++) {
				vec.push_back(rand() % 21 - 10);
			}
			vec.push_back(userNum);
			for (short i = 1; i < 12; i++) {
				vec.push_back(rand() % 21 - 10);
			}
			vec.push_back(userNum);
		}
		System::String^ getVector() {
			System::String^ vector;

			for (short i = 0; i < count; i++) {
				vector += vec[i].ToString();
				if (i + 1 < count) {
					vector += ", ";
				}
			}

			return vector;
		}
		

	public:
		~Data() {
			vec.clear();
			vec.shrink_to_fit();
		}
		Data() {
			srand(time(NULL));
			seed = 100000000 + rand() % (999999999 - 100000000 + 1);
			userNum = 0;
			activeSort = true;
		}
		System::String^ calc() {

			System::String^ calcText = "Исходный массив:\r\n";

			generateVector();

			calcText += getVector();

			if (activeSort == true) {

			}

			return calcText;

		}
		System::String^ getUserNum() {
			return userNum.ToString();
		}
		System::String^ getSeed() {
			return seed.ToString();
		}
		void setUserNum(System::String^ value) {
			userNum = int::Parse(value);
		}
		void setSeed(System::String^ value) {
			seed = unsigned::Parse(value);
		}
	};
}