import qbs

Project {
    minimumQbsVersion: "1.7.1"

    CppApplication {
        consoleApplication: true

        cpp.cxxLanguageVersion: "c++17"

        property path lib_dir: "../lib"

        files: [
            "game.cpp",
            "game.h",
            "pictures.h",
            "pictures/*.png",
            lib_dir +"/Graph_lib/Graph.cpp",
            lib_dir +"/Graph_lib/GUI.cpp",
            lib_dir +"/Graph_lib/Window.cpp",
            lib_dir +"/Graph_lib/Regular_hexagon.cpp",
            "board.cpp",
            "board.h",
            "cell.cpp",
            "cell.h",
            "main.cpp",
            "utils.h",
        ]

        cpp.includePaths: lib_dir
        Properties {
            condition: qbs.targetOS.contains("windows")
            cpp.defines: "WIN32"
            cpp.systemIncludePaths: lib_dir +"/fltk-1.3.8_win64/include"
            cpp.libraryPaths: lib_dir +"/fltk-1.3.8_win64/lib"
            cpp.cxxFlags: "-fsanitize=leak"
            cpp.driverLinkerFlags: "-mwindows"
            cpp.staticLibraries: [
                "fltk_images",
                "fltk",
                "fltk_png",
                "fltk_z",
                "fltk_jpeg",
                "ole32",
                "uuid",
                "comctl32",
            ]
        }
        Properties {
            condition: qbs.targetOS.contains("linux")
//            cpp.systemIncludePaths: "/opt/fltk-1.3.8/include"
//            cpp.libraryPaths: "/opt/fltk-1.3.8/lib"
            cpp.staticLibraries: [
                "fltk_images",
                "png",
                "z",
                "jpeg",
                "fltk",
                "Xrender",
                "Xcursor",
                "Xfixes",
                "Xext",
                "Xft",
                "fontconfig",
                "Xinerama",
                "dl",
                "m",
                "X11",
            ]
        }

        Group {     // Properties for the produced executable
            fileTagsFilter: "application"
            qbs.install: true
        }
    }
}
