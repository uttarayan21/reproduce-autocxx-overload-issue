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
  // This works
  // Foo *createFoo(const Bar &bar,
  //                const std::pair<std::map<int, std::shared_ptr<FooBar>>,
  //                                std::shared_ptr<FooBar>> &baz);
  Foo *createFoo(const Bar &bar, Baz &baz);
};
} // namespace DEMO
