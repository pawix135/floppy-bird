#define NOB_IMPLEMENTATION
#include "nob.h"

#define BUILD_FOLDER "build/"
#define SRC_FOLDER "src/"
#define INCLUDE_FOLDER "include/"
#define LIB_FOLDER "lib/"

#define DEBUG 1

int main(int argc, char **argv) {

  NOB_GO_REBUILD_URSELF(argc, argv);

  if (!nob_mkdir_if_not_exists(BUILD_FOLDER)) return 1;

  Nob_Cmd cmd = {0};

  nob_cc(&cmd);
// C:\third-party\raylib\src

  nob_cc_flags(&cmd);
  nob_cc_output(&cmd, BUILD_FOLDER "floppy-bird.exe");

  nob_cc_inputs(&cmd, SRC_FOLDER "main.c");
  nob_cc_inputs(&cmd, SRC_FOLDER "bird.c");
  nob_cc_inputs(&cmd, SRC_FOLDER "game.c");
  nob_cc_inputs(&cmd, SRC_FOLDER "utils.c");
  nob_cc_inputs(&cmd, SRC_FOLDER "assets.c");

  nob_cmd_append(&cmd, "-I"INCLUDE_FOLDER);
  nob_cmd_append(&cmd, "-L"LIB_FOLDER);
  nob_cmd_append(&cmd, "-g");
  nob_cmd_append(&cmd, "-O3");
  nob_cmd_append(&cmd, "-lraylib");
  nob_cmd_append(&cmd, "-lopengl32");
  nob_cmd_append(&cmd, "-lgdi32");
  nob_cmd_append(&cmd, "-lwinmm");
  nob_cmd_append(&cmd, "-lm");
  if(DEBUG == 1) nob_cmd_append(&cmd, "-DDEBUG");

  if (!nob_cmd_run(&cmd)) return 1;

  return 0;
}
