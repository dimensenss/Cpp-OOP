#include "Header.h"

void Car::random_car() {
	std::string arr_n[7] = { "Audi", "BMW", "Nissan", "Ford", "Jeep", "Dodge", "Mercedes" };
	std::string arr_m[8] = { "M1", "R8", "Jetta", "Yuppi", "Highlander", "Soul", "Sorrento","H7" };
	name = arr_n[rand() % 7];
	model = arr_m[rand() % 8];
}
Car::Car() {
	
	random_car();
}
void Car_H::random_car() {
	volume = round((1.0 + (float)(rand()) / RAND_MAX * 5)*10)/10;
	hp = 100 + rand() % 600;
	year = 1980 + rand() % 43;
}
Car_H::Car_H() : Car() {
	
	random_car();
}
void Car_Doc::random_car() {
	
	count_owner = rand() % 10+1;
	dtp = (double)rand() / RAND_MAX + 1;
}
Car_Doc::Car_Doc() :Car(), Car_H() {
	
	random_car();
}
AutoShow::AutoShow() {
	std::vector<Car*> arr;
}
AutoShow AutoShow::operator ()(std::vector<Car_Doc*>& arr1) {
	arr = arr1;
	return *this;
}
AutoShow::AutoShow(std::vector<Car_Doc*>& arr1) {
	arr = arr1;
}
void AutoShow::sort_year() {
	for (int i = 0; i < arr.size(); i++) {
		arr[i]->get_year();
	}
	for (int i = 1; i < arr.size(); ++i)
	{
		for (int r = 0; r < arr.size() - i; r++)
		{
			if (arr[r]->get_year() < arr[r+1]->get_year())
			{
				std::swap(arr[r], arr[r + 1]);
			}
		}
	}
}

void Car::print(System::Windows::Forms::TextBox^ textBox)
{
	textBox->Text += " CAR: \n"+gcnew System::String(name.c_str()) + ", "+ gcnew System::String(model.c_str()) + ", ";
};
void Car_H::print(System::Windows::Forms::TextBox^ textBox)
{

	Car::print(textBox); textBox->Text += "Volume: "+volume + ", " + "HP: " + hp + ", " +"Year: "+ year + ", ";
}
void Car_Doc::print(System::Windows::Forms::TextBox^ textBox)
{
	Car_H::print(textBox); textBox->Text += "Documents: "+"Owners: "+count_owner + ", " + "Was in dtp: "+dtp + " ";
	textBox->Text += "\n";
}
void AutoShow::print(System::Windows::Forms::TextBox^ textBox) {
	for (int i = 0; i < arr.size(); i++) {
		textBox->Text += i +1+ ") ";
		arr[i]->print(textBox);
		textBox->Text += "\r\n";
	}
}
void AutoShow::delete_ob(System::Decimal ob)
{
	arr.erase(arr.begin() + ((int)ob-1));

}

void AutoShow::search(System::String^ str, System::Windows::Forms::TextBox^ textBox)
{
	bool f = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i]->get_name() == msclr::interop::marshal_as<std::string>(str))
		{
			f = 1;
			textBox->Text += i + 1 + ") ";
			arr[i]->print(textBox);
			textBox->Text += "\r\n";
		}
		
	}
	if (!f) 
		textBox->Text = "Car doesnt in base";
}
