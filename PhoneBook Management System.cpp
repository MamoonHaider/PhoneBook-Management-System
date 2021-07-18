#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include "Trie.h"
#include "Stack.h"
#include "LinkedList.h"

using namespace std;

struct Book
{
    string name;
    string number;
    bool operator==(Book obj)
    {
        return name == obj.name;
    }
    bool operator!=(Book obj)
    {
        return name != obj.name;
    }
};

void writePhonebook(Book obj1) //user defined function declaration
{

    ofstream phonebook;                        //variable for class fstream that is name of our file
    phonebook.open("Phonebook.txt", ios::app); //it will open the file to write
    if (!phonebook)                            //it will check if the file exists or not
    {
        cout << "File creation failed"; //if the file exists it will give error
    }
    else //if the file does exist it will execute this part
    {
        phonebook << obj1.name << endl;
        phonebook << obj1.number << endl;
    }
    phonebook.close(); //this statement will close file after writing so no other data can get into it
}
DoubleLinkedList<Book> *readPhonebook(Book obj1, Trie ob) //declaration of file reading function
{
    DoubleLinkedList<Book> *obj5 = new DoubleLinkedList<Book>();
    ifstream phonebook1;              //name of data type to read data from a file
    phonebook1.open("Phonebook.txt"); //it will open a file to read from
    if (!phonebook1)
    {
    }
    else
    {
        while (!phonebook1.eof())
        {
            getline(phonebook1, obj1.name);
            if (obj1.name.length() > 1)
            {
                getline(phonebook1, obj1.number);
                ob.insert(obj1.name);
                obj5->insertionAtEnd(obj1);
            }
        }
    }

    phonebook1.close(); //closes file being read

    return obj5;
}
void writeCallHistory(Book obj1) //user defined function declaration
{

    ofstream callHistory;                          //variable for class fstream that is name of our file
    callHistory.open("CallHistory.txt", ios::app); //it will open the file to write
    if (!callHistory)                              //it will check if the file exists or not
    {
        cout << "File creation failed"; //if the file exists it will give error
    }
    else //if the file does exist it will execute this part
    {
        callHistory << obj1.number << endl;
        callHistory << obj1.name << endl;
        //this statement will close file after writing so no other data can get into it
    }
    callHistory.close();
}

Stack<string> readCallHistory() //declaration of file reading function
{
    Book obj1;
    Stack<string> obj2;
    ifstream callHistory1;                //name of data type to read data from a file
    callHistory1.open("CallHistory.txt"); //it will open a file to read from
    if (!callHistory1)                    //if the file does not esists it will give error
    {
    }
    else //if the file exists it will execute this part
    {
        while (!callHistory1.eof())
        {
            getline(callHistory1, obj1.name);
            getline(callHistory1, obj1.number);
            if (obj1.name.length() > 0)
            {
                obj2.push(obj1.name);
                obj2.push(obj1.number);
            }
        }
    }
    callHistory1.close(); //closes file being read
    return obj2;
}

void clearFile(string filename)
{
    std::ofstream ofs;
    ofs.open(filename);
    ofs.clear();
    ofs.close();
}

bool validateAlphaString(string name) //user defined function declaration
{

    for (const char c : name)
    {
        if (!isalpha(c) && !isspace(c))
            return false;
    }

    return true;
}
bool validateNumString(string name) //user defined function declaration
{

    for (const char c : name)
    {
        if (!isdigit(c) && !isspace(c))
            return false;
    }

    return true;
}
string getValidName()
{
    string str;
    cin >> str;
    while (!validateAlphaString(str))
    {
        cout << "Wrong Input!please Use only alphabets for name" << endl;
        cout << "Enter Name:  ";
        cin >> str;
    }
    return str;
}
string getValidNumber()
{
    string number;
    int length;
    cin >> number;
    length = number.length();
    //this loop will check if the length of the phone number is correct or not
    while (length != 10 && length != 11)
    {
        cout << "Number is not correct Please Enter(10 - 11 digits) " << endl;
        cout << "Enter Number :  ";
        cin >> number;
        length = number.length();
    }

    while (!validateNumString(number))
    {

        cout << "Wrong Input!please Use only Integers for Number" << endl;
        cout << "Enter Number :  ";
        cin >> number;
    }

    return number;
}

string lowerString(string str) //This function converts Uppercase letter into lower case
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 32; //adding 32 in will change ASCII code and convert it into lower case
        }
    }
    return str;
}

int main()
{
    Book obj1;
    Trie ob;
    DoubleLinkedList<Book> *obj;
    Stack<string> obj2;
    int n = 1, choice;
    obj = readPhonebook(obj1, ob);
    obj2 = readCallHistory();
    while (n == 1)
    {
        system("cls");
        ob.insert("");
        cout << " \n"
             << endl;
        cout << "*************************************************************" << endl;
        cout << "~~~~~~~~~~~~~~            PHONEBOOK            ~~~~~~~~~~~~~~" << endl;
        cout << "*************************************************************" << endl;
        cout << " \n"
             << endl;
        cout << "1. Add new Contact" << endl;
        cout << "2. See all Contact" << endl;
        cout << "3. Search Contact" << endl;
        cout << "4. Delete Contact" << endl;
        cout << "5. Modify/Update Contact" << endl;
        cout << "6. Make Call" << endl;
        cout << "7. See Call History" << endl;
        cout << "8. Delete Call History" << endl;
        cout << "9. Quit" << endl;
        cout << " \n"
             << endl;
        //This while loop is used to validate input from the user
        while ((cin >> choice).fail() || cin.peek() != '\n' || choice < 1 || choice > 9)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Option\n";
            cout << "Please enter a number from 1 to 8:";
        }
        if (choice == 1)
        {
            system("cls");
            int q = 1;
            cout << "************************\n";
            cout << "----- Add a contact ----\n";
            cout << "************************\n";
            while (q == 1)
            {
                cout << "Enter name        :  ";
                Book obj4;
                obj4.name = getValidName();
                obj1.name = obj4.name;
                obj1 = obj->findingList(obj1);
                if (obj1.name == obj4.name)
                {
                    cout << "This contact name already exists" << endl;
                }
                else
                {
                    obj1.name = obj4.name;
                    obj1.name = lowerString(obj1.name);
                    cout << "Enter Phone Number:  ";
                    obj1.number = getValidNumber();
                    ob.insert(obj1.name);
                    obj->insertionAtEnd(obj1);
                    writePhonebook(obj1);
                    cout << "New contact saved successfully!" << endl;
                }
                cout << "Do you want to Save Another Number? 1/0:  ";
                cin >> q;
            }
        }

        else if (choice == 2)
        {
            system("cls");
            cout << "**************************\n";
            cout << "-----List of Contacts-----" << endl;
            cout << "**************************\n";
            ob.traverse();
            system("pause");
        }

        else if (choice == 3)
        {
            system("cls");
            cout << "**************************\n";
            cout << "-----Search a contact ----\n";
            cout << "**************************\n";
            string str = {};
            char ch;
            cout << "\nEnter Name to search: ";
            ch = _getch();
            if (ch <= 90 && ch >= 65)
            {
                ch = ch + 32;
            }
            //This Loop will input ch from user and will keep on suggesting names until ENTER is pressed
            while (ch != 13) //13 is ASCII code of ENTER key so while loop will continue until Enter is pressed
            {

                system("cls");
                if (ch == 8) //8 is ASCII code of Backspace key so when backspace is pressed it will pop character
                {
                    if (str.length() > 0)
                    {
                        str.pop_back();
                    }
                }
                else
                {
                    if (ch >= 97 && ch <= 122)
                    {
                        str.push_back(ch);
                    }
                }
                cout << "**************************\n";
                cout << "-----Search a contact ----\n";
                cout << "**************************\n";
                cout << "\nEnter Name to search: " << str << endl;
                cout << "\n\n----   Suggestions -----" << endl;
                ob.printAutoSuggestions(str);
                ch = _getch();
                if (ch <= 90 && ch >= 65)
                {
                    ch = ch + 32;
                }
            }
            Book obj4;
            obj4.name = str;
            obj1.name = obj4.name;
            obj1 = obj->findingList(obj1);
            if (obj1.name == obj4.name)
            {
                cout << "Name   : " << obj1.name << endl;
                cout << "Number : " << obj1.number << endl;
            }
            else
            {
                cout << "Sorry! No such contact found." << endl;
            }
            system("pause");
        }
        else if (choice == 4)
        {
            system("cls");
            cout << "************************\n";
            cout << "--- Delete a contact ---\n";
            cout << "************************\n";

            string str = {};
            char ch;
            cout << "\nEnter Name to delete: ";
            ch = _getch();
            if (ch <= 90 && ch >= 65)
            {
                ch = ch + 32;
            }
            //This Loop will input ch from user and will keep on suggesting names until ENTER is pressed
            while (ch != 13) //13 is ASCII code of ENTER key so while loop will continue until Enter is pressed
            {
                system("cls");
                if (ch == 8) //8 is ASCII code of Backspace key so when backspace is pressed it will pop character
                {
                    if (str.length() > 0)
                    {
                        str.pop_back();
                    }
                }
                else
                {
                    if (ch >= 97 && ch <= 122)
                    {
                        str.push_back(ch);
                    }
                }
                cout << "************************\n";
                cout << "--- Delete a contact ---\n";
                cout << "************************\n";
                cout << "\nEnter name to Delete: " << str << endl;
                cout << "\n\n-----   Suggestions ----" << endl;
                ob.printAutoSuggestions(str);
                ch = _getch();
                if (ch <= 90 && ch >= 65)
                {
                    ch = ch + 32;
                }
            }
            Book obj4;
            obj4.name = str;
            obj1.name = obj4.name;
            obj1 = obj->findingList(obj1);
            if (obj1.name == obj4.name)
            {
                if (obj1.name.length() > 0)
                {
                    cout << "Name  : " << obj1.name << endl;
                    cout << "Number: " << obj1.number << endl;
                    ob.Delete(obj1.name);
                    Book obj3;
                    obj3.name = obj1.name;
                    obj->deletionAtMiddle(obj3);
                    clearFile("Phonebook.txt");
                    obj->overWriting();
                    cout << "Contact deleted successfully!\n";
                }
                else
                {
                    cout << "Contact dosen't Exist" << endl;
                }
            }
            else
            {
                cout << "This contact already does not exists" << endl;
            }
            system("pause");
        }
        else if (choice == 5)
        {
            system("cls");
            Book obj7;
            cout << "*************************\n";
            cout << "-----Modify a contact----\n";
            cout << "*************************\n";

            string str = {};
            char ch;
            cout << "\nEnter Name to modify: ";
            ch = _getch();
            if (ch <= 90 && ch >= 65)
            {
                ch = ch + 32;
            }
            //This Loop will input ch from user and will keep on suggesting names until ENTER is pressed
            while (ch != 13) //13 is ASCII code of ENTER key so while loop will continue until Enter is pressed
            {
                system("cls");
                if (ch == 8) //8 is ASCII code of Backspace key so when backspace is pressed it will pop character
                {
                    if (str.length() > 0)
                    {
                        str.pop_back();
                    }
                }
                else
                {
                    if (ch >= 97 && ch <= 122)
                    {
                        str.push_back(ch);
                    }
                }
                cout << "*************************\n";
                cout << "-----Modify a contact----\n";
                cout << "*************************\n";
                cout << "\nEnter Name To Modify:  " << str << endl;
                cout << "\n\n-----   Suggestions ----" << endl;
                ob.printAutoSuggestions(str);
                ch = _getch();
                if (ch <= 90 && ch >= 65)
                {
                    ch = ch + 32;
                }
            }
            Book obj4;
            obj4.name = str;
            obj1.name = obj4.name;
            obj1 = obj->findingList(obj1);
            if (obj1.name == obj4.name)
            {
                if (obj1.name.length() > 0)
                {
                    cout << "Name  : " << obj1.name << endl;
                    cout << "Number: " << obj1.number << endl;
                    ob.Delete(obj1.name);
                    obj7.name = obj1.name;
                    obj->deletionAtMiddle(obj7);
                    clearFile("Phonebook.txt");
                    obj->overWriting();
                    cout << "Enter New Name        :  ";
                    obj1.name = getValidName();
                    cout << "Enter New Phone Number:  ";
                    obj1.number = getValidNumber();
                    cout << "Contact Updated successfully!";
                    ob.insert(obj1.name);
                    obj->insertionAtEnd(obj1);
                    writePhonebook(obj1);
                }
                else
                {
                    cout << "Contact dosen't Exist" << endl;
                }
            }
            else
            {
                cout << "Sorry! No such contact found." << endl;
            }
            system("pause");
        }

        else if (choice == 6)
        {
            char choice1;
            system("cls");
            cout << "************************\n";
            cout << "-------Make a call------\n";
            cout << "************************\n";
            cout << "Do you want to call from phonebook contact or not? (y/n)" << endl;
            cin >> choice1;
            system("cls");
            if (choice1 == 'y' || choice1 == 'Y')
            {

                string str = {};
                char ch;
                cout << "************************\n";
                cout << "-------Make a call------\n";
                cout << "************************\n";
                cout << "\nEnter Name to call: ";
                ch = _getch();
                if (ch <= 90 && ch >= 65)
                {
                    ch = ch + 32;
                }
                //This Loop will input ch from user and will keep on suggesting names until ENTER is pressed
                while (ch != 13) //13 is ASCII code of ENTER key so while loop will continue until Enter is pressed
                {
                    system("cls");
                    if (ch == 8) //8 is ASCII code of Backspace key so when backspace is pressed it will pop character
                    {
                        if (str.length() > 0)
                        {
                            str.pop_back();
                        }
                    }
                    else
                    {
                        if (ch >= 97 && ch <= 122)
                        {
                            str.push_back(ch);
                        }
                    }
                    cout << "************************\n";
                    cout << "-------Make a call------\n";
                    cout << "************************\n";
                    cout << "\nEnter Name to call: " << str << endl;
                    cout << "\n\n-----   Suggestions ----" << endl;
                    ob.printAutoSuggestions(str);
                    ch = _getch();
                    if (ch <= 90 && ch >= 65)
                    {
                        ch = ch + 32;
                    }
                }
                Book obj4;
                obj4.name = str;
                obj1.name = obj4.name;
                obj1 = obj->findingList(obj1);
                if (obj1.name == obj4.name)
                {
                    cout << "-----Calling-----\n";
                    cout << "Name  : " << obj1.name << endl;
                    cout << "Number: " << obj1.number << endl;
                }
                else
                {
                    cout << "Sorry! No such contact found." << endl;
                }
            }

            else if (choice1 == 'n' || choice1 == 'N')
            {
                cout << "************************\n";
                cout << "-------Make a call------\n";
                cout << "************************\n";

                cout << "Enter Number";
                obj1.number = getValidNumber();
                obj1.name = "unknown";
                cout << "-----Calling----\n";
                cout << "Name  : " << obj1.name << endl;
                cout << "Number: " << obj1.number << endl;
            }
            writeCallHistory(obj1);
            obj2.push(obj1.number);
            obj2.push(obj1.name);
            system("pause");
        }

        else if (choice == 7)
        {
            obj2 = readCallHistory();
            system("cls");
            cout << "************************\n";
            cout << "-------Call History-----\n";
            cout << "************************\n";

            while (!obj2.isEmpty())
            {
                cout << obj2.pop() << endl;
            }
            system("pause");
        }
        else if (choice == 8)
        {
            cout << "Are you sure? (y/n)\n";
            char ch1 = getch();
            if (ch1 == 'y' || ch1 == 'Y')
            {
                clearFile("CallHistory.txt");
                cout << "Call History deleted successfully\n";
                obj2 = readCallHistory();
                system("pause");
            }
            else
            {
                cout << "Exited\n";
                n = 1;
            }
        }
        else if (choice == 9)
        {
            n = 0;
        }
    }
    return 0;
}
