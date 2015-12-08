#ifndef CONNECTTAB_H
#define CONNECTTAB_H
#include <string>


class ConnectTab
{
public:
    ConnectTab(std::string nameSci, std::string nameCom);
    std::string getSciName();
    std::string getComName();
private:
    std::string nameSci, nameCom;
};

#endif // CONNECTTAB_H
