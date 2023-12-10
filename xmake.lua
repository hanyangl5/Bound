set_project("BoundEngine")

bound_project_dir = "./"
bound_source_dir = bound_project_dir .. "source/"
bound_third_party_dir = bound_source_dir .. "third_party/"
includes("source/xmake.lua")


-- option("build_type")
-- set_values(develop, release)
-- set_default(true)
-- set_showmenu(true)
-- option_end()