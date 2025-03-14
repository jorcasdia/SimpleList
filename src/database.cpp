#include "include/database.h"

void Database::write(vector<vector<string>> mainList) {
    ofstream db;
    db.open("db/lists.sl");

    if (db.is_open()) {
        for (size_t user_index = 0; user_index < mainList[user_index].size(); user_index++) {
            for (size_t list_index = 0; list_index < mainList[user_index][list_index].size(); list_index++) {
                db << mainList[user_index][list_index] << "\n";
            }
            
        }
        
    } else {
        cout << "Cannot open file for writing.";
    }
    db.close();
}
vector<vector<string>> Database::read() {
    string line;
    ifstream db;
    db.open("db/lists.sl");

    vector<string> userList;

    if (db.is_open()) {
        while (getline(db, line, '\n')) {
            if (line.front() == '#') {
                cout << "Found a hashtag: " << line << "\n";
                line.erase(line.begin());
                userList.push_back(line);
            } else if (line.front() == '%') {
                cout << "Found a percentage: " << line << "\n";
                mainList.push_back(userList);
                userList.clear();
            } else {
                cout << "Found an item: " << line << "\n";
                userList.push_back(line);
            }
        }
        
    } else {
        cout << "Cannot open file for reading.";
    }
    db.close();

    return mainList;
}
