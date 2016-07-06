#!/usr/env python
#-*- coding: utf8 -*-
import os
import sys
def main():
    filename = sys.argv[1];
    with open("src/" + filename + ".h", "w") as outfile:
        outfile.write("#ifndef " + filename.upper() + "_H_" + "\n");
        outfile.write("#define " + filename.upper() + "_H_" + "\n\n\n");
        outfile.write("class " + filename + " {" + "\npublic:\n\nprivate:\n\n};\n\n");
        outfile.write("#endif\n\n\n");
    with open("src/" + filename + ".cpp", "w") as outfile:
        outfile.write("#include \"" + filename + ".h\"" + "\n");
    with open("doc/" + filename + ".md", "w") as outfile:
        outfile.write("# " + filename + "\n");
if __name__ == '__main__':
    main()
