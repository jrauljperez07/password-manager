#include <iostream>
#include <sqlite3.h>
#include "./include/Database.h"

using namespace std;

int main(){
    const char* dbPath = "/Users/jrauljperez02/Desktop/Tec/Password_manager/main.db";
    Database db(dbPath);

    {
        DatabaseContext ctx(db);
        const char* createTableQuery = "SELECT * FROM core_users;";
        if (db.executeQuery(createTableQuery)) {
            std::cout << "Query successfully executed" << std::endl;
        }
    }


    return 0;
}