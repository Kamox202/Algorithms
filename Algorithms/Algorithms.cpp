// Algorithms.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include<fstream>
#include<vector>

using namespace std;

vector<int> bouble_sort(vector<int> numbers)
{
	for (int i = 0; i < numbers.size(); i++)
	{
		for (int j = 0; j < numbers.size() -1; j++)
		{
			if (numbers[j] > numbers[j + 1])
			{
				int temporary = numbers[j];
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = temporary;
			}
		}
	}
	
	return numbers;
}

void manual_data()
{
	cout << "enter the amount of numbers to sort" << endl;
	int amout_of_numbers = 0;
	cin >> amout_of_numbers;
	vector<int> numbers;
	int temporary = 0;
	for (int i = 0; i < amout_of_numbers; i++)
	{
		cout << "enter number " << i + 1 << endl;
		cin >> temporary;
		numbers.push_back(temporary);
	}

	vector<int> result = bouble_sort(numbers);
	cout << "sorted numbers" << endl;
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
}

void data_from_textfile()
{
	cout << "enter the name of the file" << endl;
	string file_name = "";
	cin >> file_name;
	ifstream file_with_numbers(file_name);
	int amout_of_numbers = 0;
	
	vector<int> numbers;
	int temporary = 0;
	while (file_with_numbers >> temporary)
	{
		numbers.push_back(temporary);
		amout_of_numbers++;
		
	}
	vector<int> result = bouble_sort(numbers);
	cout << "sorted numbers" << endl;
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
}

int main()
{
    short choice_mode = 1;
	do
	{
    cout << "Choose a way in which you want to enter numbers to sort 1 - manual 2 - text file" << endl;
	cin >> choice_mode;
	} while (choice_mode < 1 && choice_mode >> 2);

	switch (choice_mode)
	{
	case 1:
		manual_data();
		break;
	case 2:
		data_from_textfile();
		break;

	default:
		break;
	}

	
	}

