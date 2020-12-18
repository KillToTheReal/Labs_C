#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <ctime>
using namespace std;

bool Is_Increasing(const vector<int> &a, int first, int last)
{
    for (first; first < last - 1; first++)
    {
        if (a[first] >= a[first + 1])
        {
            return 0;
        }
    }
    return 1;
}

int FindFirstZeroPos(const vector<int> &a)
{
    int first_zero_place = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == 0)
        {
            first_zero_place = i;
            return first_zero_place;
        }
    }
    return -1;
}

int FindLastMaxPos(const vector<int> &a)
{
    int max = -100;
    int max_pos = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] >= max)
        {
            max = a[i];
            max_pos = i;
        }
    }
    return max_pos;
}

void UdalenieElementaSYacheikoy(vector<int> &a, int n) //Удаление элемента вместе с ячейкой
{
    for (n; n < a.size() - 1; n++)
    {
        a[n] = a[n + 1];
    }
    int f = a.size() - 1;
    a[f] = 0;
    a.pop_back();
}

void UdalenieElementa(vector<int> &a, int n) //Удаление элемента с передвижением оставшихся элементов влево, а последний == 0
{
    {
        for (n; n < a.size() - 1; n++)
        {
            a[n] = a[n + 1];
        }
        int f = a.size() - 1;
        a[f] = 0;
    }
}

int MinPolozhElem(const vector<int> &a)
{
    int min = 200;
    for (int k = 0; k < a.size(); k++) //Поиск миним
    {
        if (a[k] >= 0)
        {
            if (a[k] < min)
            {
                min = a[k];
            }
        }
    }
    return min;
}

void DobavlMinElem(vector<int> &a) //(1)К каждому отрицательному элементу добавить минимальный положительный элемент
{
    int min = MinPolozhElem(a);
    cout << endl
         << "Minimalny' element: " << min << endl;

    for (int i1 = 0; i1 < a.size(); i1++)
        a[i1] += min;

    for (auto j : a)
    {
        cout << j << " ";
    }
}

void VivodVectora(const vector<int> &a)
{
    cout << endl
         << "Vash massiv: ";
    for (auto j : a)
    {
        cout << j << " ";
    }
    cout << endl;
}

void UdalenieKratnyh(vector<int> &a, int t)
{
    int zero_count = 0;
    int divided_count = 0;
    for (int f : a)
    {
        if (f == 0)
        {
            zero_count++;
        }
    }

    for (int g : a)
    {
        if (g % t == 0)
            divided_count++;
    }

    int diff = divided_count - zero_count;

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            if (a[j] % t == 0 && a[j] != 0)
            {
                UdalenieElementaSYacheikoy(a, j);
            }
        }
    }

    int i1 = a.size();
    int i2 = a.size() + zero_count;
    while (i1 < i2)
    {
        int h = 0;
        a.push_back(h);
        i1++;
    }
}

void VvodMassiva(vector<int> &a, int t)
{
    int n = 0;

    cout << endl
         << "Vvedite elementy massiva: ";
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        a[i] = n;
    }
}

int SpecialSum(const vector<int> &a)
{
    int first_zero_place = FindFirstZeroPos(a);
    int sum_eltov = 0;
    int last_max_pos = FindLastMaxPos(a);

    if (Is_Increasing(a, first_zero_place, a.size()))
    {
        for (int i = 0; i < last_max_pos; i++)
        {
            sum_eltov += a[i];
        }
    }
    return sum_eltov;
}

void DeleteForSign(vector<int> &a)
{
    int min = 200;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] < min)
            min = a[i];
    }

    if (min < 0)
    {
        for (int j = 0; j < a.size(); j++)
        {
            for (int h = 0; h < a.size(); h++)
            {
                if (a[h] < 0)
                    UdalenieElementaSYacheikoy(a, h);
            }
        }
    }
    else if (min >= 0)
    {
        for (int j1 = 0; j1 < a.size(); j1++)
        {
            for (int h1 = 0; h1 < a.size(); h1++)
            {
                if (a[h1] > 0)
                    UdalenieElementaSYacheikoy(a, h1);
            }
        }
    }
}

void SortForIndex(vector<int> &a, int first, int last)
{
    sort(a.begin() + first, a.begin() + last);
    reverse(a.begin() + first, a.begin() + last);
}

/*Вариант 6 Дан массив из N вещественных чисел.
  К каждому отрицательному элементу добавить минимальный
положительный элемент(+).
 Сжать массив, удалив из него все элементы, кратные числу t.(+)
Освободившиеся в конце массива элементы заполнить количеством нулей в исходном массиве.(+)
Если элементы, расположенные за первым нулевым элементом, упорядочены в порядке
возрастания, то найти сумму элементов массива, расположенных до последнего максимального
элемента.(Я думал что убью себя но +++)
Удалить из массива элементы, чей знак не совпадает со знаком минимального элемента. (+)
Отсортировать по убыванию часть массива между элементами с заданными индексами i1 и i2. (+)
*/

int main()
{
    srand(time(NULL));
    int n;
    cout << "Vvedite chislo: ";
    cin >> n;
    vector<int> why(n);
    // for (int i = 0; i < why.size(); i++)
    //     why[i] = (rand() % 100 - 50);

    VvodMassiva(why, n);
    //UdalenieKratnyh(why, 2);
    VivodVectora(why);

    //cout << SpecialSum(why);

    SortForIndex(why, 0, 4);
    VivodVectora(why);
}
