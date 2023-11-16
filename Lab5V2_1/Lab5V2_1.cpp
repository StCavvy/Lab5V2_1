#include <iostream>

using namespace std;

int main()
{
	//змінні для підрахунку загальної кількості слів та змінна-флаг для перевірки умови
	int deviders = 0;
	int words = 0;
	bool check = false;
	int filled_size = 0;

	//змінні для пошуку слів в масиві та підрахунку співвідношення
	float percentage = 0;
	int row = 0;
	int first_letter = -1;
	int last_letter = 0;
	int word_size = 0;
	int encounters = 0;

	//наш массив
	char input [300];

	//приймаємо массив з консолі
	cout << "Enter your array : ";
	cin.getline(input, sizeof(input));
	cout << endl;

	//перевіряємо, скільки усього єлементів мають якесь значення, аби дізнатися яка частина масиву заповнена
	for (int i = 0; i < sizeof(input); i++)
	{
		if (input[i] == NULL)
		{
			filled_size = i;
			break;
		}
	}

	//виводимо в консоль масив
	cout << "In array '";
	for (int i = 0; i < filled_size; i++) cout << input[i];
	cout << "' : " << endl;

	//рахуємо та виводимо загальну кількість слів
	for (int i = 0; i < filled_size; i++)
	{
		if (input[i] == ' ') deviders++;
	}
	words = deviders + 1;
	cout << "Total words count : " << words << endl;

	//головний цикл, який відпрацьовує допоки умова для зупинки не здійснилася
	while (check == false)
	{

		//шукаємо першу літеру в масиві, з неї починається слово
		for (int i = 0; i < filled_size; i++)
		{
			if (input[i] >= 'A' && input[i] <= 'Z' || input[i] >= 'a' && input[i] <= 'z')
			{
				first_letter = i;
				break;
			}
			else if (input[i] == NULL)
			{
				check = true;
				break;
			}
		}

		//шукаємо пробіл, символ перед ним буде останьою літерою слова, тепер ми знаємо де в масиві це слово
		for (int i = first_letter; i < filled_size + 1; i++)
		{
			if (input[i] == ' ' || input[i] == NULL)
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
		for (int i = last_letter + 2; i < filled_size; i++)
		{
			//почитаючи з певного місця, перевіряємо, чи відворюється послідовність символів, яка відповідає нашому слову
			for (int j = 0; j < word_size; j++)
			{
				if (input[i + j] == input[first_letter + j])
				{
					//якщо літери співпали, то додаємо до лічильника один пункт
					row++;
				}
				else
				{
					row = 0;
					break;
				}
			}

			//якщо кіл-ть літер підряд які співпали відповідає розміру слова, 
			// та це э окремим словом, перед та після якого пробіл або пустий єлемент
			// то рахуємо це за повтор слова, після чого його викреслюємо його
			if (row == word_size && input[i - 1] == ' ' && input[i + word_size] == ' ')
			{
				for (int j = 0; j < word_size; j++)
				{
					input[i + j] = '*';
					input[i + word_size] = '*';
				}
				encounters++;
				row = 0;
			}
			else if (row == word_size && input[i - 1] == ' ' && input[i + word_size] == NULL)
			{
				for (int j = 0; j < word_size; j++)
				{
					input[i + j] = '*';
					input[i + word_size] = '*';
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
		input[last_letter + 1] = '*';

		//повертаємо нашим змінним початкові значення для наступного проходу
		percentage = 0;
	    row = 0;
		first_letter = -1;
		last_letter = 0;
		word_size = 0;
		encounters = 0;
	}
} 
