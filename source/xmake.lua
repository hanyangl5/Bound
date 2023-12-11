-- msvc only support address sanitizer
set_policy("build.sanitizer.address", true)

-- set_policy("build.sanitizer.memory", true)
-- set_policy("build.sanitizer.leak", true)
-- set_policy("build.sanitizer.undefined", true)
includes("third_party/")
includes("runtime/")
includes("tests/")