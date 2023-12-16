-- test is not working now
-- add_requires("doctest")


-- target("test")
--     set_kind("binary")
--     set_languages("cxx20")
--     add_defines("DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN")
--     add_files("runtime/*.cpp")
--     add_packages("doctest")
--     add_deps("utils", "platform")

target("test")
    set_kind("binary")
    set_languages("cxx20")
    add_files("simpletest.cpp")
    add_deps("utils", "platform")