#include "tasknamebox.h"

TaskNameBox::TaskNameBox(QWidget *parent) : QWidget(parent)
{
QLineEdit *name=new QLineEdit(this);
connect(name,&QLineEdit::returnPressed,this,[=](){

    this->hide();
    emit this->inputComplete(name->text());
    this->close();

});
}
