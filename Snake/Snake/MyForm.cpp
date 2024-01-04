#include "MyForm.h"
#include <iostream>

using namespace System;
using namespace System::Windows::Forms;

 FILE* f;

void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Snake::MyForm form;
	Application::Run(% form);
}
struct vector {
	int X, Y;
};

vector direction;//направление змейки
vector positionFruit;//позиция фрукта
vector gameArea;//игровая зона

//конструктор формы
Snake::MyForm::MyForm(void)
{
	InitializeComponent();

	//Размеры игровой зоны
	gameArea.X = 500;
	gameArea.Y = 500;

	firstLaunch = true;//первый запуск
	NewGame();//новая игра

}

//реализаци действий игры
void Snake::MyForm::GeneratePositionFruit()
{
	//генерация случайной позиции фрукта
	Random^ rand = gcnew Random();
	positionFruit.X = rand->Next(100, (gameArea.X-100));
	positionFruit.Y = rand->Next(150, (gameArea.Y-100));

	//преобразуем значение чтобы было кратно шагу
	int tempX = positionFruit.X % step;
	positionFruit.X -= tempX;

	int tempY = positionFruit.Y % step;
	positionFruit.Y -= tempY;

	//проверка что фрукт не создался на змейке
	for (int i = 0; i < score; i++)
	{
		if (positionFruit.X == snake[i]->Location.X && positionFruit.Y == snake[i]->Location.Y)
			GeneratePositionFruit();
	}

	//присваеваем позицию фрукту
	fruit->Location = Point(positionFruit.X, positionFruit.Y);

	//добавляем объект на форму
	this->Controls->Add(fruit);
}

void Snake::MyForm::Eating()
{
	//проверим голову змеи и позицию фрукта
	
	if (snake[0]->Location.X == positionFruit.X && snake[0]->Location.Y == positionFruit.Y) {
		Score->Text = "Очки: " + ++score;
		//добавляем новый элемент змейке
		snake[score] = gcnew PictureBox();
		snake[score]->Location = Point(snake[score - 1]->Location.X + step * direction.X, snake[score - 1]->Location.Y - step * direction.Y);
		Bitmap^ bit = gcnew Bitmap("C:/Users/Homo/source/repos/dimensenss/Lab_Works/Snake/resources/body_snake_down.png");
		snake[score]->Image = bit;
		snake[score]->SizeMode = PictureBoxSizeMode::StretchImage;
		snake[score]->BackColor = Color::Olive;
		snake[score]->Width = step;
		snake[score]->Height = step;
		this->Controls->Add(snake[score]);
		
		GeneratePositionFruit();
	}
}

void Snake::MyForm::Movement()
{
	//двигаем каждый элемент змейки
	for (int i = score; i >= 1; i--)
		snake[i]->Location = snake[i - 1]->Location;
	
	snake[0]->Location = Point(snake[0]->Location.X + direction.X * step, snake[0]->Location.Y + direction.Y * step);
}

void Snake::MyForm::EatYourself()
{
	//проверка позиции каждой части змейки
	for (int i = 1; i < score; i++) {
		if (snake[0]->Location == snake[i]->Location)
			GameOver();
	}
}

void Snake::MyForm::GameOver()
{
 	play = false;
	die = true;

	//открыть файл для записи	
	if (launches==1) 
		fopen_s(&f, "score.txt", "w");
		
	else
		fopen_s(&f, "score.txt", "a");
	fprintf(f, "%d ", score);
	fclose(f);
	
 	Game_over->Visible = true;
}
void Snake::MyForm::SaveRecords() {
	int* arr = new int[launches];
	//записать в массив данные из файла
	fopen_s(&f, "score.txt", "r");
	fseek(f, 0, SEEK_SET);

	for (int i = 0; i < launches; i++) {
		fscanf(f, "%d", &*(arr + i));
	}
	fclose(f);

	if (listBoxText->Visible == false) {

		play = false;
		listBoxText->Visible = true;

		for (int i = 0; i < launches; i++)
		{
			listBoxText->AutoSize;
			listBoxText->Items->Add(i + 1 + ") Игра: " + *(arr + i) + " очков");
		}
	}
	else {
		play = true;
		timer->Start();

		for (int i = launches; i > 0; i--)
			listBoxText->Items->RemoveAt(i - 1);

		listBoxText->Visible = false;
	}
	delete[]arr;
}
System::Void Snake::MyForm::сохранитьДанныеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	SaveRecords();
}

void Snake::MyForm::NewGame()
{
	++launches;
	//если инициализация была, то удаляем объекты с формы
	if (!firstLaunch)
	{
		this->Controls->Remove(fruit);
		if (!firstLaunch) {
			for (int i = 0; i <= score; i++)
				this->Controls->Remove(snake[i]);
		}
	}
	else
		firstLaunch = false;
	
	//можно играть
	play = true;
	die = false;

	score = 0;
	//создаем змейку
	snake = gcnew array <PictureBox^, 1>(400);
	snake[0] = gcnew PictureBox();
	Bitmap^ serpens = gcnew Bitmap("C:/Users/Homo/source/repos/dimensenss/Lab_Works/Snake/resources/head_snake.png");
	snake[0]->Image = serpens;
	snake[0]->SizeMode = PictureBoxSizeMode::StretchImage;
	snake[0]->Location = Point(250, 250);
	snake[0]->BackColor = Color::SlateGray;//цвет головы
	snake[0]->Width = step;
	snake[0]->Height = step;

	this->Controls->Add(snake[0]);

	//создаем фрукт
	fruit = gcnew PictureBox();
	Bitmap^ apple = gcnew Bitmap("C:/Users/Homo/source/repos/dimensenss/Lab_Works/Snake/resources/apple.png");
	fruit->Image = apple;
	fruit->SizeMode = PictureBoxSizeMode::StretchImage;
	fruit->BackColor = Color::Blue;
	fruit->Width = step;
	fruit->Height = step;
	GeneratePositionFruit();

	//задаем таймер для обновления и запускаем таймер для обновления 
	timer->Interval = updateInterval;
	timer->Start();

	//задаем направление на запуске
	direction.X = 0;
	direction.Y = 0;

	Score->Text = "Очки: 0";

	//скрываем ненужные компоненты на форме
	Game_over->Visible = false;
}

void Snake::MyForm::CheckBorders()
{
	if (snake[0]->Location.X >= Rightbound->Location.X || snake[0]->Location.X <= Leftbound->Location.X) 
		GameOver();

	if (snake[0]->Location.Y <= Topbound->Location.Y || snake[0]->Location.Y >= Bottombound->Location.Y)
		GameOver();
}

//реализация событий
System::Void Snake::MyForm::новаяИграToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	NewGame();
}

System::Void Snake::MyForm::паузаПродолжитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (play) {
		play = false;
	}
	else
	{
		play = true;
		timer->Start();
	}
	return System::Void();
}

System::Void Snake::MyForm::правилаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (play) {
		play = false;
	}
	MessageBox::Show("Правила игры:\n1. Для управления используйте стрелки\n2. Ешьте фрукты чтобы расти\n3. Нельзя есть себя и врезаться в стены.", "Правила игры!");
	play = true;
	timer->Start();
}

System::Void Snake::MyForm::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

System::Void Snake::MyForm::MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	//считываем нажатую клавишу
	if (e->KeyCode.ToString() == "Right")//39
	{
		if (direction.X != -1)
		{
			direction.X = 1;
			direction.Y = 0;
			Bitmap^ right = gcnew Bitmap("C:/Users/Homo/source/repos/dimensenss/Lab_Works/Snake/resources/head_snake_right.png");
			snake[0]->Image = right;
			snake[0]->SizeMode = PictureBoxSizeMode::StretchImage;
		}
	}
	else if (e->KeyCode.ToString() == "Left")//37
	{
		if (direction.X != 1)
		{
			direction.X = -1;
			direction.Y = 0;
			Bitmap^ left = gcnew Bitmap("C:/Users/Homo/source/repos/dimensenss/Lab_Works/Snake/resources/head_snake_left.png");
			snake[0]->Image = left;
			snake[0]->SizeMode = PictureBoxSizeMode::StretchImage;
		}
	}
	else if (e->KeyCode.ToString() == "Up")//38
	{
		if (direction.Y != 1)
		{
			direction.Y = -1;
			direction.X = 0;
			Bitmap^ up = gcnew Bitmap("C:/Users/Homo/source/repos/dimensenss/Lab_Works/Snake/resources/head_snake.png");
			snake[0]->Image = up;
			snake[0]->SizeMode = PictureBoxSizeMode::StretchImage;
		}
	}
	else if (e->KeyCode.ToString() == "Down")//40
	{
		if (direction.Y != -1)
		{
			direction.Y = 1;
			direction.X = 0;
			Bitmap^ down = gcnew Bitmap("C:/Users/Homo/source/repos/dimensenss/Lab_Works/Snake/resources/head_snake_down.png");
			snake[0]->Image = down;
			snake[0]->SizeMode = PictureBoxSizeMode::StretchImage;
		}
	}
}

//обновление игры
void Snake::MyForm::GameForm_Update(Object^ obgect, EventArgs^ e)
{
	if (!die && play)
	{
		Movement();//задает движение змейки
		Eating();//проверка что съели фрукт
		EatYourself();//проверка что съели себя
		CheckBorders();//проверка на столкновение со стеной 
	}
	else if (!play && !die)
	{
		timer->Stop();
	}
	
}

System::Void Snake::MyForm::скоростьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (groupBoxSettings->Visible == false) {
		
		play = false; //пауза
		//Активация кнопок и поля для ввода
		buttonApplySpeed->Enabled = true;
		numericUpDown->Enabled = true;
		groupBoxSettings->Visible = true;
	}
	else {
		//Продолжить
		play = true;
		timer->Start();
		//Деактивация кнопок и полей для ввода
		buttonApplySpeed->Enabled = false;
		numericUpDown->Enabled = false;
		groupBoxSettings->Visible = false;
	}
}

System::Void Snake::MyForm::buttonApplySpeed_Click(System::Object^ sender, System::EventArgs^ e)
{
	int c =900;
	updateInterval = Convert::ToSingle(numericUpDown->Value);//считывание из numericUpDown
	if (updateInterval >= 7) //множитель свыше 7 скорости
		updateInterval = 150 - (updateInterval * 10);

	else
	updateInterval = c - (updateInterval * 100); // перевод значения из миллисекунд
	timer->Interval = updateInterval;
	//Деактивация кнопок и полей для ввода
	buttonApplySpeed->Enabled = false;
	numericUpDown->Enabled = false;
	groupBoxSettings->Visible = false;
	//Продолжить
	play = true;
	timer->Start();
}
