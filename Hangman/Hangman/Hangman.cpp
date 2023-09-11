//ввод испоьзуемых слов, других констант и переменных
//перемашивание слов, макс. кол-во ошибок
//введение уже отгаданных букв, часть слова, открытая на данный момент
//основной цикл: пока игрок не отгадает слово или не достигнет макс. кол-ва ошибок
//получение буквы от пользователя
//рассмотрение варианта, когда пользователь вводит уже отгаданную букву
//рассмотрение варианта, когда пользователь вводит верную букву
//обновление списка букв
//рассмотрение варианта, когда пользователь вводит неверную букву
//конец игры: превышение кол-ва ошибок или верно угаданное слово
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <ctime>
using namespace std;
int main()
{
	const int MAX_WRONGS = 8;
	vector <string> words;
	words.push_back("GUESS");
	words.push_back("HANGMAN");
	words.push_back("DIFFICULT");
	words.push_back("APPLE");
	words.push_back("SUCCESS");
	words.push_back("KITTEN");
	srand(static_cast <unsigned int> (time(0)));
	random_shuffle(words.begin(), words.end());
	const string THE_WORD = words[0];
	vector <char> used;
	vector <char> incorrect;
	string incorrectUsed;
	int wrongs = 0;
	string soFar(THE_WORD.size(), '-');
	vector <char>::const_iterator iter;
	cout << "\t\t\t\t Welcome to HANGMAN! Good luck!\n";
	while (soFar != THE_WORD && wrongs != MAX_WRONGS)
	{
		cout << " The word is " << soFar << endl;
		cout << " You have " << wrongs << " wrongs\n";
		cout << " You have " << MAX_WRONGS - wrongs << " attemps left\n";
		cout << " You have already guessed " << used.size() << " letters: ";
		for (iter = used.begin(); iter != used.end(); ++iter)
		{
			cout << *iter << ", ";
		}
		cout << " And you have " << incorrect.size() << " incorred letters: ";
		for (iter = incorrect.begin(); iter != incorrect.end(); ++iter)
		{
			cout << *iter << ", ";
		}
		char guess;
		cout << "\n Enter your guess: ";
		cin >> guess;
		guess = toupper(guess);
		while (soFar.find(guess) != string::npos or incorrectUsed.find(guess) != string::npos)
		{
			cout << " You have been already guessed this letter\n";
			cout << " Enter your guess: ";
			cin >> guess;
			guess = toupper(guess);
		}
		if (THE_WORD.find(guess) != string::npos)
		{
			cout << " You guessed it!\n";
			used.push_back(guess);
			for (int i = 0; i < THE_WORD.size(); ++i)
			{
				if (THE_WORD[i] == guess)
				{
					soFar[i] = guess;
				}
			}
		}
		else
		{
			cout << " No! You didnt guess!\n";
			incorrect.push_back(guess);
			wrongs++;
			incorrectUsed += guess;
		}
	}
	if (wrongs == MAX_WRONGS)
	{
		cout << "\n\n\t\t\t\t\t You have been hunged! The word was " << THE_WORD << endl;
	}
	else
	{
		cout << "\n\n\t\t\t\t\t WIN!!!\n";
	}
	return 0;
}