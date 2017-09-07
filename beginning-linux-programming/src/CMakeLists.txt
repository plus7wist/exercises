aux_source_directory(. SRC_LIST)

foreach(source ${SRC_LIST})
  get_filename_component(basename ${source} NAME_WE)
  add_executable(${basename} ${source})
endforeach(source)
