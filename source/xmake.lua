-- address sanitizer
set_policy("build.sanitizer.address", true)

-- set_policy("build.sanitizer.memory", true)
-- set_policy("build.sanitizer.leak", true)
-- set_policy("build.sanitizer.undefined", true)

-- disable exception, https://github.com/xmake-io/xmake/issues/2988
set_exceptions("no-cxx")

-- disble rtti
if is_config("toolchain", "msvc")then
    add_cxxflags("/GR-")
-- elseif is_config("toolchain", "gcc", "mingw") then
--     add_cxxflags("-fno-rtti")
elseif is_config("toolchain", "llvm") or is_config("toolchain","clang") then
    add_cxxflags("-fno-rtti")
else
    
end

add_rules("mode.release", "mode.debug")

includes("third_party/")
includes("runtime/")
includes("tests/")