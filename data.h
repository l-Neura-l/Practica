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
		bool isPozitive;

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
			int temp = 0;
			for (short i = 1; i < 13; i++) {
				do {
					temp = rand() % 21 - 10;
				} while (temp == 0);
				vec.push_back(temp);
			}
			vec.push_back(userNum);
			for (short i = 1; i < 12; i++) {
				do {
					temp = rand() % 21 - 10;
				} while (temp == 0);
				vec.push_back(temp);
			}
			vec.push_back(userNum);
			int pos = 0;
			for (short i = 0; i < count; i++) {
				if (vec[i] > 0) {
					pos += 1;
				}
			}
			isPozitive = (pos > 12) ? false : true;
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
			userNum = 1;
			activeSort = true;
		}
		System::String^ calc() {

			System::String^ calcText = "Исходный массив:\r\n";

			generateVector();

			calcText += getVector();

			if (activeSort == true) {
				calcText += "\r\nОтсортированый массив:\r\n";
				short temp = 0;
				if (isPozitive) {
					for (short i = 0; i < count; i++) {
						if (vec[i] < 0) {
							for (short j = 0; j < count; j++) {
								if (vec[j] > 0) {
									int temp = vec[i];
									vec[i] = vec[j];
									vec[j] = temp;
								}
							}
						}
					}
					for (short i = 0; i < count; i++) {
						if (vec[i] > 0) {
							temp = i;
							break;
						}
					}
				}
				else {
					for (short i = 0; i < count; i++) {
						if (vec[i] > 0) {
							for (short j = 0; j < count; j++) {
								if (vec[j] < 0) {
									int temp = vec[i];
									vec[i] = vec[j];
									vec[j] = temp;
								}
							}
						}
					}
					for (short i = 0; i < count; i++) {
						if (vec[i] < 0) {
							temp = i;
							break;
						}
					}
				}

				std::sort(vec.begin(), vec.begin() + temp);
				calcText += getVector();
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