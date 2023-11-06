#pragma once

#include <sqlite3.h>
#include <iostream>

class Database {
public:
    Database(const char* dbPath);
    ~Database();

    bool openConnection();
    void closeConnection();

    bool executeQuery(const char* query);

    sqlite3* getConnection() const; 

private:
    sqlite3* db;
    const char* dbPath;
};

class DatabaseContext {
public:
    DatabaseContext(Database& database);
    ~DatabaseContext();

private:
    Database& db;
};