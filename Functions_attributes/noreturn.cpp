#include <iostream>

/*Adding a [[noreturn]] attribute to a function means that it never returns
 * control to the call site.
 */
/*his code snippet compiles fine without any warnings or errors. However, if you
 remove the [[noreturn]] attribute, the compiler generates the following
 warning*/
/*warning C4715: 'isFeatureLicensed': not all control paths return a value.*/
[[noreturn]] void forceProgramTermination() {
  std::exit(1);  // Defined in <cstdlib>
}
bool isDongleAvailable() {
  bool isAvailable{false};
  // Check whether a licensing dongle is available...
  return isAvailable;
}
bool isFeatureLicensed(int featureId) {
  if (!isDongleAvailable()) {
    // No licensing dongle found, abort program execution!
    forceProgramTermination();
  } else {
    bool isLicensed{featureId == 42};
    // Dongle available, perform license check of the given feature...
    return isLicensed;
  }
}
int main() { bool isLicensed{isFeatureLicensed(42)}; }