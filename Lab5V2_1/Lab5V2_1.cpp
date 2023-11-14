#include <iostream>

using namespace std;

int main()
{
	//наш масив символів
	char input[20]{'g', 'a', 'y', ' ', 'g', 'a', 'y', ' ', 's', 'e', 'x', ' ', 'p', 'o', 'r', 'n', ' ', 'n' ,'o','.'};

	//змінні для підрахунку загальної кількості слів та змінна-флаг для перевірки умови
	int deviders = 0;
	int words = 0;
	bool check = false;

	//змінні для пошуку слів в масиві та підрахунку співвідношення
	float percentage = 0;
	int row = 0;
	int first_letter = -1;
	int last_letter = 0;
	int word_size = 0;
	int encounters = 0;

	/*for (int i = 0; i < 20; i++)
	{
		cout << "Enter " << i+1 << " symbol of 20 : ";
		cin >> input[i];
		cout << endl;
	}
	system("clear");
	*/

	//виводимо в консоль масив
	cout << "In array '";
	for (int i = 0; i < 20; i++) cout << input[i];
	cout << "' : " << endl;

	//рахуємо та виводимо загальну кількість слів
	for (int i = 0; i < 20; i++)
	{
		if (input[i] == ' ') deviders++;
	}
	words = deviders + 1;
	cout << "Total words count : " << words << endl;

	//головний цикл, який відпрацьовує допоки умова для зупинки не здійснилася
	while (check == false)
	{
		//шукаємо першу літеру в масиві, з неї починається слово
		for (int i = 0; i < 20; i++)
		{
			if (input[i] >= 'A' && input[i] <= 'Z' || input[i] >= 'a' && input[i] <= 'z')
			{
				first_letter = i;
				break;
			}
		}

		//шукаємо пробіл, символ перед ним буде останьою літерою слова, тепер ми знаємо де в масиві це слово
		for (int i = first_letter; i < 20; i++)
		{
			if (input[i] == ' ' || input[i] == '.')
			{
				last_letter = i - 1;
				break;
			}
		}
		
		//перевіряємо, чи знайшлася в масиві хоча б одна літера, якщо ні, то виходимо з циклу і підіймаємо флаг
		if (first_letter == -1)
		{
			check = true;
			break;
		}

		//рахуємо розмір слова
		word_size = (last_letter - first_letter) + 1;

		//шукаємо повтори слова у цьому циклі
		for (int i = last_letter + 2; i < 20; i++)
		{
			//почитаючи з певного місця, перевіряємо, чи відворюється послідовність символів, яка відповідає нашому слову
			for (int j = 0; j < word_size; j++)
			{
				if (input[i + j] == input[first_letter + j])
				{
					//якщо літери співпали, то додаємо до лічильника один пункт
					row++;
				}
				else break;
			}

			//якщо кіл-ть літер підряд які співпали відповідає розміру слова, то рахуємо це за повтор слова, після чого його викреслюємо
			if (row == word_size)
			{
				for (int j = 0; j < word_size; j++)
				{
					input[i + j] = '*';
					if (i + word_size <= 20) input[i + word_size] = '*';
				}
				encounters++;
				row = 0;
			}
		}
		//рахуємо співвідношення
		percentage = (100.0f / words) * (encounters + 1.0f);

		//виводимо інформацію по слову
		cout << "Word '";
		for (int i = first_letter; i <= last_letter; i++) cout << input[i] ;
		cout << "' was encountered " << encounters + 1 << " times, that is " << percentage << "%" << endl;

		//викреслюємо саме слово, аби при наступному проході не натикатися на нього, також викреслюємо пробіл
		for (int i = first_letter; i <= last_letter; i++) input[i] = '*';
		if (last_letter + 1 <= 20) input[last_letter + 1] = '*';

		//повертаємо нашим змінним початкові значення для наступного проходу
		percentage = 0;
	    row = 0;
		first_letter = -1;
		last_letter = 0;
		word_size = 0;
		encounters = 0;
	}
} 
