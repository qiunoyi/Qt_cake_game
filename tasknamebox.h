#ifndef TASKNAMEBOX_H
#define TASKNAMEBOX_H

#include <QWidget>
#include <QLineEdit>
class TaskNameBox : public QWidget
{
    Q_OBJECT
public:
    explicit TaskNameBox(QWidget *parent = nullptr);

signals:void inputComplete(QString name);

};

#endif // TASKNAMEBOX_H
