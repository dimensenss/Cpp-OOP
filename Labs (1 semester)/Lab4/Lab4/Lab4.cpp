#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main() {

	setlocale(LC_ALL, "ru");

	short c;
	short f;
	short d;

	unsigned int rez;
	while (1) {
		printf("Введите номер канала таймера (0-3) >");
		scanf("%hd", &c);

		printf("Введите форму сигнала (0-3) >");
		scanf("%hd", &f);

		printf("Введите коэффициент деления опорной частоты (0-4095) >");
		scanf("%hd", &d);

		rez = ((unsigned int)c & 0x3) << 14;
		rez |= ((unsigned int)f & 0x3) << 12;
		rez |= ((unsigned int)d & 0xFFF);
		
		printf("\nУправляющее слово программыруемого таймера = %04x\n", rez);

		/////////////////////////////////////////////////////////////////////

		printf("\n\nВведите управляющее слово программируемого таймера\n");
		printf("\n(16-ричное число от 0 до 0xFFFF) >");
		scanf("%x", &rez);

		c = (rez >> 14) & 0x3;
		f = (rez >> 12) & 0x3;
		d = rez & 0xFFF;

		printf("\n\nНомер канала таймера = %18hd\n", c);
		printf("Форма сигнала = %25hd\n", f);
		printf("Коэффициент деления опорной частоты = %4hd\n", d);

		printf("\n\n\n\n\n");
	}


	return 0;
}