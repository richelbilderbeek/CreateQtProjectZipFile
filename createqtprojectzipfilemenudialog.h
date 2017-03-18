#ifndef CREATEQTPROJECTZIPFILEMENUDIALOG_H
#define CREATEQTPROJECTZIPFILEMENUDIALOG_H


#include <string>
#include <vector>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#include "about.h"
#include "menudialog.h"
#pragma GCC diagnostic pop

namespace ribi {
namespace CreateQtProjectZipFile {

struct MenuDialog final : public ::ribi::MenuDialog
{
  MenuDialog();
  ~MenuDialog() noexcept {}

  About GetAbout() const noexcept override;
  Help GetHelp() const noexcept override;
  std::string GetVersion() const noexcept override;
  std::vector<std::string> GetVersionHistory() const noexcept override;

  private:
  int ExecuteSpecific(const std::vector<std::string>& argv) noexcept override;
};

} //~namespace CreateQtProjectZipFile
} //~namespace ribi

#endif // CREATEQTPROJECTZIPFILEMENUDIALOG_H
