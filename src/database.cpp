#include "../include/Database.h"

Database::Database(const char* dbPath) : db(nullptr), dbPath(dbPath) {}

Database::~Database() {
    closeConnection();
}

bool Database::openConnection(){
    int result = sqlite3_open(dbPath, &db);
    return result == SQLITE_OK;
}

void Database::closeConnection(){
    if(db){
        sqlite3_close(db);
        db = nullptr;
    }
}

bool Database::executeQuery(const char* query){
    char* errMsg = nullptr;
    int result = sqlite3_exec(db, query, nullptr, nullptr, &errMsg);

    if(result != SQLITE_OK){
        std::cerr << "Error executing query: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }

    return true;
}

sqlite3* Database::getConnection() const {
    return db;
}

DatabaseContext::DatabaseContext(Database& database) : db(database) {
   if(!db.openConnection()){
    std::cerr << "Error opening database connection" << std::endl;
   }
}

DatabaseContext::~DatabaseContext(){
    db.closeConnection();
}