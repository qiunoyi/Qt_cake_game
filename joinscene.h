#ifndef JOINSCENE_H
#define JOINSCENE_H

#include <QWidget>

namespace Ui {
class JoinScene;
}

class JoinScene : public QWidget
{
    Q_OBJECT

public:
    explicit JoinScene(QWidget *parent = nullptr);
    ~JoinScene();
    Ui::JoinScene *ui;//这样不太安全其实
private:
};

#endif // JOINSCENE_H
