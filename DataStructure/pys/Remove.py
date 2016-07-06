import os
import sys
filename = sys.argv[1];
os.remove("src/" + filename + ".h");
os.remove("src/" + filename + ".cpp");
