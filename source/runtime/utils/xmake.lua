target("utils")
    set_kind("static")
    set_languages("cxx20")
    add_includedirs("public", {public = true})
    add_includedirs("private", {public = false})
    add_files(
        "private/**.cpp")
    add_deps("mimalloc-xmake")
    add_deps("spdlog-xmake")


