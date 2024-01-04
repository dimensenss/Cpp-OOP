#include "foo.h"
#define _CRT_SECURE_NO_WARNINGS
void hand_input(FILE* f)
{
    int i;
    table arr;
    fseek(f, 0, SEEK_END);
    for (i = 0; i < 20; i++)
    {
        cin >> arr.name;
        if (strcmp(arr.name, "***") == 0) break;
        cin >> arr.sc >> arr.cnt >> arr.sq;
        fprintf(f, "\n%-11s   %10c   %13s   %10.1f", arr.name, arr.sc, arr.cnt, arr.sq);
    }
}

void random_input(FILE* f)
{
    table arr;
    fseek(f, 0, SEEK_END);

    int N;
    cout<<"Enter N: ";
    cin >> N;
    char symbol[3] = { 'T','М','Д' };
    string names[5] = {"Олово", "Сталь", "Чугун","Золото","Бронза" };
    string sign[10] = { "0-15","0-10","0-20","1-30","5-50","0-70","1-40","0-25","7-10","1-65" };
	
    for (int i = 0; i < N; i++)
    {
        strcpy_s(arr.name, names[rand() % 5].c_str());
        arr.sc = symbol[rand() % 3];
        strcpy_s(arr.cnt, sign[rand() % 10].c_str());
        arr.sq = (double)(rand()) / RAND_MAX * 100;
        fprintf(f, "\n%-11s   %10c   %13s   %10.1f", arr.name, arr.sc, arr.cnt, arr.sq);
    }
    
}

void random_end_input(FILE* f, char* fname)
{
    table arr;
    table arr_temp;
	
    FILE* temp;
    fopen_s(&temp, "temp.txt", "w+");
    
    
    int N;
    cout << "\nEnter N: ";
    cin >> N;
    char symbol[3] = { 'T','М','Д' };
    string names[5] = { "Олово","Сталь","Чугун","Золото","Бронза" };
    string sign[10] = { "0-100","0-10","0-20","15-30","35-50","40-70","10-40","0-25","75-100","15-65" };
	
    for (int i = 0; i < N; i++)
    {
        strcpy_s(arr.name, names[rand() % 5].c_str());
        arr.sc = symbol[rand() % 3];
        strcpy_s(arr.cnt, sign[rand() % 10].c_str());
        arr.sq = (double)(rand()) / RAND_MAX * 100;
        fprintf(temp, "\n%-11s   %10c   %13s   %10.1f", arr.name, arr.sc, arr.cnt, arr.sq);
    }
    
    fseek(f, 0, SEEK_SET);
    while (!feof(f)) {
        if (f != NULL) {
            fscanf(f, "%s  %c  %s  %f", &arr_temp.name, &arr_temp.sc, &arr_temp.cnt, &arr_temp.sq);
            fprintf(temp, "\n%-11s   %10c   %13s   %10.1f", arr_temp.name, arr_temp.sc, arr_temp.cnt, arr_temp.sq);
        }
        
    }
    fclose(f);
    fclose(temp);
    remove(fname);
    rename("temp.txt", fname);
}
void input_in_file(char* fname, int* mode)
{
    FILE* f;
    fopen_s(&f, fname, "r+t");


    if (*mode == 1)
        hand_input(f);
    if (*mode == 2)
        random_input(f);
    if (*mode == 3)
    random_end_input(f, fname);
		
		
    if (!f == NULL)fclose(f);
}

void one_material_print(char* fname)
{
    table arr;
    FILE* f;

	fopen_s(&f, fname, "r+t");
	

    int N = 0;
    cout << "What line to display?";
	cout << "\nEnter N: ";
    cin >> N;
    if (N < 1) {
        system("cls"); cout << "Enter number, bigger then 0\n"; fclose(f); return;
    }
    cout << "---------------------------------------------------\n";
    cout << "|   Коэффициенты теплопроводимости материаллов    |\n";
    cout << "|-------------------------------------------------|\n";
    cout << "| Вещество    | Тип | Влажность (%)  | Коэффициент|\n";
    cout << "|             |     |                |            |\n";
    cout << "|-------------|-----|----------------|------------|\n";
    

    for (; N-1 >= 0; ) {
        
        fscanf(f, "%s  %c  %s  %f", &arr.name, &arr.sc, &arr.cnt, &arr.sq);
        N--;
    }
    printf("| %-11s | %-3c | %-14s | %-10.3f |\n", arr.name, arr.sc, arr.cnt, arr.sq);
   
    
    cout << "---------------------------------------------------\n";
    cout << "|                                                 |\n";
    cout << "|  Примечание: М - металлы,                       |\n";
    cout << "|              Т - термоизоляционные материалы,   |\n";
    cout << "|              Д - другие материалы               |\n";
    cout << "---------------------------------------------------\n";

    if(f!=NULL)fclose(f);
}
void all_materials_print(char* fname)
{
    table arr;
    FILE* f;

    fopen_s(&f, fname, "r+t");
    
    cout << "---------------------------------------------------\n";
    cout << "|   Коэффициенты теплопроводимости материаллов    |\n";
    cout << "|-------------------------------------------------|\n";
    cout << "| Вещество    | Тип | Влажность (%)  | Коэффициент|\n";
    cout << "|             |     |                |            |\n";
    cout << "|-------------|-----|----------------|------------|\n";


    while (!feof(f)) {
        fscanf(f, "%s  %c  %s  %f", &arr.name, &arr.sc, &arr.cnt, &arr.sq);
        printf("| %-11s | %-3c | %-14s | %-10.3f |\n", arr.name, arr.sc, arr.cnt, arr.sq);
    }
        


    cout << "---------------------------------------------------\n";
    cout << "|                                                 |\n";
    cout << "|  Примечание: М - металлы,                       |\n";
    cout << "|              Т - термоизоляционные материалы,   |\n";
    cout << "|              Д - другие материалы               |\n";
    cout << "---------------------------------------------------\n";

    if (f != NULL)fclose(f);
}
void clear_file(char* fname) {
	FILE* f;
	fopen_s(&f, fname, "w");
	if (f != NULL)fclose(f);
}

void print_menu()
{
    system("cls");
    printf("What do we do?\n");
    printf("1. Fill structure by hand and print in file\n");
    printf("2. Fill structure randomly and print in file\n");
    printf("3. Fill the structure to the beginning of the file\n");
    printf("4. Print in console one material\n");
    printf("5. Print in console all ot the materials\n");
    printf("6. Clear file\n");
    printf("7. Exit\n");
    printf(">");
}

int get_variant() {
    int variant;
    cin >> variant;
    if (variant < 1 || variant > 7)
    {
        cout << "Ошибка, введите числа в диапозоне 1-7" << endl;
        return 0;
    }
    else
        return variant;
}
