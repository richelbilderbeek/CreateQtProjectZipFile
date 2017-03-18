#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wunused-but-set-parameter"
#include "createqtprojectzipfilemenudialog.h"

#include <iostream>

#include "createqtprojectzipfilemaindialog.h"
#include "fileio.h"
#include "qrcfile.h"
#include "qtcreatorprofile.h"
#include "qtcreatorprofilezipscript.h"
#pragma GCC diagnostic pop

ribi::CreateQtProjectZipFile::MenuDialog::MenuDialog()
{

}

int ribi::CreateQtProjectZipFile::MenuDialog::ExecuteSpecific(const std::vector<std::string>& argv) noexcept
{
  const int argc = static_cast<int>(argv.size());
  assert(argc > 0);
  if (argc == 1)
  {
    std::cout << this->GetHelp() << '\n';
    return 1;
  }

  std::string folder;
  for (int i=0; i!=argc-1; ++i)
  {
    if (argv[i] == "-f" || argv[i] == "--folder")
    {
      folder = argv[i+1];
      break;
    }
  }
  bool silent = false;
  for (int i=0; i!=argc; ++i)
  {
    if (argv[i] == "-s" || argv[i] == "--silent")
    {
      silent = true;
      break;
    }
  }

  if (!fileio::FileIo().IsFolder(folder))
  {
    if (!silent)
    {
      std::cout
        << "Invalid folder '" << folder << "'\n"
        << "Please supply a valid folder name\n";
    }
    return 1;
  }
  #ifdef _WIN32
  if (folder.substr(0,6) != "..\\..\\" && folder.substr(0,6) != "../../")
  {
    if (!silent)
    {
      std::cout
        << "Folder must start with '..\\..\\' or '..//..//'\n"
        << "Please supply a folder name starting with '\\..\\..' or '//..//..'\n";
    }
    return 1;
  }
  #else
  if (folder.substr(0,6) != "../../")
  {
    if (!silent)
    {
      std::cout
        << "Folder must start with '../../'\n"
        << "Please supply a folder name starting with '/../..'\n";
    }
    return 1;
  }
  #endif

  //Call the script with UNIX line endings, as
  //all Qt Creator file works with these as well
  std::string folder_unix;
  std::replace_copy(folder.begin(),folder.end(),std::back_inserter(folder_unix),'\\','/');

  const std::string script = CreateQtProjectZipFileMainDialog(folder_unix).GetScript();
  assert(!script.empty());
  if (!silent) { std::cout << script << '\n'; }
  return 0;
}

ribi::About ribi::CreateQtProjectZipFile::MenuDialog::GetAbout() const noexcept
{
  About a(
    "Richel Bilderbeek",
    "CreateQtProjectZipFile",
    "tool to create a zip file from a Qt project",
    "the 25th of April 2014",
    "2012-2015",
    "http://www.richelbilderbeek.nl/ToolCreateQtProjectZipFile.htm",
    GetVersion(),
    GetVersionHistory());
  a.AddLibrary("FileIo version: " + fileio::FileIo().GetVersion());
  a.AddLibrary("QrcFile version: " + QrcFile::GetVersion());
  a.AddLibrary("QtCreatorProFile version: " + QtCreatorProFile::GetVersion());
  a.AddLibrary("QtCreatorProFileZipScript version: " + QtCreatorProFileZipScript::GetVersion());
  return a;
}

ribi::Help ribi::CreateQtProjectZipFile::MenuDialog::GetHelp() const noexcept
{
  return Help(
    this->GetAbout().GetFileTitle(),
    this->GetAbout().GetFileDescription(),
    {
      //Options
      Help::Option('f',"folder","the source folder to have a zip script generated of")
    },
    {
      //Example uses
      "CreateQtProjectZipFile -f MyFolder",
      "CreateQtProjectZipFile --folder MyFolder",
    }
  );
}

std::string ribi::CreateQtProjectZipFile::MenuDialog::GetVersion() const noexcept
{
  return "3.0";
}

std::vector<std::string> ribi::CreateQtProjectZipFile::MenuDialog::GetVersionHistory() const noexcept
{
  return {
    "2012-02-25: version 1.0: initial version",
    "2012-05-29: version 1.1: small fix due to new boost::filesystem",
    "2012-05-30: version 1.2: added Test method",
    "2012-06-10: version 1.3: added Path class for cleaner code",
    "2013-05-19: version 2.0: support for any depth of folder tree",
    "2014-01-27: version 2.1: also copies the included .pri files' content",
    "2014-04-12: version 2.2: added 'silent' flag",
    "2014-04-25: version 2.3: fixed SimplifyPath bug",
    "2014-05-02: version 3.0: internally use UNIX path seperators only, fixed bug"
  };
}
