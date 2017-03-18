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
#include "testtimer.h"
#include "trace.h"
#include "ui_qtcreateqtprojectzipfilemaindialog.h"

#pragma GCC diagnostic pop

void QtCreateQtProjectZipFileMainDialogTest() noexcept
{
  {
    const std::string pro_filename{"../../Tools/ToolCreateQtProjectZipFile/ToolCreateQtProjectZipFileDesktop.pro"};
    const boost::shared_ptr<const QtCreatorProFile> pro_file(
      new QtCreatorProFile(pro_filename));
    assert(pro_file);
    assert(fileio::FileIo().IsRegularFile(pro_filename));
    const boost::shared_ptr<const QtCreatorProFileZipScript> script(
      new QtCreatorProFileZipScript(pro_file));
    assert(script);

  }
  const TestTimer test_timer(__func__,__FILE__,1.0);
  //Test basic functions on this project with going two folders down
  const bool verbose{false};
  const std::vector<std::string> pro_filenames
    =
    {
      "../../Tools/ToolCreateQtProjectZipFile/ToolCreateQtProjectZipFileDesktop.pro",
      "../../Tools/ToolCodeToHtml/ToolCodeToHtmlDesktop.pro",
      "../../Tools/ToolKalmanFilterer/ToolKalmanFiltererDesktop.pro",
      "../../Projects/ProjectRichelBilderbeek/ProjectRichelBilderbeekDesktop.pro"
    };
  const int n_tests = std::count_if(
    pro_filenames.begin(), pro_filenames.end(),
      [](const std::string& filename)
      { return fileio::FileIo().IsRegularFile(filename); }
    );
  if (verbose)
  {
    const std::string s = "Testing "
      + boost::lexical_cast<std::string>(n_tests)
      + " / "
      + boost::lexical_cast<std::string>(pro_filenames.size());
    TRACE(s);
  }
  for (const std::string& pro_filename: pro_filenames)
  {
    if (!fileio::FileIo().IsRegularFile(pro_filename)) continue;
    if (!fileio::FileIo().IsFolder(pro_filename)) continue;
    const CreateQtProjectZipFileMainDialog d(pro_filename);
    assert(!d.GetScript().empty());
  }

  for (const std::string& pro_filename: pro_filenames)
  {
    if (!fileio::FileIo().IsRegularFile(pro_filename)) continue;
    const boost::shared_ptr<const QtCreatorProFile> pro_file(
      new QtCreatorProFile(pro_filename));
    assert(pro_file);
    assert(fileio::FileIo().IsRegularFile(pro_filename));
    const boost::shared_ptr<const QtCreatorProFileZipScript> script(
      new QtCreatorProFileZipScript(pro_file));
    assert(script);
    std::stringstream s;
    s << (*script);
    assert(!s.str().empty());
  }
}
