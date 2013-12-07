#include <memory>
#include <iostream>
using namespace std;
class Singleton{
  public:
  static Singleton* getInstance();
  
  private:
  static Singleton* _Instance;
  Singleton(){}
  ~Singleton(){}
  Singleton(const Singleton &instance){}
  Singleton & operator=(const Singleton &rst){}
};

  Singleton* Singleton::_Instance=NULL;
  Singleton* Singleton:: getInstance(){
    if(_Instance==NULL)
      _Instance=new Singleton();
    return _Instance;
  }
  
  
