#ifndef ADALL_INCLUDE_ADALL_ACTION_HPP_
#define ADALL_INCLUDE_ADALL_ACTION_HPP_

#include <string>

class Action {
  std::string m_name{"NONE"};
  std::string m_type{"NONE"};

 public:
  Action();

  Action(const std::string &name, const std::string &type);

  [[nodiscard]] const std::string &name() const;

  [[nodiscard]] const std::string &type() const;

};

#endif //ADALL_INCLUDE_ADALL_ACTION_HPP_