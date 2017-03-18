#ifndef QTCREATEQTPROJECTZIPFILEMENUDIALOG_H
#define QTCREATEQTPROJECTZIPFILEMENUDIALOG_H

#include "qthideandshowdialog.h"

namespace Ui {
class QtCreateQtProjectZipFileMenuDialog;
}

namespace ribi {

class QtCreateQtProjectZipFileMenuDialog : public QtHideAndShowDialog
{
  Q_OBJECT //!OCLINT

public:
  explicit QtCreateQtProjectZipFileMenuDialog(QWidget *parent = 0) noexcept;
  QtCreateQtProjectZipFileMenuDialog(const QtCreateQtProjectZipFileMenuDialog&) = delete;
  QtCreateQtProjectZipFileMenuDialog& operator=(const QtCreateQtProjectZipFileMenuDialog&) = delete;
  ~QtCreateQtProjectZipFileMenuDialog() noexcept;

protected:
  void keyPressEvent(QKeyEvent *) noexcept;

private slots:
  void on_button_start_clicked() noexcept;
  void on_button_about_clicked() noexcept;
  void on_button_quit_clicked() noexcept;

private:
  Ui::QtCreateQtProjectZipFileMenuDialog *ui;
};

} //~namespace ribi

#endif // QTCREATEQTPROJECTZIPFILEMENUDIALOG_H
