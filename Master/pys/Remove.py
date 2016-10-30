import os
import sys
filename = sys.argv[1];
os.remove("src/" + filename + ".hpp");
os.remove("src/" + filename + ".cpp");
