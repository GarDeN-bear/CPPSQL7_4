#include "MySQL.h"

MySQL::MySQL(std::string host_, std::string port_, std::string dbname_, 
                std::string user_, std::string password_) {
    host = host_;
    port = port_;
    dbname = dbname_;
    user = user_;
    password = password_;
    try{
        std::cout << "Connection is ready\n";
        c = std::make_unique<pqxx::connection>("host=" + host + " " + 
            "port=" + port + " " +
            "dbname=" + dbname + " " +
            "user=" + user + " " +
            "password=" + password + " ");
    }
    catch (std::exception& ex){
        std::cout << "Error: " << ex.what() << std::endl;
    }
}

void MySQL::createTable(std::string sqlQueryCrTab){
    pqxx::work tx{*c};
    std::cout << "Table created successfully";
    tx.exec(sqlQueryCrTab);
    tx.commit();
}
void MySQL::addClient(std::string table, std::string first_name, std::string last_name, 
                        std::string email, std::string phone_number){
    pqxx::work tx{*c};
    std::string insert = "INSERT INTO " + tx.esc(table) + " (first_name, last_name, email, phone_number) VALUES ('" + 
            tx.esc(first_name) + "', '" + tx.esc(last_name) + "', '" +
            tx.esc(email) + "', '" + tx.esc(phone_number) + "')";
    std::cout << "Client added successfully";
    tx.exec(insert);
    tx.commit();
}