#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wunused-but-set-parameter"
#include "createqtprojectzipfilemenudialog.h"
#pragma GCC diagnostic pop

int main(int argc, char* argv[])
{
  ribi::CreateQtProjectZipFile::MenuDialog d;
  const std::vector<std::string> args { ribi::MenuDialog::ConvertArguments(argc,argv) };
  return d.Execute(args);
}
