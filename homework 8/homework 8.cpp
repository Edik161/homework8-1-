// homework 8.cpp: определяет точку входа для приложения.
//

#include "homework 8.h"

int main()
{
    setlocale(LC_ALL,"Rus");
    const int SIZE = 8;
    char array[SIZE][SIZE];
    char letters[] = {'F', 'E', 'R'};

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