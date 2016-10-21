#ifndef CHANCEVARIABLE_H
#define CHANCEVARIABLE_H

#include <QDialog>

namespace Ui {
class ChanceVariable;
}

class ChanceVariable : public QDialog
{
    Q_OBJECT

public:
    explicit ChanceVariable(QWidget *parent = 0);
    ~ChanceVariable();

private slots:
    void on_Configurar_windowTitleChanged(const QString &title);

    void on_pushButton_clicked();

private:
    Ui::ChanceVariable *ui;
};

#endif // CHANCEVARIABLE_H
