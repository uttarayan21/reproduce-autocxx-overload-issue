#pragma once
#include <functional>
#include <map>
#include <memory>
#include <string>
namespace DEMO {
class FooBar;
typedef std::pair<std::map<int, std::shared_ptr<FooBar>>,
                  std::shared_ptr<FooBar>>
    Baz;
// typedef std::pair<int, FooBar> Baz;
struct Bar;
class Foo;
class Demo {
public:
  Foo *createFoo(const Bar &bar);
  Foo *createFoo(const Bar &bar, const Baz &baz);
};
} // namespace DEMO
