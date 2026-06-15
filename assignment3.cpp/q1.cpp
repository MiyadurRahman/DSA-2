#include<iostream>
using namespace std;

int my_id = 112430460;

const int m = 11;
const int a = my_id % 9;
const int b = my_id % 11;
const int c1 = 3;
const int c2 = 5;
const int q = 7;

struct student{
    int id = -1;
    string name;
    float CGPA;
};

student hashtable[1000];
int tracker[1000];
int collision = 0;

int _hash1(int key, int i)
{
    return (a * key + b + i) % m;
}

void _insert_linear(student s)
{
    int i = 0;
    while(1)
    {
        int index = _hash1(s.id, i);

        if(tracker[index] != 1)
        {
            hashtable[index] = s;
            tracker[index] = 1;
            break;
        }

        i++;
        collision++;
    }
}

int _hash2(int key, int i)
{
    return (a * key + b + c1 * i + c2 * i * i) % m;
}

void _insert_quadratic(student s)
{
    int i = 0;
    while(1)
    {
        int index = _hash2(s.id, i);

        if(tracker[index] != 1)
        {
            hashtable[index] = s;
            tracker[index] = 1;
            break;
        }

        i++;
        collision++;
    }
}

int h1(int key)
{
    return key % m;
}

int h2(int key)
{
    return q - (key % q);
}

int _hash3(int key, int i)
{
    return (h1(key) + i * h2(key)) % m;
}

void _insert_double(student s)
{
    int i = 0;
    while(1)
    {
        int index = _hash3(s.id, i);

        if(tracker[index] != 1)
        {
            hashtable[index] = s;
            tracker[index] = 1;
            break;
        }

        i++;
        collision++;
    }
}

void reset_table()
{
    for(int i = 0; i < m; i++)
    {
        tracker[i] = 0;
        hashtable[i].id = -1;
    }
    collision = 0;
}

int main()
{
    student s[7];

    for(int i = 0; i < 7; i++)
    {
        cin >> s[i].name >> s[i].id >> s[i].CGPA;
    }

    reset_table();
    for(int i = 0; i < 7; i++)
    {
        _insert_linear(s[i]);
    }
    cout << collision << endl;

    reset_table();
    for(int i = 0; i < 7; i++)
    {
        _insert_quadratic(s[i]);
    }
    cout << collision << endl;

    reset_table();
    for(int i = 0; i < 7; i++)
    {
        _insert_double(s[i]);
    }
    cout << collision << endl;

    return 0;
}