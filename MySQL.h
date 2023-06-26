#include <pqxx/pqxx>
#include <iostream>
#include <memory>

class MySQL{
public:
    MySQL(std::string host_, std::string port_, std::string dbname_, 
                std::string user_, std::string password_);
    void createTable(std::string sqlQueryCrTab);
    void addClient(std::string table, std::string first_name, std::string last_name, 
                    std::string email, std::string phone_number);
private:
    std::string host;
    std::string port;
    std::string dbname;
    std::string user;
    std::string password;
    std::unique_ptr<pqxx::connection> c;
};