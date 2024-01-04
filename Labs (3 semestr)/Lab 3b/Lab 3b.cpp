#include "Header.h"

int main()
{
    Library lib;
    Library* arr = new Library[3];

    arr[0]("Twen", "Tom Soier", 320, 19, 2, 2);
    arr[1]("Bulgakov", "Master i Margarita", 450, 19, 0, 0);
    arr[2]("Verber", "The secret of the Gods", 280, 1, 1, 1);

    for (int i = 0; i < 3; i++)
        cout << arr[i];
    
    lib.search_book("Tom Soier", arr);//поиск
    lib.push_book("Tom Soier", arr);//попытка вернуть лишнюю копию
    lib.pop_book("Tom Soier", arr);//удачная попытка взять книгу 1/2

    lib.pop_book("Tom Soier", arr);//удачная попытка взять книгу 2/2

    lib.pop_book("Tom Soier", arr);//неудачная попытка взять книгу
    lib.push_book("Tom Soier", arr);//удачная попытка вернуть книгу 1/2
    lib.push_book("Tom Soier", arr);//удачная попытка вернуть книгу 1/2
    lib.push_book("Tom Soier", arr);//попытка вернуть лишнюю копию

   

}