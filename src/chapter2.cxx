module;
#include <iostream>
#include <variant>
export module Chapter2;
export {
  class Object {
   public:
    int objId = 0;
    Object(int newId);
    Object(Object& newObj);
  };

  class VarObject {
   public:
    VarObject(int newVarVal);
    VarObject(Object newVarVal);
    int num;
    std::variant<Object, int> var;
  };

  std::basic_ostream<char>& operator<<(
      std::basic_ostream<char, std::char_traits<char>>& __out,
      const Object& __s);

  std::basic_ostream<char>& operator<<(
      std::basic_ostream<char, std::char_traits<char>>& __out,
      const Object& __s) {
    std::string value{std::to_string(__s.objId)};
    __out.write(value.c_str(), value.size());
    return __out;
  }
}
