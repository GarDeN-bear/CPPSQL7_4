#include <iostream>
#include "MySQL.h"

int main(){
    MySQL mySQL("localhost", "5432", "CPPSQL7_4", "postgres", "GarDeN001");
    std::string sqlQueryCrTab = "CREATE TABLE IF NOT EXISTS client (id SERIAL PRIMARY KEY, "
                            "first_name VARCHAR(50) NOT NULL, "
                            "last_name VARCHAR(50) NOT NULL, "
                            "email VARCHAR(50) UNIQUE NOT NULL, "
                            "phone_number VARCHAR(100) UNIQUE);";
    mySQL.createTable(sqlQueryCrTab);
    mySQL.addClient("client", "Денис", "Гарпинич", "garpinich22@mail.ru", "896230451, 89031840300");
    // pqxx::connection c(
    //     "host=localhost "
    //     "port=5432 "
    //     "dbname=CPPSQL7_4 "
    //     "user=postgres "
    //     "password=GarDeN001"
    // );
    // std::string create_table;
    // tx.exec("INSERT INTO client(first_name, last_name, email, phone_number) "
    // "VALUES('Денис', 'Гарпинич', 'garpinich22@mail.ru', '89623740451, 89031840300')");
    // tx.commit();

    // }
    // catch(std::exception& ex){
    //     std::cout << "Error: " << ex.what() << std::endl;
    // }
    



    return 0;
}