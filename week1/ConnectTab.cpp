#include "ConnectTab.h"
using namespace std;

ConnectTab::ConnectTab(std::string nameSci, std::string nameCom)
{
    this -> nameSci = nameSci;
    this -> nameCom = nameCom;

}
std::string ConnectTab::getSciName(){
    return nameSci;
}
std::string ConnectTab::getComName(){
    return nameCom;
}
