#include "createqtprojectzipfilemenudialog.h"

#include <iostream>
#include "createqtprojectzipfilemaindialog.h"
#include "fileio.h"
#include "qrcfile.h"
#include "qtcreatorprofile.h"
#include "qtcreatorprofilezipscript.h"
#include "richelbilderbeekprogram.h"


void CreateQtProjectZipFileMenuDialogTest() noexcept
{
  {
    {
      const std::string mypath{fileio::FileIo().GetTempFileName()};
      { std::ofstream f(mypath); f << "SOURCES += qtmain.cpp"; }
      boost::shared_ptr<QtCreatorProFile> p{new QtCreatorProFile(mypath)};
    }
    const std::string script = CreateQtProjectZipFileMainDialog("../../Tools/ToolCreateQtProjectZipFile").GetScript();
  }
  MenuDialog d;
  #ifdef _WIN32
  d.Execute( { "CreateQtProjectZipFile", "-f", "..\\..\\Tools\\ToolCreateQtProjectZipFile", "-s" } );
  #else
  d.Execute( { "CreateQtProjectZipFile", "-f", "../../Tools/ToolCreateQtProjectZipFile", "-s" } );
  #endif
}
