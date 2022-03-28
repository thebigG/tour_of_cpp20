module;
#include <iostream>
#include <variant>
//#include <string>
export module Chapter2;
export {
  class Object {
   public:
    int objId = 0;
    Object(int newId);
    Object(Object& newObj);
    ~Object() {}
  };

  class VarObject {
   public:
    //    VarObject(int newVarVal);
    //    VarObject(Object newVarVal);
    int num;
    std::variant<int, float> x = 12;
  };

  //  std::basic_ostream<char>& operator<<(
  //      std::basic_ostream<char, std::char_traits<char>>& __out,
  //      const Object& __s);

  //  std::basic_ostream<char>& operator<<(
  //      std::basic_ostream<char, std::char_traits<char>>& __out,
  //      const Object& __s) {
  ////    std::string value{std::to_string(__s.objId)};
  ////    __out.write(value.c_str(), value.size()+1);
  //      __out << __s.objId;
  //    return __out;
}
