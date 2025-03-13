#include "include/database.h"

void Database::write() {
    ofstream db;
    db.open("db/lists.sl");

    db.close();
}
void Database::read() {

}
