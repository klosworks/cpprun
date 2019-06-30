#include <iostream>
#include <string>
#include <experimental/filesystem>
#include <cstdlib>
#include "utils.h"


using namespace std;
namespace fs = std::experimental::filesystem;

struct CmdOptions
{
    bool build_locally = false;
    string target; //the file to build and run
};

CmdOptions parse_cmd(int argc, char** argv)
{
    CmdOptions result;
    release_assert(argc >= 2);
    result.build_locally = false;
    if(argc > 2)
    {
        release_assert(string(argv[1]) == "-l");
        result.target = argv[2];
    }
    result.target = argv[1];

    if(!fs::exists(fs::path(result.target)))
    {
        cerr << "File " << result.target << " doesn't exist." << endl;
        exit(1);
    }
    return result;
}

fs::path create_build_dir(bool build_locally, fs::path target)
{
    fs::path build_dir;
    if(!build_locally)
    {
        //build where cpprun is installed
        string s = get_current_process_location();
        //the builds should go to /var/cache. The thing is that there may be multiple copies of cpprun on the system.
        //Hence, make a subfolder in /var/cache/cpprun whose name encodes the cpprun instance used.
        auto base_p = fs::path("/var/cache/cpprun");
        create_directory(base_p); 
        auto instance_build_folder= encode_path(s);
        fs::path full_p = base_p / instance_build_folder;
        create_directory(full_p);
        auto abs_target = fs::absolute(target);
        build_dir = full_p / abs_target;
    }
    else
    {
        fs::path t(target);
        auto parent = t.parent_path();
        build_dir = parent / "build";
    }
    create_directory(build_dir);
    release_assert(fs::exists(build_dir));
    return build_dir;
}

int main(int argc, char** argv)
{
    CmdOptions options = parse_cmd(argc, argv);
    fs::path build_dir = create_build_dir(options.build_locally, options.target);
    system(("cmake " + build_dir.u8string()).c_str());    
}

