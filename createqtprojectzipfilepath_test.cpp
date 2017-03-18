#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#include "createqtprojectzipfilepath.h"
#include <boost/algorithm/string/split.hpp>

#include <QDir>
#include <QFile>

#include "fileio.h"
#pragma GCC diagnostic pop

void ribiCreateQtProjectZipFilePathTest() noexcept
{
  {
    const Path p("home/richel/x/y/z.txt");
    assert(p.GetMainFolder() == "x");
    assert(p.GetSubFolder() == "y");
    assert(p.GetFilename() == "z.txt");
    assert(p.ToStr() == "x/y/z.txt");
  }
  {
    const Path p("x","y","z.txt");
    assert(p.GetMainFolder() == "x");
    assert(p.GetSubFolder() == "y");
    assert(p.GetFilename() == "z.txt");
    assert(p.ToStr() == "x/y/z.txt");
  }
}

