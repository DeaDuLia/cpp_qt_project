#ifndef MYQACTION_H
#define MYQACTION_H
#include <QAction>
#include <string>
#include <QString>
using namespace std;
class MyQAction : public QAction
{
    Q_OBJECT
public:
    explicit MyQAction(QString name) : QAction()
    {
        this->setText(name);
    }
};

#endif // MYQACTION_H
