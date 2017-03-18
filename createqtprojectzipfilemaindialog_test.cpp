#include "createqtprojectzipfilemaindialog.h"

#include <cassert>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wunused-but-set-parameter"
#include <boost/algorithm/string/find.hpp>
#include "qtcreatorprofilezipscript.h"
#pragma GCC diagnostic pop

void ribiCreateQtProjectZipFileMainDialogTest() noexcept
{
  CreateQtProjectZipFileMainDialog d(
    "../../Tools/ToolCreateQtProjectZipFile"
  );
  const std::string s = d.GetScript();
  {
    const std::string t = "mkdir Projects";
    assert(!boost::algorithm::find_first(s,t).empty() && "Valid string should be present");
  }
  {
    const std::string t = "mkdir "
    #ifdef _WIN32
      "Projects\\Tools\\ToolCreateQtProjectZipFile\\..\\.."
    #else
      "Projects/Tools/ToolCreateQtProjectZipFile/../.."
    #endif
    ;
    assert( boost::algorithm::find_first(s,t).empty() && "False string should be absent");
  }
  #ifdef TODO_FIX_ISSUE_177
  assert(1==2 && "Yay, fixed issue 177");
  #endif //~#ifdef TODO_FIX_ISSUE_177
}
