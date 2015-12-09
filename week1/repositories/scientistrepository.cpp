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

    return db;

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

    query.prepare("INSERT INTO ConnectTable (Scientist_id, Computer_id)" "VALUES (:id_sci, :id_com)");
    query.bindValue(":id_sci", inputScientists);
    query.bindValue(":id_com", inputComputers);
    query.exec();

}

ScientistRepository::ScientistRepository() {
    fileName = constants::DATA_FILE_NAME;
}

