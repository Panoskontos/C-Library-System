//Library System

#include <iostream>
#include <algorithm>

using namespace std;

struct user
{
    string name;
    int id;
    bool borrow_book = false;
    bool return_book = false;
    string which_book;
};

struct library
{
    string books[100];
    int ids[100];
    int quantity[100];
    user users[100];
    int been_borrowed[100]{};
    int books_len = 0;
    int users_len = 0;

    void run()
    {
        while (true)
        {
            int choice = menu();
            if (choice == 1)
                add_book();
            if (choice == 2)
                search_book();
            if (choice == 3)
                print_borrowers();
            if (choice == 4)
                sort_name();
            if (choice == 5)
                sort_id();
            if (choice == 6)
                add_user();
            if (choice == 7)
                user_borrow();
            if (choice == 8)
                user_returned();
            if (choice == 9)
                print_users();
            if (choice == 10)
                break;
        }
    }

    int menu()
    {
        cout << "\n";
        cout << "Library menu:\n";
        cout << "1) add book\n";
        cout << "2) search books\n";
        cout << "3) print borrower\n";
        cout << "4) print books by name\n";
        cout << "5) print books by id\n";
        cout << "6) add_user\n";
        cout << "7) user borrowed\n";
        cout << "8) user returned\n";
        cout << "9) print users\n";
        cout << "10) exit\n";
        cout << "\n";
        cout << "Enter your choice [1-10]:";
        int input;
        cin >> input;
        return input;
    }

    void add_book()
    {
        cout << "\n";
        cout << "Enter book's id , name and how many: \n";
        int id, how_many;
        string name;
        cin >> id >> name >> how_many;
        books[books_len] = name;
        ids[books_len] = id;
        quantity[books_len] = how_many;
        books_len++;
    }

    void add_user()
    {
        cout << "\n";
        cout << "Enter user's name & id\n";
        string name;
        int id;
        cin >> name >> id;
        users[users_len].name = name;
        users[users_len].id = id;
        users_len++;
    }

    void print_users()
    {
        cout << "\n";
        cout << "*******************\n";
        for (int i = 0; i < users_len; i++)
        {
            cout << users[i].id << " " << users[i].name << "\n";
        }
    }

    int isprefix(string a, string b)
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (b[i] != a[i])
            {
                return 0;
            }
        }
        return 1;
    }

    void search_book()
    {
        cout << "\n";
        cout << "Enter prefix:\n";
        string prefix;
        cin >> prefix;
        bool notfound = true;
        for (int i = 0; i < books_len; i++)
        {
            if (isprefix(prefix, books[i]))
            {
                cout << "Results found\n";
                cout << books[i] << "\n";
                notfound = false;
            }
        }
        if (notfound)
        {
            cout << "No results were found\n";
        }
    }

    void sort_name()
    {
        sort(books, books + books_len);
        cout << "****************************************\n";
        for (int i = 0; i < books_len; i++)
        {
            cout << books[i];
            cout << " at quantity " << quantity[i];
            cout << " total borrowed " << been_borrowed[i] << "\n";
        }
        cout << "*****************************************\n";
    }

    void sort_id()
    {
        sort(ids, ids + books_len);
        cout << "****************************************\n";
        for (int i = 0; i < books_len; i++)
        {
            cout << ids[i] << " " << books[i];
            cout << " at quantity " << quantity[i];
            cout << " total borrowed " << been_borrowed[i] << "\n";
        }
        cout << "*****************************************\n";
    }

    void user_borrow()
    {
        cout << "Enter book and user that borrowed it\n";
        string user, book;
        bool book_notfound = true;
        cin >> book >> user;
        for (int i = 0; i < books_len; i++)
        {
            if (book == books[i])
            {
                book_notfound = false;
                if (quantity[i] > 0)
                {
                    cout << "Book is available at " << quantity[i] << " copies\n";
                    quantity[i]--;
                    been_borrowed[i]++;
                }
                else
                {
                    cout << " No copies are available \n";
                    return;
                }
            }
        }
        if (book_notfound)
            cout << "No book with this name is found\n";
        else
        {
            for (int i = 0; i < users_len; i++)
            {
                if (user == users[i].name)
                {
                    cout << "user also found\n";
                    users[i].borrow_book = true;
                    users[i].which_book = book;
                    cout << "book has successfully been borrowed\n";
                }
            }
        }
    }

    void user_returned()
    {
        cout << "Enter book and user that has returned\n";
        string user, book;
        cin >> book >> user;
        bool book_notfound = true;
        for (int i = 0; i < books_len; i++)
        {
            if (book == books[i])
            {
                book_notfound = false;
                quantity[i]++;
                been_borrowed[i]--;
            }
        }
        if (book_notfound)
            cout << "No book with this name is found";
        else
        {
            for (int i = 0; i < users_len; i++)
            {
                if (user == users[i].name)
                {
                    cout << "user also found\n";
                    users[i].borrow_book = false;
                    users[i].which_book = "";
                    users[i].return_book = true;
                    cout << "book has successfully been returned\n";
                }
            }
        }
    }

    void print_borrowers()
    {
        cout << "Enter book you want to search\n";
        string book;
        cin >> book;
        cout << "*******************************\n";
        cout << book << " has been borrowed by \n";
        for (int i = 0; i < users_len; i++)
        {
            if (book == users[i].which_book)
            {
                cout << users[i].name << "\n";
            }
        }
    }
};

int main()
{
    library x;
    x.run();

    return 0;
}

//-----------------------------X Generator Function-- ---------------------------------

void x_generator(int n)
{

    int spacebetween = n - 2;
    int spaceleft = 0;
    for (int i = 0; i < n; i++)
    {

        if (i < n / 2)
        {
            for (int j = 0; j < spaceleft; j++)
            {
                std::cout << " ";
            }
            std::cout << "*";
            for (int j = 0; j < spacebetween; j++)
            {
                std::cout << " ";
            }
            std::cout << "*"
                      << "\n";

            spaceleft++;
            spacebetween -= 2;
        }
        else if (i == n / 2)
        {

            for (int j = 0; j < n / 2; j++)
            {
                std::cout << " ";
            }
            std::cout << "*"
                      << "\n";
        }
        else
        {
            --spaceleft;
            spacebetween += 2;
            for (int j = 0; j < spaceleft; j++)
            {
                std::cout << " ";
            }
            std::cout << "*";
            for (int j = 0; j < spacebetween; j++)
            {
                std::cout << " ";
            }
            std::cout << "*"
                      << "\n";
        }
    }
}
