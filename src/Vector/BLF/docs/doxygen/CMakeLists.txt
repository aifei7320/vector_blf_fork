find_package(Doxygen)
find_package(Graphviz)
find_package(HTMLHelp)

if(DOXYGEN_FOUND)
  if(WIN32)
    set(DOXYGEN_GENERATE_HTMLHELP YES)
    set(DOXYGEN_GENERATE_TREEVIEW NO)
    set(DOXYGEN_GENERATE_MAN NO)
  else()
    set(DOXYGEN_GENERATE_HTMLHELP NO)
    set(DOXYGEN_GENERATE_TREEVIEW YES)
    set(DOXYGEN_GENERATE_MAN YES)
  endif()

  configure_file(Doxyfile.in
    Doxyfile @ONLY IMMEDIATE)

  add_custom_target(doxygen ALL
    COMMAND ${DOXYGEN_EXECUTABLE} Doxyfile > doxygen-out.txt 2> doxygen-err.txt
    SOURCES Doxyfile)

  install(
    DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/html/
    DESTINATION share/doc/Vector_BLF/doxygen)

  install(
    FILES ${CMAKE_CURRENT_BINARY_DIR}/doxygen-out.txt ${CMAKE_CURRENT_BINARY_DIR}/doxygen-err.txt
    DESTINATION share/doc/Vector_BLF/doxygen)

  if(NOT WIN32)
    install(
      DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/man/
      DESTINATION share/man)
  endif()

endif()
