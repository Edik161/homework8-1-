// homework 8.cpp: определяет точку входа для приложения.
//

#include "homework 8.h"

int main()
{
    //setlocale(LC_ALL,"Rus");
    std::locale::global(std::locale("ru_RU.UTF-8"));
   
    const int SIZE = 8;
    char array[SIZE][SIZE];
    char letters[] = {'F', 'E', 'R', '1', 'Y', '2'};
    //std::string l[] = { "Щ" };


    for (char letter : letters)
    {
        for (int i = 0; i < SIZE; i++) 
        {
            for (int j = 0; j < SIZE; j++)
            {
                array[i][j] = '*';
            }
        }
        for (int i = 0; i < SIZE; i++) 
        {
            for (int j = 0; j < SIZE; j++) 
            {
                switch (letter) 
                {
                    case 'F':
                        if (i == 0 || i == SIZE/2 || j == 0)
                            array[i][j] = 'F';
                        break;
                    case 'E':
                        if (i == 0 || i == SIZE/2 || i == SIZE-1 || j == 0)
                            array[i][j] = 'E';
                        break;
                    case 'R':
                        if (j == 0 || (i == 0 && j < SIZE-1) || 
                            (i == SIZE/2 && j < SIZE-1) ||
                            (j == SIZE-1 && i > 0 && i < SIZE/2) ||
                            (i == j && i > SIZE/2))
                            array[i][j] = 'R';
                        break;
                    case '1':// Буква Щ
                        if ((7 != i && (0 == j || 3 == j || 6 == j)) ||
                            (6 == i) || (7 == i && 7 == j))
                            array[i][j] = '1';
                        break;
                    case 'Y':
                        if ((i == j && j < SIZE / 2 || j == (SIZE - 2 - i) && j > i) ||
                            (j == (SIZE / 2 - 1) && j < i))
                            array[i][j] = 'Y';
                        break;
                    case '2':// Буква Б
                        if ((0 == i || 0 == j || SIZE - 1 == i && SIZE - 1 != j) ||
                            SIZE - 4 == i && SIZE - 1 != j || 
                            SIZE - 1 == j && SIZE - 3 == i ||
                            SIZE - 1 == j && SIZE - 2 == i)
                            array[i][j] = '2';
                        break;
                }
            }
        }
        std::cout << "Буква " << letter << ":\n";
        for (int i = 0; i < SIZE; i++) 
        {
            for (int j = 0; j < SIZE; j++) 
            {
                std::cout << array[i][j] << ' ';
            }
            std::cout << '\n';
        }
        std::cout << "----------------\n";
    }

    return 0;
}