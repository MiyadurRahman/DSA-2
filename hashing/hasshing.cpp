#include<iostream>
using namespace std;


struct student{
    int id=-1;
    string name;
    float CGPA;
};
struct student hashtable[1000]; /// 1000 is the capacity
int capacity=1000;
int tracker[1000];
// 0 means that index is empty
// 1 means that index is full
// -1 means that index was deleted

int collision=0;
/// linear probing
int _hash(int key, int i)
{
    int index= (2*key+1+i)%capacity;
    return index;
}

/// insert student s
void _insert(struct student s)
{
    int i=0;
    while(1)
    {
        int index=_hash(s.id, i);
        if(tracker[index]!=1)
        {
            hashtable[index]=s;
            tracker[index]=1;
            break;
        }
        else
        {
            i++;
            collision++;
        }

    }
}

/// find student for id=key
struct student _search(int key)
{
    int i=0;
    while(1)
    {
        int index=_hash(key, i);
        if(hashtable[index].id==key) // if the student matches
        {
            return hashtable[index]; // return the student

        } 
        else if(tracker[index]==0)
        {
            // not found, return the default student
            struct student s;
            return s;
        }
        else
        {
            // need to jump
            i++;
        }
    }
}


///delete student with id=key
void _delete(int key)
{
    int i=0;
    while(1)
    {
        int index=_hash(key, i);
        if(hashtable[index].id==key) // if the student matches
        {
            tracker[index]=-1; // deleted

        }
        else if(tracker[index]==0)
        {
            // not found, return the default student
            return;
        }
        else
        {
            // need to jump
            i++;
        }
    }

}



int main()
{
    int student_count;
    cin>>student_count;
    for(int i=0;i<student_count;i++)
    {
        struct student s;
        cin>>s.id>>s.name>>s.CGPA;
        _insert(s);

    }






}