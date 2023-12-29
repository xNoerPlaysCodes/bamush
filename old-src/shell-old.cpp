#include "command_handler.cpp"
#include "config_loader.cpp"
// somehow I already included iostream somewhere????
#include <sstream>
#include <vector>
#include <string>
#include <filesystem>
#include <readline/history.h>
#include <readline/readline.h>
using str = std::string;
namespace fs = std::filesystem;

void loadHistory() {
    str homedir = getHomeDirectory();
    if (!fs::exists((homedir + "/.bamush_history"))) {
        std::system(("touch " + homedir + "/.bamush_history").c_str());
    } if (!fs::exists((homedir + "/.bamushrc"))) {
        std::system(("touch " + homedir + "/.bamushrc").c_str());
    } if (!fs::exists((homedir + "/.bamush_prompt"))) {
        std::system(("touch " + homedir + "/.bamush_prompt").c_str());
    }
}

int main(int argc, char **argv) {
    str homedir = getHomeDirectory();
    loadHistory();
    read_history((homedir + "/.bamush_history").c_str());
    str argvstr[argc];
    for (int i = 0; i < argc; i++) {
        argvstr[i] = argv[i];
    }
    // std::system((loadConfig()).c_str()); // Config Exec (bash) // Postponed
    std::vector<str> PROMPT_ARR = loadPrompt();
    str PROMPT = PROMPT_ARR[0];
    PROMPT = (PROMPT.substr(0, PROMPT.length() - 1));
    bool shell_ir = true;
    while (shell_ir) {
        char *c_ui = readline(PROMPT.c_str());
        str ui(c_ui);

        if (!c_ui) {
            continue;
        }

        if (ui.empty()) {
            free(c_ui);
            continue;
        }

        // Add the command to history
        add_history(c_ui);

        if (ui == "exit") {
            shell_ir = false;
        } else {
            std::istringstream iss(ui);
            std::vector<str> args;
            str arg;

            while (iss >> arg) {
                args.push_back(arg);
            }

            handle(args.size(), args); // Handle the command with command_handler.cpp
        }

        free(c_ui);
    }

    write_history((homedir + "/.bamush_history").c_str());
    return 0;
}