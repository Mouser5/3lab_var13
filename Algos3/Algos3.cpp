#include <iostream>
#include <math.h>
using namespace std;

void VisualSolution(char** field, int column, int row, int size) {
        field[column][row] = 'Q'; 
        int TempCol = column+1, TempRow=row+1;
    for (TempCol; TempCol < size; TempCol++) {
        if (field[TempCol][TempRow-1] == '=')
            field[TempCol][TempRow-1]= '-';
    }
    TempCol = column;
    for (TempRow; TempRow < size; TempRow++) {
        if (field[TempCol][TempRow] == '=')
            field[TempCol][TempRow]= '|';
    }
    TempCol = column+1;
    TempRow = row+1;
    int TempRowDown = row-1;
    while ((TempCol<size)&&(TempRow<size))
    {
        if (field[TempCol][TempRow] == '=')
            field[TempCol][TempRow] = '\\';  //Вниз вправо
        TempCol++;
        TempRow++;
    }
    TempCol = column+1;
    while ((TempCol < size) && (TempRowDown >=0)) //Вверх вправо
    {
        if (field[TempCol][TempRowDown] == '=' )
            field[TempCol][TempRowDown] = '/';
        TempCol++;
        TempRowDown--;
    } 
}

void StepBack(char** field, int column, int size) {
    int row = 0;
    for (; row < size;) {
        if (field[column][row] != 'Q')
            row++;
        else break;
    }
    field[column][row] = '*';
    int TempCol = column + 1, TempRow = row;
    for (; TempCol < size; TempCol++) //вправо
        if (field[TempCol][row]=='-')
            field[TempCol][row] = '=';
    TempCol =column + 1;
    TempRow=row+1;
    for ( ; TempRow < size; TempRow++)
    {
        if (field[column][TempRow] == '|')
            field[column][TempRow] = '=';
    }
    TempRow = row-1;
    TempCol = column+1;
    while ((TempCol<size)&&(0(TempRow)>=0))
    {
        if (field[TempCol][TempRow] == '/')
            field[TempCol][TempRow] = '=';  //вверх вправо
        TempCol++;
        TempRow--;
    }
    TempCol = column+1;
    TempRow = row + 1;
    while ((TempCol < size) && (TempRow < size))
    {
        if (field[TempCol][TempRow] == '\\')
            field[TempCol][TempRow] = '='; // вниз вправо
        TempCol++;
        TempRow++;
    } 
}

void Solution(char ** field,int column, int size) {
    int TempRow = 0, TempCol=column;
    for (; TempRow < size;) {
        if ((field[TempCol][TempRow] != 'Q')&&(field[TempCol][TempRow]!='='))
            TempRow++;
        else break;
    }
    if (TempRow == size) {
        StepBack(field, column-1, size);
        TempRow++;
        if (TempRow > size) {
            for (int index = 0; index < size;index++)
                if(field[column][index]=='*')
                    field[column][index]='=';
        }
            
        if (field[0][size-1]!='*') Solution(field, column - 1, size);
        else 
        {
            cout << "There is no solution on " << size << "x" <<size <<" field" << endl;
            return;
        }
    }
    else{
        VisualSolution(field, TempCol, TempRow, size);
        if (column != size - 1)
            Solution(field, TempCol+1, size);
        else return;
    }
}

void Program() {
    int size = 0;
    cin >> size;
    char agree = 0;
    char** field = new char* [size]; // строки
    for (int index = 0; index < size; index++)
    {
        field[index] = new char[size]; //столбцы VisualSolution(field, column, row % size, size);
    }
    for (int row = 0; row < size; row++)
    {
        for (int column = 0; column < size; column++) {
            field[column][row] ='=';
        }
    }
    Solution(field,0,size);
    if (field[size - 1][size - 1] == '*')
        return;
    cout << "Do you want to see solution?\n";
    cin >> agree;
    if (tolower(agree) != 'y')
        return;
    for (int row = 0; row < size; row++)
    {
        for (int column = 0; column < size; column++) {
            if (field[column][row] == 'Q')
                cout << column << ' ' << row << endl;
        }
    }
    cout << "Do you want to see field?\n";
    cin >> agree;
    if (tolower(agree) != 'y')
        return;
    cout << "Solution" << endl;
    for (int row = 0; row < size; row++)
    {
        for (int column = 0; column < size; column++) {
            cout << field[column][row] << ' ';
        }
        cout << endl;
    }
}

int main()
{
    Program();
    return(0);
}
