add_rules("mode.debug", "mode.release")
add_rules( "plugin.compile_commands.autoupdate", { outputdir = ".vscode" } )

target("aoc2025")
	add_files("src/*.c")
	set_rundir(os.projectdir())