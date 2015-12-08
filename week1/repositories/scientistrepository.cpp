#include "repositories/scientistrepository.h"
#include "utilities/utils.h"
#include "utilities/constants.h"
#include <QCoreApplication>
#include <QtSql>
#include "string"
#include <iostream>
#include <QString>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "Computer.h"
#include "ConnectTab.h"

using namespace std;
QSqlDatabase ScientistRepository::openDatabase() {

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "prufa.sqlite";
    db.setDatabaseName(dbName);

    db.open();
    //QSqlQuery query(db);
    //query.exec("INSERT INTO Computers VALUES (4, JT, 1994, artificial intelligent);");

    //query.exec("INSERT INTO Scientists VALUES (1, Einar, 1990, 1995, tegund, ja);");


    return db;

/*    QSqlQuery query(db);

    query.exec("INSERT INTO Scientists VALUES (1, Einar, 1990, 1995, tegund, ja);");


    query.prepare("SELECT * FROM Computers;");

    query.exec();

    query.exec("INSERT INTO Tables SELECT Scientists.Id, Computers.Id FROM Scientist INNER JOIN Computers ON Scientists.Id=Computers.Id ORDER BY Scientists.Name;");


    string queryCreate = "CREATE TABLE Computers(id INTEGER, Name VARCHAR, Year built INTEGER, Type VARCHAR, Built(yes/no)? VARCHAR);";
        query.exec(QString(queryCreate.c_str()));

    string queryCreate = "CREATE TABLE Computers(id INTEGER, name VARCHAR, Year built INTEGER, Type VARCHAR, Built(yes/no)? VARCHAR)";
    query.exec(Qstring(queryInsert.c_str()));

    string queryInsert = "INSERT INTO Computers VALUES(xxxxxxxxxxxxx)";
    if { query.exec(Qstring(queryInsert.c_str()));
        //ef þetta gerist þá gerum við eitthvað við gögnin
    }

    query.prepare("SELECT * FROM Computers WHERE id = :id);");

    while(query.next) {
        gDebug() << query.lastQuery
    }*/
}

vector<Computer> ScientistRepository::printComputers(){

    QSqlQuery query(openDatabase());

    query.prepare("Select * from Computers");
    query.exec();

    vector<Computer> k;

    while(query.next()) {
        int id = query.value("Id").toUInt();
        string name = query.value("Name").toString().toStdString();
        int yearBuilt = query.value("Year_build").toInt();
        string type = query.value("Type").toString().toStdString();
        //string built = query.value("Built(yes/no)?").toString().toStdString();

        Computer s(id, name, yearBuilt, type);

        k.push_back(s);
    }
    return k;
}
vector<ConnectTab> ScientistRepository::printConnectTable(){

    QSqlQuery query(openDatabase());

    query.prepare("SELECT s.name AS SciName, c.name AS ComName FROM ConnectTable connect JOIN Scientists s ON s.id = connect.Scientist_Id JOIN Computers c ON c.id = connect.Computer_Id");
    query.exec();

    vector<ConnectTab> c;

    while(query.next()) {
        string nameSci = query.value("SciName").toString().toStdString();
        string nameCom = query.value("ComName").toString().toStdString();

        ConnectTab m(nameSci, nameCom);
        c.push_back(m);
    }
    return c;

    printComputers();
    printScientists();
}

vector<Scientist> ScientistRepository::printScientists() {

    QSqlQuery query(openDatabase());

    query.prepare("Select * from Scientists");
    query.exec();

    vector<Scientist> v;

    while(query.next()) {
        int id = query.value("Id").toUInt();
        string name = query.value("Name").toString().toStdString();
        string gender = query.value("Gender").toString().toStdString();
        int birth = query.value("Birth_year").toUInt();
        int death = query.value("Year_of_death").toUInt();


        Scientist s(id, name, gender, birth, death);
        v.push_back(s);
    }
    return v;
}

void ScientistRepository::addPerson(std::string name, std::string sex, int yearBorn, int yearDeath){

    QSqlQuery query;
    query.prepare("INSERT INTO Scientists (Name, Gender, Birth_year, Year_of_death)" "VALUES (:Name, :Gender, :Birth_year, :Year_of_death)");
    query.bindValue(":Name", QString::fromStdString(name));
    query.bindValue(":Gender", QString::fromStdString(sex));
    query.bindValue(":Birth_year", (yearBorn));
    query.bindValue(":Year_of_death", (yearDeath));
    query.exec();
}

void ScientistRepository::addComputer(string name, int yearBuild, string type){

    QSqlQuery query;
    query.prepare("INSERT INTO Computers (Name, Year_build, Type)" "VALUES (:Name, :Year_build, :Type)");
    query.bindValue(":Name", QString::fromStdString(name));
    query.bindValue(":Year_build", yearBuild);
    query.bindValue(":Type", QString::fromStdString(type));
    query.exec();
}

void ScientistRepository::connectTables(int inputScientists, int inputComputers) {

    QSqlQuery query;

    //query.prepare("SELECT c.name, s.name FROM ConnectTable connect JOIN Scientists s ON s.id = connect.Scientist_Id JOIN Computers c \
    ON c.id = connect.Computer_Id");

    query.prepare("INSERT INTO ConnectTable (Scientist_id, Computer_id)" "VALUES (:id_sci, :id_com)");
    query.bindValue(":id_sci", inputScientists);
    query.bindValue(":id_com", inputComputers);
    query.exec();

    /*query.prepare("Select Name.Scientists, Name.Computers FROM Scientists JOIN Computers \
    WHERE Id.Scientists = inputScientists AS Scientist_Id AND Id.Computers = AS Computer_Id");
    query.exec();*/
}

ScientistRepository::ScientistRepository() {
    fileName = constants::DATA_FILE_NAME;
}

/*vector<Scientist> ScientistRepository::searchForScientists(string searchTerm) {

    vector<Scientist> allScientists = getAllScientists();
    vector<Scientist> filteredScientists;

    for (unsigned int i = 0; i < allScientists.size(); i++) {
        if (allScientists.at(i).contains(searchTerm)) {
            filteredScientists.push_back(allScientists.at(i));
        }
    }

    return filteredScientists;
}*/

