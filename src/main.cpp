#include "include/list.h"
#include "include/database.h"

int main(int argc, char const *argv[])
{
    List simpleList;
    Database data;

    if (argc > 1) {
        simpleList.name = string(argv[1]);
        simpleList.print_menu();
        data.write(simpleList.list);
        data.read();
    } else {
        cout << "Username not supplied... exiting the program" << endl;
    }

    

    return 0;
}

