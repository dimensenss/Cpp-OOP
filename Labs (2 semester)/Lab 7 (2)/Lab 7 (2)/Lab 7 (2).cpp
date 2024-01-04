﻿#include "foo.h"
#define _CRT_SECURE_NO_WARNINGS

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    int mode;
    int variant;

    char fname[] = "file.txt";

    do
    {
        print_menu();
        variant = get_variant();
        switch (variant)
        {
        case 1:
        {
            mode = 1;
            input_in_file(fname, &mode);
        }break;

        case 2:
        {
            mode = 2;
            input_in_file(fname, &mode);
        }break;

        case 3:
        {

            mode = 3;
            input_in_file(fname, &mode);
        }break;

        
        case 4:
        {
            one_material_print(fname);
        }break;
        case 5:
        {
            all_materials_print(fname);
        }break;
        case 6: 
        {
            clear_file(fname);
        }break;
		
        
        
        } 
        if (variant != 7)
            system("pause");
    }while (variant != 7);
}


