#include<iostream>
#include<string.h>
using namespace std;

struct contacts
{
    string name;
    string phone;
};

struct MailList
{
    contacts contactArray[100];
    int mailSize = 0;
};

int strcmpx(const char * str1, const char * str2);

void showMenu();
void showContacts(MailList *mail);
int getTrueIndex();
void addContact(MailList *mail, contacts c);
void removeContact(MailList mail, string name);
contacts queryContact(MailList mail, string name);
void removeContact(int index, MailList mail);
void modifyContact(MailList mail, string name);

int main()
{

    int select = 0;
    MailList mail;
    // showContacts(&mail);
    // string name = "";
    // string phone = "";
    // cout << "input name: " << endl;
    // cin >> name;
    // cout << "input phone: " << endl;
    // cin >> phone;
    // contacts c = {
    //     name,
    //     phone
    // };
    // addContact(&mail, c);
    // showContacts(&mail);
    while (true)
    {
        showMenu();
        cout << "please enter: " << endl;
        cin >> select;
        // if (select < 1 || select > 4)
        // {
        //     continue;
        // }
        switch (select)
        {
            case 1:
            showContacts(&mail);
            break;
            case 2:
            {
                string name = "";
                string phone = "";
                cin >> name;
                cin >> phone;
                contacts c = {
                    name,
                    phone
                };
                addContact(&mail, c);
                break;
            }
            case 3:
            {
                string name = "";
                cout << "query : " << endl;
                cin >> name;
                contacts c = queryContact(mail, name);
                if (strcmpx(c.name.c_str(), "null") == 0)
                {
                    cout << "not found" << endl;
                }
                else
                {
                    cout << c.name << ":" << c.phone << endl;
                }
                break;
            }
            case 4:
            {
                return 0;
                break;
            }
            default:
                break;
            }
    }

    getchar();
    return 0;
}

int strcmpx(const char * str1, const char * str2)
{
    if(*str1==NULL || *str2==NULL)
    {
        cout<<"INPUT ERROR!"<<endl;
        return -1;
    }

    while(*str1!='\0' && *str2!='\0')
    {
        if(*str1>*str2)
        {
            return 1;
        } else if (*str1<*str2)
        {
            return -1;
        }
        str1++;
        str2++;
    }
    if(*str1!='\0' && *str2=='\0') return 1;
    else if(*str1=='\0' && *str2!='\0') return -1;
    return 0;
}

void showMenu()
{
    cout << "******" << endl;
    cout << "1.foreach information" << endl;
    cout << "2.add a contact" << endl;
    cout << "3.query information" << endl;
    cout << "4.exit" << endl;
    cout << "******" << endl;
}

void showContacts(MailList *mail)
{
    if (mail -> mailSize == 0)
    {
        cout << "empty data" << endl;
        return;
    }
    for (int i = 0; i < mail -> mailSize; i++)
    {
        cout << mail -> contactArray[i].name << ": " << mail -> contactArray[i].phone << endl;
    }
}

void addContact(MailList *mail, contacts c)
{
    int len = sizeof(mail -> contactArray) / sizeof(mail -> contactArray[0]);
    if (mail -> mailSize >= len)
    {
        cout << "index out" << endl;
        return;
    }
    mail -> contactArray[mail -> mailSize] = c;
    mail -> mailSize ++;
    cout << "success" << endl;
}

int getTrueIndex(MailList mail, string name)
{
    int index = -1;
    for (int i = 0; i < mail.mailSize; i++)
    {
        if (strcmpx(mail.contactArray[i].name.c_str(), name.c_str()) == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

// void removeContact(MailList mail, string name)
// {
//     int index = getTrueIndex(mail, name);
//     if (index != -1)
//     {
//         mail.contactArray[index].name = "";
//         mail.contactArray[index].phone = "";
//         mail.mailSize --;
//     } 
//     else 
//     {
//         cout << "not found" << endl;
//     }
// }

contacts queryContact(MailList mail, string name)
{
    contacts c = {
        "null",
        "null"
    };
    int index = getTrueIndex(mail, name);
    if (index != -1)
    {
        c.name = mail.contactArray[index].name;
        c.phone = mail.contactArray[index].phone;
        return c;
    }
    return c;
}

// void removeContact(int index, MailList mail)
// {
//     if (index < 0 || index >= mail.mailSize)
//     {
//         cout << "index out" << endl;
//         return;
//     }
//     mail.contactArray[index].name = "";
//     mail.contactArray[index].phone = "";
//     mail.mailSize --;
// }

void modifyContact(MailList mail, string name, string phone)
{
    int index = getTrueIndex(mail, name);
    if (index != -1)
    {
        mail.contactArray[index].name = name;
        mail.contactArray[index].phone = phone;
    } 
}
