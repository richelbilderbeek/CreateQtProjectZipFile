#include "createqtprojectzipfilemaindialog.h"

#include <cassert>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wunused-but-set-parameter"
#include <boost/algorithm/string/find.hpp>

#include "qtcreatorprofilezipscript.h"
#pragma GCC diagnostic pop

ribi::CreateQtProjectZipFileMainDialog::CreateQtProjectZipFileMainDialog(
  const std::string& source_folder)
  : m_script(QtCreatorProFileZipScript::CreateScript(source_folder))
{

}
