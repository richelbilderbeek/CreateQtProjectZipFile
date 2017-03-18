#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#include "qtcreateqtprojectzipfilemaindialog.h"

#include <fstream>

#include <boost/lexical_cast.hpp>

#include <QFile>
#include <QFileDialog>
#include <QKeyEvent>
#include <QListWidgetItem>
#include <QMessageBox>

#include "createqtprojectzipfilemenudialog.h"
#include "createqtprojectzipfilemaindialog.h"
#include "fileio.h"
#include "qtcreatorprofilezipscript.h"
#include "ui_qtcreateqtprojectzipfilemaindialog.h"

#pragma GCC diagnostic pop

ribi::QtCreateQtProjectZipFileMainDialog::QtCreateQtProjectZipFileMainDialog(QWidget *parent) noexcept :
  QtHideAndShowDialog(parent),
  ui(new Ui::QtCreateQtProjectZipFileMainDialog)
{
  ui->setupUi(this);
  ui->lineEdit->setText("Tools/ToolCreateQtProjectZipFile");
}

ribi::QtCreateQtProjectZipFileMainDialog::~QtCreateQtProjectZipFileMainDialog() noexcept
{
  delete ui;
}

void ribi::QtCreateQtProjectZipFileMainDialog::CreateScript(const std::string source_folder) noexcept
{
  const std::string text = QtCreatorProFileZipScript::CreateScript(source_folder);
  ui->text->setPlainText(text.c_str());
}

void ribi::QtCreateQtProjectZipFileMainDialog::keyPressEvent(QKeyEvent * event) noexcept
{
  if (event->key() == Qt::Key_Escape) { close(); return; }
}

void ribi::QtCreateQtProjectZipFileMainDialog::on_lineEdit_textChanged(const QString &arg1) noexcept
{
  const std::string source_folder = "../../" + arg1.toStdString();

  if (!QFile::exists(source_folder.c_str()))
  {
    const std::string text = "Folder '" + source_folder + "' does not exist.";
    ui->text->setPlainText(text.c_str());
    return;
  }
  CreateScript(source_folder);
}
