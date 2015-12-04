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

using namespace std;
void ScientistRepository::openDatabase() {

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "Computers.sqlite";
    db.setDatabaseName("Computers.sqlite");

    db.open();
    QSqlQuery query(db);

    string queryCreate = "CREATE TABLE Computers(id INTEGER, Name VARCHAR, Year built INTEGER, Type VARCHAR, Built(yes/no)? VARCHAR);";
        query.exec(QString(queryCreate.c_str()));

        while(query.next()) {
            int id = query.value("id").toUInt();
            string name = query.value("name").toString().toStdString();
            string year_built = query.value("Year built").toString().toStdString();
            string type = query.value("type").toString().toStdString();
            string built = query.value("Built(yes/no)?").toString().toStdString();



        }

    /*string queryCreate = "CREATE TABLE Computers(id INTEGER, name VARCHAR, Year built INTEGER, Type VARCHAR, Built(yes/no)? VARCHAR)";
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

ScientistRepository::ScientistRepository()
{
    fileName = constants::DATA_FILE_NAME;
}

std::vector<Scientist> ScientistRepository::getAllScientists()
{
    ifstream file;

    file.open(fileName.c_str());

    vector<Scientist> scientists;

    if (file.is_open())
    {
        string line;
        while(getline(file, line))
        {
            vector<string> fields = utils::splitString(line, constants::FILE_DELIMETER);

            if (fields.size() >= 3)
            {
                string name = fields.at(0);
                enum sexType sex = utils::stringToSex(fields.at(1));
                int yearBorn = utils::stringToInt(fields.at(2));

                if (fields.size() == 3)
                {
                    scientists.push_back(Scientist(name, sex, yearBorn));
                }
                else
                {
                    int yearDied = utils::stringToInt(fields.at(3));

                    scientists.push_back(Scientist(name, sex, yearBorn, yearDied));
                }
            }
        }
    }

    file.close();

    return scientists;
}

vector<Scientist> ScientistRepository::searchForScientists(string searchTerm)
{
    vector<Scientist> allScientists = getAllScientists();
    vector<Scientist> filteredScientists;

    for (unsigned int i = 0; i < allScientists.size(); i++)
    {
        if (allScientists.at(i).contains(searchTerm))
        {
            filteredScientists.push_back(allScientists.at(i));
        }
    }

    return filteredScientists;
}

bool ScientistRepository::addScientist(Scientist scientist)
{
    ofstream file;

    file.open(fileName.c_str(), std::ios::app);

    if (file.is_open())
    {
        string name = scientist.getName();
        enum sexType sex = scientist.getSex();
        int yearBorn = scientist.getYearBorn();
        int yearDied = scientist.getYearDied();

        file << name << constants::FILE_DELIMETER
             << sex << constants::FILE_DELIMETER
             << yearBorn << constants::FILE_DELIMETER;

        if (yearDied != constants::YEAR_DIED_DEFAULT_VALUE)
        {
            file << yearDied;
        }

        file << '\n';
    }
    else
    {
        return false;
    }

    file.close();
    return true;
}
