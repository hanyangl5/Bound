-- target("platform")
--     set_kind("static")
--     set_languages("c99", "cxx20")
--     add_includedirs("public", {public = true})
--     add_includedirs("private", {public = false})
--     add_includedirs(bound_source_dir .. "runtime/config/public", {public = false})
--     print(bound_source_dir .. "runtime/config/public")
--     add_files("private/**.c", "private/**.cpp")

target("platform")
    set_kind("static")
    set_languages("cxx20")
    add_includedirs("public", {public = true})
    add_includedirs("private", {public = false})
    add_files(
        "private/**.cpp")
    add_deps("utils")

