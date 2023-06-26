#include <pqxx/pqxx>
#include <iostream>

int main(){
    try{
    pqxx::connection c(
        "host=localhost "
        "port=5432 "
        "dbname=CPPSQL7_3 "
        "user=postgres "
        "password=GarDeN001"
    );    
    std::cout << "good work!";
    }
    catch(std::exception& ex){
        std::cout << "Error: " << ex.what() << std::endl;
    }
    return 0;
}